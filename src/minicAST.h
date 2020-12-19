#include <bits/stdc++.h>
using namespace std;

class ASTProgNode;
class ASTExprNode;
class ASTAssignNode;
class ASTDeclarationNode;
class ASTTypeNode;
class ASTStatementNode;
class ASTNonControlNode;
class ASTIfElseNode;
class ASTControlNode;
class ASTForStatementNode;
class ASTWhileStatementNode;
class ASTProgramNode;
class ASTBlockNode;
class ASTParamListNode;
class ASTArgListNode;
class ASTFunctionDeclarationNode;
class ASTFunctionCallNode;
class ASTReturnStatementNode;
class ASTStructDeclarationNode;
class ASTIncludeNode;
class ASTIdentifierNode;
class ASTConstantNode;

class ASTvisitor {
 public:
  virtual void visit(ASTProgNode &node) = 0;
  virtual void visit(ASTExprNode &node) = 0;
  virtual void visit(ASTAssignNode &node) = 0;
  virtual void visit(ASTDeclarationNode &node) = 0;
  virtual void visit(ASTTypeNode &node) = 0;
  virtual void visit(ASTStatementNode &node) = 0;
  virtual void visit(ASTNonControlNode &node) = 0;
  virtual void visit(ASTIfElseNode &node) = 0;
  virtual void visit(ASTControlNode &node) = 0;
  virtual void visit(ASTForStatementNode &node) = 0;
  virtual void visit(ASTWhileStatementNode &node) = 0;
  virtual void visit(ASTProgramNode &node) = 0;
  virtual void visit(ASTBlockNode &node) = 0;
  virtual void visit(ASTParamListNode &node) = 0;
  virtual void visit(ASTArgListNode &node) = 0;
  virtual void visit(ASTFunctionDeclarationNode &node) = 0;
  virtual void visit(ASTFunctionCallNode &node) = 0;
  virtual void visit(ASTReturnStatementNode &node) = 0;
  virtual void visit(ASTStructDeclarationNode &node) = 0;
  virtual void visit(ASTIncludeNode &node) = 0;
  virtual void visit(ASTIdentifierNode &node) = 0;
  virtual void visit(ASTConstantNode &node) = 0;
};

class ASTNode {
 public:
  virtual void accept(ASTvisitor &v) = 0;
};

class ASTProgNode {
 public:
  vector<ASTProgramNode *> programs;
  virtual void accept(ASTvisitor &v) { v.visit(*this); };
};

class ASTProgramNode : ASTNode {
 public:
  virtual void accept(ASTvisitor &v) { v.visit(*this); };
};

class ASTBlockNode : ASTProgramNode {
 public:
  virtual void accept(ASTvisitor &v) { v.visit(*this); };
  vector<ASTProgramNode *> programs;
};

class ASTStatementNode : ASTProgramNode {
 public:
  virtual void accept(ASTvisitor &v) { v.visit(*this); };
};

class ASTExprNode : ASTProgramNode {
 public:
  virtual void accept(ASTvisitor &v) { v.visit(*this); }
  vector<ASTExprNode *> expressions;
  string operation;
  string type = "undefined";
};

class ASTAssignNode : ASTNode {
 public:
  virtual void accept(ASTvisitor &v) { v.visit(*this); }
  ASTIdentifierNode *l;
  ASTExprNode *r;
};

class ASTIdentifierNode : public ASTExprNode {
 public:
  string id;
  ASTExprNode *d;
  virtual void accept(ASTvisitor &v) { v.visit(*this); }
};

class ASTConstantNode : public ASTExprNode {
 public:
  string datatype;
  string value;
  virtual void accept(ASTvisitor &v) { v.visit(*this); }
};

class ASTParamListNode : ASTProgramNode {
 public:
  vector<ASTDeclarationNode *> declarations;
  virtual void accept(ASTvisitor &v) { v.visit(*this); }
};
class ASTArgListNode : ASTProgramNode {
 public:
  vector<ASTExprNode *> args;
  virtual void accept(ASTvisitor &v) { v.visit(*this); }
};

class ASTDeclarationNode : ASTProgramNode {
 public:
  ASTTypeNode *type;
  vector<pair<ASTIdentifierNode *, ASTExprNode *>> identifiers;
  virtual void accept(ASTvisitor &v) { v.visit(*this); }
};

class ASTControlNode : ASTProgramNode {
 public:
  typedef ASTProgramNode ASTProgramNode;
  virtual void accept(ASTvisitor &v) { v.visit(*this); };
};

class ASTFunctionDeclarationNode : ASTProgramNode {
 public:
  string id;
  ASTTypeNode *returntype = nullptr;
  ASTBlockNode *block = nullptr;
  ASTParamListNode *params = nullptr;
  bool isStandard = false;
  virtual void accept(ASTvisitor &v) { v.visit(*this); };
};

class ASTFunctionCallNode : public ASTExprNode {
 public:
  string id;
  ASTArgListNode *argList;
  virtual void accept(ASTvisitor &v) { v.visit(*this); };
};

class ASTIncludeNode : ASTProgramNode {
 public:
  virtual void accept(ASTvisitor &v) { v.visit(*this); };
};

class ASTReturnStatementNode : ASTControlNode {
 public:
  ASTExprNode *value = nullptr;
  virtual void accept(ASTvisitor &v) { v.visit(*this); };
};

class ASTForStatementNode : ASTControlNode {
 public:
  ASTProgramNode *init = nullptr;
  ASTExprNode *condition = nullptr;
  ASTProgramNode *iteration = nullptr;
  ASTBlockNode *block = nullptr;
  virtual void accept(ASTvisitor &v) { v.visit(*this); };
};

class ASTWhileStatementNode : ASTControlNode {
 public:
  ASTExprNode *condition = nullptr;
  ASTBlockNode *block = nullptr;
  virtual void accept(ASTvisitor &v) { v.visit(*this); };
};

class ASTIfElseNode : ASTControlNode {
 public:
  virtual void accept(ASTvisitor &v) { v.visit(*this); };
  ASTBlockNode *onTrue;
  ASTBlockNode *onFalse;
  ASTExprNode *condition;
};

class ASTTypeNode : ASTNode {
 public:
  string primitive;
  virtual void accept(ASTvisitor &v) { v.visit(*this); };
};