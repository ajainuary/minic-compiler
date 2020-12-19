#include <bits/stdc++.h>

#include "minicAST.h"
using namespace std;

#include <llvm/ADT/APFloat.h>
#include <llvm/ADT/STLExtras.h>
#include <llvm/ADT/SmallVector.h>
#include <llvm/AsmParser/Parser.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/IR/InlineAsm.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/LegacyPassManagers.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Pass.h>
#include <llvm/Support/FormattedStream.h>
#include <llvm/Support/MathExtras.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/raw_ostream.h>

using namespace llvm;

LLVMContext context;

class DataBlock {
 public:
  BasicBlock *block;
  map<string, Value *> locals;
  DataBlock(BasicBlock *block) { this->block = block; }
};

ASTFunctionDeclarationNode *standard_function(string name) {
  ASTFunctionDeclarationNode *node = new ASTFunctionDeclarationNode();
  ASTTypeNode *void_type = new ASTTypeNode();
  void_type->primitive = "void";
  node->id = name;
  node->isStandard = true;
  node->returntype = void_type;
  return (ASTFunctionDeclarationNode *)node;
}
class CodegenVisitor : ASTvisitor {
 private:
  Module *module;
  IRBuilder<> *builder;
  ASTProgNode *start;
  Function *mainFunc;
  vector<DataBlock> table;
  void *returned;

  void error(string msg) {
    cerr << msg << "\n";
    exit(0);
  }
  map<string, Value *> getLocals() { return table.back().locals; }
  void setLocals(map<string, Value *> variables) {
    table.back().locals.insert(variables.begin(), variables.end());
  }
  bool isLocal(string name) { return getLocals().count(name); }
  void declareLocals(string name, Value *value) {
    if (!isLocal(name)) {
      pair<string, Value *> inp = make_pair(name, value);
      table.back().locals.insert(inp);
    } else {
      error("Redeclaration of " + name);
    }
  }
  bool isGlobal(string name) {
    for (auto it : table) {
      if (it.locals.count(name)) {
        return true;
      }
    }
    return false;
  }
  Value *getBlock(string name) {
    vector<DataBlock>::iterator it;
    for (it = table.begin(); it != table.end(); it++) {
      if (it->locals.count(name)) {
        Value *ret = it->locals.find(name)->second;
        return ret;
      }
    }
    return NULL;
  }

  void pushBlock(BasicBlock *block) { table.push_back(DataBlock(block)); }
  void popBlock() { table.pop_back(); };

  BasicBlock *topBlock() {
    if (table.size() == 0) {
      cerr << "Empty table" << endl;
    }
    return table.back().block;
  }
  void generateIR() {
    legacy::PassManager PM;
    verifyModule(*this->module);
    PM.add(createPrintModulePass(outs()));
    PM.run(*this->module);
  }

  void handleBlock(BasicBlock *block) {
    block = topBlock();
    popBlock();
  }
  template <class T>
  void traverse(vector<T> *a) {
    for (auto x : *a) {
      x->accept(this);
    }
  }

