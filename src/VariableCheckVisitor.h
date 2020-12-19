#include <bits/stdc++.h>

#include "minicAST.h"
using namespace std;

ASTFunctionDeclarationNode *standard_function(string name) {
  ASTFunctionDeclarationNode *node = new ASTFunctionDeclarationNode();
  ASTTypeNode *void_type = new ASTTypeNode();
  void_type->primitive = "void";
  node->id = name;
  node->isStandard = true;
  node->returntype = void_type;
  return (ASTFunctionDeclarationNode *)node;
}
class VariableCheckVisitor : ASTvisitor {
 public:
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
    unordered_map<string, ASTTypeNode *> func_scope;
    variable_scope.push_back(func_scope);
    if (node.params) node.params->accept(*this);
    node.block->accept(*this);
    variable_scope.pop_back();
  }
  virtual void visit(ASTBlockNode &node) {
    unordered_map<string, ASTTypeNode *> block_scope;
    variable_scope.push_back(block_scope);
    for (auto &x : node.programs) {
      x->accept(*this);
    }
    variable_scope.pop_back();
  }
  virtual void visit(ASTExprNode &node) {
    for (auto &x : node.expressions) {
      x->accept(*this);
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
    node.l->accept(*this);
    node.r->accept(*this);
    if (node.r->type != "undefined" && node.r->type != node.l->type) {
      cerr << "-------------ERROR: Assignment Type Mismatch" << endl;
    }
  }
  virtual void visit(ASTDeclarationNode &node) {
    auto current_scope = variable_scope.rbegin();
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
      if (x.second) x.second->accept(*this);
      if (x.second && x.second->type != "undefined" &&
          x.second->type != node.type->primitive) {
        cerr << "-------------ERROR: Assignment Type Mismatch" << endl;
      }
    }
  }
  virtual void visit(ASTIdentifierNode &node) {
    bool flag = false;
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
  }
  virtual void visit(ASTIfElseNode &node) {
    node.condition->accept(*this);
    node.onTrue->accept(*this);
    if (node.onFalse) {
      node.onFalse->accept(*this);
    }
  }
  virtual void visit(ASTForStatementNode &node) {
    node.init->accept(*this);
    node.condition->accept(*this);
    node.iteration->accept(*this);
    node.block->accept(*this);
  }
  virtual void visit(ASTWhileStatementNode &node) {
    node.condition->accept(*this);
    node.block->accept(*this);
  }
  virtual void visit(ASTParamListNode &node) {
    for (auto &x : node.declarations) {
      x->accept(*this);
    }
  }
  virtual void visit(ASTArgListNode &node) {
    for (auto &x : node.args) {
      x->accept(*this);
    }
  }
  virtual void visit(ASTFunctionCallNode &node) {
    node.argList->accept(*this);
    if (!functionMatch(node)) {
      cerr << "No matching function to " << node.id << " found" << endl;
    }
  }
  virtual void visit(ASTReturnStatementNode &node) {
    node.value->accept(*this);
  }
  virtual void visit(ASTTypeNode &node){};
  virtual void visit(ASTStatementNode &node){};
  virtual void visit(ASTNonControlNode &node){};
  virtual void visit(ASTControlNode &node){};
  virtual void visit(ASTProgramNode &node){};
  virtual void visit(ASTStructDeclarationNode &node){};
  virtual void visit(ASTIncludeNode &node){};
  virtual void visit(ASTConstantNode &node){};
};