 public:
  void codeGen() {
    cerr << "Starting Code Generation Visitor" << endl;
    this->visit(*start);
    cerr << "Completed Code Generation Visitor" << endl;
    generateIR();
    cerr << "Completed Building IR Code" << endl;
  }
  CodegenVisitor(ASTProgNode *node) {
    this->builder = new IRBuilder<>(context);
    this->module = new Module("main", context);
    this->start = node;
    this->module->setTargetTriple("x86_64-pc-linux-gnu");
    function_scope.insert({"scanf", standard_function("scanf")});
    function_scope.insert({"printf", standard_function("printf")});
    unordered_map<string, ASTTypeNode *> global;
    variable_scope.push_back(global);
    FunctionType *ftype = FunctionType::get(Type::getInt64Ty(context), false);
    this->mainFunc =
        Function::Create(ftype, GlobalValue::ExternalLinkage, "main", module);
  }
  list<unordered_map<string, ASTTypeNode *>> variable_scope;
  unordered_map<string, ASTFunctionDeclarationNode *> function_scope;
  bool functionMatch(ASTFunctionCallNode &node) {
    bool flag = false;
    ASTFunctionDeclarationNode *match = nullptr;
    if (function_scope.find(node.id) != function_scope.end()) {
      flag = true;
      match = function_scope.find(node.id)->second;
    }
    if (!flag) {
      cerr << "---------ERROR: " << node.id << " NOT FOUND" << endl;
      return false;
    }
    if (match->isStandard) {
      return true;
    }
    if (match->params && node.argList) {
      bool f2 = true;
      if (match->params->declarations.size() == node.argList->args.size()) {
        int n = match->params->declarations.size();
        for (int i = 0; i < n; i++) {
          if (node.argList->args[i]->type != "undefined" &&
              match->params->declarations[i]->type->primitive !=
                  node.argList->args[i]->type) {
            f2 = false;
          }
        }
      } else {
        f2 = false;
      }
      if (f2) {
        return true;
      }
    }
    cerr << "---------ERROR: " << node.id << " INCORRECT SIGNATURE" << endl;
    return false;
  }
  virtual void visit(ASTProgNode &node) {
    function_scope.insert({"scanf", standard_function("scanf")});
    function_scope.insert({"printf", standard_function("printf")});
    unordered_map<string, ASTTypeNode *> global;
    variable_scope.push_back(global);
    for (auto &x : node.programs) {
      x->accept(*this);
    }
  }
  virtual void visit(ASTFunctionDeclarationNode &node) {
    cerr << "start " << node.id << endl;
    if (function_scope.find(node.id) != function_scope.end()) {
      cerr << "---------------ERROR: Function " << node.id << " already defined"
           << endl;
    }
    auto current_scope = variable_scope.rbegin();
    if (current_scope->find(node.id) != current_scope->end()) {
      cerr << "---------------ERROR: Variable " << node.id
           << " already defined with the same name" << endl;
    }
    this->function_scope.insert({node.id, &node});
    Function *func;
    if (node.id == "main") {
      func = this->mainFunc;
    } else {
      vector<Type *> argT;
      int n = node.params->declarations.size();
      for (int i = 0; i < n; i++) {
        argT.push_back(Type::getInt64Ty(context));
      }
      FunctionType *ft = FunctionType::get(Type::getInt64Ty(context),
                                           makeArrayRef(argT), false);
      func =
          Function::Create(ft, GlobalValue::InternalLinkage, node.id, module);
    }
    BasicBlock *block = BasicBlock::Create(context, "body", func, 0);
    pushBlock(block);

    // builder->SetInsertPoint(topBlock());
    Function::arg_iterator it2 = func->arg_begin();
    if (node.params) {
      for (int i = 0; i < node.params->declarations.size(); i++) {
        Value *arg = &(*it2);
        string name = node.params->declarations[i]->identifiers[0].first->id;
        cerr << "PARAMETER " << name << endl;
        if (current_scope->find(name) != current_scope->end()) {
          cerr << "---------------ERROR: Variable " << name
               << " already defined" << endl;
        }
        if (function_scope.find(name) != function_scope.end()) {
          cerr << "---------------ERROR: Function " << name
               << " already defined with the same name" << endl;
        }
        current_scope->insert({name, node.params->declarations[i]->type});
        arg->setName(name);
        if (!arg->getType()->isArrayTy()) {
          AllocaInst *allocaInst =
              new AllocaInst(Type::getInt64Ty(context), 0, name, topBlock());
          auto tmp = new StoreInst(arg, allocaInst, false, topBlock());
          declareLocals(name, allocaInst);
        } else {
          cerr << "Array parameter"
               << " " << name << endl;
          declareLocals(name, arg);
        }
        it2++;
      }
    }
    unordered_map<string, ASTTypeNode *> func_scope;
    variable_scope.push_back(func_scope);
    cerr << "block start " << node.id << endl;
    node.block->accept(*this);
    cerr << "block end " << node.id << endl;
    if (topBlock()->getTerminator() == NULL) {
      if (node.returntype->primitive != "void") {
        ReturnInst::Create(context,
                           ConstantInt::get(Type::getInt64Ty(context), 0, true),
                           topBlock());
      } else {
        ReturnInst::Create(context, topBlock());
      }
    }
    if (node.id != "main") {
      popBlock();
      cerr << "end " << node.id << endl;
    }
    this->returned = func;
    variable_scope.pop_back();
  }
  virtual void visit(ASTBlockNode &node) {
    unordered_map<string, ASTTypeNode *> block_scope;
    variable_scope.push_back(block_scope);
    cerr << "block of size " << node.programs.size() << endl;
    for (auto &x : node.programs) {
      if (x != NULL) x->accept(*this);
    }
    variable_scope.pop_back();
  }
  virtual void visit(ASTExprNode &node) {
    cerr << "visit Expr Node(" << endl;
    if (node.expressions.size() == 1) {
      node.expressions[0]->accept(*this);
      Value *val = static_cast<Value *>(this->returned);
      ConstantInt *zer = ConstantInt::get(Type::getInt64Ty(context), 0, true);
      if (node.operation == "-") {
        this->returned = BinaryOperator::Create(Instruction::Sub, zer, val,
                                                "tmp", topBlock());
      }
      if (node.operation == "!") {
        this->returned = CmpInst::Create(Instruction::ICmp, ICmpInst::ICMP_EQ,
                                         zer, val, "tmp", topBlock());
      }
      if (node.operation == "&") {
        cerr << "Dereference" << endl;
        this->returned =
            new IntToPtrInst(getBlock(dynamic_cast<ASTIdentifierNode *>(
                                          node.expressions[0]->expressions[0])
                                          ->id),
                             Type::getInt64Ty(context));
      }
    } else if (node.expressions.size() == 2) {
      node.expressions[0]->accept(*this);
      Value *left = static_cast<Value *>(this->returned);
      node.expressions[1]->accept(*this);
      Value *right = static_cast<Value *>(this->returned);
      cerr << node.operation << " operation" << endl;
      if (node.operation == "+") {
        this->returned = BinaryOperator::Create(Instruction::Add, left, right,
                                                "tmp", topBlock());
      }
      if (node.operation == "-") {
        this->returned = BinaryOperator::Create(Instruction::Sub, left, right,
                                                "tmp", topBlock());
      }
      if (node.operation == "*") {
        this->returned = BinaryOperator::Create(Instruction::Mul, left, right,
                                                "tmp", topBlock());
      }
      if (node.operation == "/") {
        this->returned = BinaryOperator::Create(Instruction::SDiv, left, right,
                                                "tmp", topBlock());
      }
      if (node.operation == "and") {
        this->returned = BinaryOperator::Create(Instruction::And, left, right,
                                                "tmp", topBlock());
      }
      if (node.operation == "or") {
        this->returned = BinaryOperator::Create(Instruction::Or, left, right,
                                                "tmp", topBlock());
      }
      if (node.operation == "mod") {
        this->returned = BinaryOperator::Create(Instruction::SRem, left, right,
                                                "tmp", topBlock());
      }
      if (node.operation == "==") {
        this->returned =
            new ZExtInst(CmpInst::Create(Instruction::ICmp, ICmpInst::ICMP_EQ,
                                         left, right, "tmp", topBlock()),
                         Type::getInt64Ty(context), "zext", topBlock());
      }
      if (node.operation == ">=") {
        this->returned =
            new ZExtInst(CmpInst::Create(Instruction::ICmp, ICmpInst::ICMP_SGE,
                                         left, right, "tmp", topBlock()),
                         Type::getInt64Ty(context), "zext", topBlock());
      }
      if (node.operation == ">") {
        this->returned =
            new ZExtInst(CmpInst::Create(Instruction::ICmp, ICmpInst::ICMP_SGT,
                                         left, right, "tmp", topBlock()),
                         Type::getInt64Ty(context), "zext", topBlock());
      }
      if (node.operation == "<=") {
        this->returned =
            new ZExtInst(CmpInst::Create(Instruction::ICmp, ICmpInst::ICMP_SLE,
                                         left, right, "tmp", topBlock()),
                         Type::getInt64Ty(context), "zext", topBlock());
      }
      if (node.operation == "<") {
        this->returned =
            new ZExtInst(CmpInst::Create(Instruction::ICmp, ICmpInst::ICMP_SLT,
                                         left, right, "tmp", topBlock()),
                         Type::getInt64Ty(context), "zext", topBlock());
      }
      if (node.operation == "!=") {
        this->returned =
            new ZExtInst(CmpInst::Create(Instruction::ICmp, ICmpInst::ICMP_NE,
                                         left, right, "tmp", topBlock()),
                         Type::getInt64Ty(context), "zext", topBlock());
      }
    }
    for (auto &x : node.expressions) {
      // x->accept(*this);
      if (x->type != "undefined") {
        if (node.type != "undefined" && x->type != node.type) {
          cerr << "-------------ERROR: Operand Type Mismatch" << endl;
        } else {
          node.type = x->type;
        }
      }
    }
  }
  virtual void visit(ASTAssignNode &node) {
    // if (node.r->type != "undefined" && node.r->type != node.l->type) {
    //   cerr << "-------------ERROR: Assignment Type Mismatch" << endl;
    // }
    cerr << "start assign" << endl;
    node.l->accept(*this);
    cerr << "end L" << endl;
    node.r->accept(*this);
    Value *expr = static_cast<Value *>(this->returned);
    Value *location = getBlock(node.l->id);
    if (node.l->d) {
      vector<Value *> idxList;
      node.l->d->accept(*this);
      idxList.push_back(ConstantInt::get(Type::getInt64Ty(context), 0, true));
      Value *index_val = static_cast<Value *>(this->returned);
      idxList.push_back(index_val);
      GetElementPtrInst *index = GetElementPtrInst::CreateInBounds(
          location, idxList, "tmp", topBlock());
      StoreInst *instruction = new StoreInst(expr, index, false, topBlock());
      this->returned = instruction;
    } else {
      this->returned = new StoreInst(expr, location, false, topBlock());
    }
    cerr << "end R" << endl;
  }
  virtual void visit(ASTDeclarationNode &node) {
    auto current_scope = variable_scope.rbegin();
    if (node.identifiers[0].first->d) {
      ArrayType *arrayType = ArrayType::get(
          Type::getInt64Ty(context),
          stoi(dynamic_cast<ASTConstantNode *>(node.identifiers[0].first->d)
                   ->value));
      AllocaInst *allocaInst = new AllocaInst(
          arrayType, 0, node.identifiers[0].first->id, topBlock());
      declareLocals(node.identifiers[0].first->id, allocaInst);
      this->returned = allocaInst;
    } else {
      AllocaInst *allocaInst =
          new AllocaInst(Type::getInt64Ty(context), 0,
                         node.identifiers[0].first->id, topBlock());
      declareLocals(node.identifiers[0].first->id, allocaInst);
      this->returned = allocaInst;
    }
    for (auto &x : node.identifiers) {
      if (current_scope->find(x.first->id) != current_scope->end()) {
        cerr << "---------------ERROR: Variable " << x.first->id
             << " already defined" << endl;
      }
      if (function_scope.find(x.first->id) != function_scope.end()) {
        cerr << "---------------ERROR: Function " << x.first->id
             << " already defined with the same name" << endl;
      }
      current_scope->insert({x.first->id, node.type});
      // if (x.second) x.second->accept(*this);
      // Value *val = static_cast<Value *>(this->returned);
      // auto tmp = new StoreInst(val, allocaInst, false, topBlock());
      // if (x.second && x.second->type != "undefined" &&
      //     x.second->type != node.type->primitive) {
      //   cerr << "-------------ERROR: Assignment Type Mismatch" << endl;
      // }
    }
  }
  virtual void visit(ASTIdentifierNode &node) {
    bool flag = false;
    cerr << "Visit identifier " << node.id << endl;
    ASTTypeNode *match_type = nullptr;
    for (auto it = variable_scope.rbegin(); it != variable_scope.rend(); it++) {
      if (it->find(node.id) != it->end()) {
        flag = true;
        match_type = it->find(node.id)->second;
        break;
      }
    }
    if (!flag) {
      cerr << "---------ERROR: " << node.id << " NOT FOUND" << endl;
      return;
    }
    node.type = match_type->primitive;
    auto name = node.id;
    Value *val = getBlock(name);
    cerr << node.d << endl;
    if (node.d) {
      cerr << "Access index of " << name << endl;
      vector<Value *> idxList;
      node.d->accept(*this);
      idxList.push_back(ConstantInt::get(Type::getInt64Ty(context), 0, true));
      Value *index_val = static_cast<Value *>(this->returned);
      idxList.push_back(index_val);
      GetElementPtrInst *index =
          GetElementPtrInst::CreateInBounds(val, idxList, "tmpXYZ", topBlock());
      LoadInst *instruction = new LoadInst(index, "tmp", topBlock());
      this->returned = instruction;
    } else {
      LoadInst *instruction = new LoadInst(val, "tmp", topBlock());
      this->returned = instruction;
    }
  }
  virtual void visit(ASTIfElseNode &node) {
    BasicBlock *entryBlock = topBlock();
    BasicBlock *ifBlock =
        BasicBlock::Create(context, "then", entryBlock->getParent(), 0);
    BasicBlock *elseBlock =
        BasicBlock::Create(context, "else", entryBlock->getParent(), 0);
    BasicBlock *after =
        BasicBlock::Create(context, "after", entryBlock->getParent(), 0);
    node.condition->accept(*this);
    Value *cond = static_cast<Value *>(this->returned);
    Constant *zero = ConstantInt::get(Type::getInt64Ty(context), 0, true);
    ICmpInst *comparison =
        new ICmpInst(*entryBlock, ICmpInst::ICMP_NE, cond, zero, "tmp");
    BranchInst::Create(ifBlock, elseBlock, comparison, entryBlock);
    pushBlock(ifBlock);
    node.onTrue->accept(*this);
    BranchInst::Create(after, ifBlock);
    popBlock();
    pushBlock(elseBlock);
    if (node.onFalse) {
      node.onFalse->accept(*this);
    }
    BranchInst::Create(after, elseBlock);
    popBlock();
    auto locals = getLocals();
    popBlock();
    pushBlock(after);
    setLocals(locals);
  }
  virtual void visit(ASTForStatementNode &node) {
    BasicBlock *entryBlock = topBlock();
    BasicBlock *bodyBlock =
        BasicBlock::Create(context, "loop_body", entryBlock->getParent(), 0);
    BasicBlock *after =
        BasicBlock::Create(context, "after_loop", entryBlock->getParent(), 0);
    BasicBlock *headerBlock =
        BasicBlock::Create(context, "loop_header", entryBlock->getParent(), 0);
    node.init->accept(*this);
    Value *init = static_cast<Value *>(this->returned);
    BranchInst::Create(headerBlock, entryBlock);
    pushBlock(headerBlock);
    node.condition->accept(*this);
    Value *cond = static_cast<Value *>(this->returned);
    Constant *zero = ConstantInt::get(Type::getInt64Ty(context), 0, true);
    ICmpInst *comparison =
        new ICmpInst(*topBlock(), ICmpInst::ICMP_NE, cond, zero, "tmp");
    BranchInst::Create(bodyBlock, after, comparison, headerBlock);
    popBlock();

    pushBlock(bodyBlock);
    node.block->accept(*this);
    node.iteration->accept(*this);
    Value *inc = static_cast<Value *>(this->returned);
    BranchInst::Create(headerBlock, topBlock());
    popBlock();
    auto locals = getLocals();
    popBlock();
    pushBlock(after);
    setLocals(locals);
  }
  virtual void visit(ASTWhileStatementNode &node) {
    BasicBlock *entryBlock = topBlock();
    BasicBlock *headerBlock =
        BasicBlock::Create(context, "while_header", entryBlock->getParent(), 0);
    BasicBlock *bodyBlock =
        BasicBlock::Create(context, "while_body", entryBlock->getParent(), 0);
    BasicBlock *after =
        BasicBlock::Create(context, "after_while", entryBlock->getParent(), 0);
    BranchInst::Create(headerBlock, entryBlock);
    pushBlock(headerBlock);
    node.condition->accept(*this);
    Value *cond = static_cast<Value *>(this->returned);
    Constant *zero = ConstantInt::get(Type::getInt64Ty(context), 0, true);
    ICmpInst *comparison =
        new ICmpInst(*topBlock(), ICmpInst::ICMP_NE, cond, zero, "tmp");
    BranchInst::Create(bodyBlock, after, comparison, headerBlock);
    popBlock();
    pushBlock(bodyBlock);
    cerr << "into while" << endl;
    node.block->accept(*this);
    cerr << "out of while" << endl;
    BranchInst::Create(headerBlock, topBlock());
    popBlock();
    auto locals = getLocals();
    pushBlock(after);
    setLocals(locals);
  }
  virtual void visit(ASTParamListNode &node) {
    for (auto &x : node.declarations) {
      x->accept(*this);
    }
  }
  virtual void visit(ASTArgListNode &node) {}
  virtual void visit(ASTFunctionCallNode &node) {
    vector<Value *> args;
    builder->SetInsertPoint(topBlock());
    for (auto &x : node.argList->args) {
      x->accept(*this);
      Value *tmp = static_cast<Value *>(this->returned);
      args.push_back(tmp);
    }
    if (node.id == "printf") {
      vector<Type *> runTimeFuncArgs;
      for (auto &x : args) {
        runTimeFuncArgs.push_back(x->getType());
      }
      FunctionType *runTimeFuncType =
          FunctionType::get(builder->getInt32Ty(), runTimeFuncArgs, false);
      Function::Create(runTimeFuncType, Function::ExternalLinkage, "printf",
                       module);
      Function *extPrintf = module->getFunction("printf");
      builder->CreateCall(extPrintf, args);
      return;
    }
    if (node.id == "scanf") {
      vector<Type *> runTimeFuncArgs;
      vector<Value *> tmp_args;
      tmp_args.push_back(args[0]);
      for (int i = 1; i < node.argList->args.size(); ++i) {
        Value *location = getBlock(dynamic_cast<ASTIdentifierNode *>(
                                       node.argList->args[i]->expressions[0])
                                       ->id);
        tmp_args.push_back(location);
      }
      for (auto &x : tmp_args) {
        runTimeFuncArgs.push_back(x->getType());
      }
      FunctionType *runTimeFuncType =
          FunctionType::get(builder->getInt64Ty(), runTimeFuncArgs, false);
      Function::Create(runTimeFuncType, Function::ExternalLinkage, "scanf",
                       module);
      Function *extScanf = module->getFunction("scanf");
      builder->CreateCall(extScanf, tmp_args);
      return;
    }
    Function *func = module->getFunction(node.id);
    this->returned = builder->CreateCall(func, args);
  }
  virtual void visit(ASTReturnStatementNode &node) {
    cerr << "Returning" << endl;
    BasicBlock *top = topBlock();
    Function *function = top->getParent();
    if (function->getReturnType()->isVoidTy() == true) {
      if (node.value != NULL) {
        error("Cannot return something in a void function");
      } else {
        this->returned = ReturnInst::Create(context, topBlock());
      }
    } else {
      if (node.value != NULL) {
        node.value->accept(*this);
        Value *ret = static_cast<Value *>(this->returned);
        this->returned = ReturnInst::Create(context, ret, topBlock());
      } else {
        error("Incorrect return type");
      }
    }
  }
  virtual void visit(ASTTypeNode &node){};
  virtual void visit(ASTStatementNode &node){};
  virtual void visit(ASTNonControlNode &node){};
  virtual void visit(ASTControlNode &node){};
  virtual void visit(ASTProgramNode &node){};
  virtual void visit(ASTStructDeclarationNode &node){};
  virtual void visit(ASTIncludeNode &node){};
  virtual void visit(ASTConstantNode &node) {
    cerr << "NODE " << node.value << " of type " << node.type << endl;
    if (node.type == "integer")
      this->returned = ConstantInt::get(context, APInt(64, stoi(node.value)));
    if (node.type == "char") {
      string input_str = node.value;
      string escaped_str;
      for (int i = 0; i < input_str.size(); i++) {
        if (input_str[i] == '\\') {
          if (i != (int)input_str.size() - 1 && input_str[i + 1] == 'n') {
            escaped_str += '\n';
            i++;
          } else if (i != (int)input_str.size() - 1 &&
                     input_str[i + 1] == 't') {
            escaped_str += '\t';
            i++;
          } else if (i != (int)input_str.size() - 1 &&
                     input_str[i + 1] == '0') {
            escaped_str += '\0';
            i++;
          } else {
            escaped_str += '\\';
          }
        } else {
          escaped_str += input_str[i];
        }
      }
      node.value = escaped_str;
      this->returned = builder->CreateGlobalStringPtr(escaped_str);
    }
  }
  ~CodegenVisitor() {}
};
