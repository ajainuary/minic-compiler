
// Generated from minic.g4 by ANTLR 4.8
#include <bits/stdc++.h>
using namespace std;
#pragma once

#include "antlr4-runtime.h"
// #include "minicAST.h"
#include "minicVisitor.h"

ASTProgramNode *express(ASTExprNode *e) {
  ASTExprNode *node = new ASTExprNode();
  node->operation = "+";
  node->expressions.push_back(e);
  return (ASTProgramNode *)node;
}
class minicBuildASTVisitor : public minicVisitor {
 public:
  virtual antlrcpp::Any visitProg(minicParser::ProgContext *ctx) override {
    ASTProgNode *node = new ASTProgNode();
    for (auto &program : ctx->program()) {
      ASTProgramNode *tmp = visit(program);
      node->programs.push_back(tmp);
    }
    return (ASTProgNode *)node;
  }

  virtual antlrcpp::Any visitArrowPass(
      minicParser::ArrowPassContext *ctx) override {
    return (ASTExprNode *)visit(ctx->expr());
  }

  virtual antlrcpp::Any visitBinaryArrow(
      minicParser::BinaryArrowContext *ctx) override {
    ASTExprNode *node = new ASTExprNode();
    node->operation = "->";
    for (auto &expr : ctx->expr()) {
      node->expressions.push_back(visit(expr));
    }
    return (ASTExprNode *)node;
  }

  virtual antlrcpp::Any visitUnaryOperate(
      minicParser::UnaryOperateContext *ctx) override {
    ASTExprNode *node = new ASTExprNode();
    node->operation = ctx->OP->getText();
    node->expressions.push_back(visit(ctx->arrowExpr()));
    return (ASTExprNode *)node;
  }

  virtual antlrcpp::Any visitUnaryPass(
      minicParser::UnaryPassContext *ctx) override {
    return visit(ctx->arrowExpr());
  }

  virtual antlrcpp::Any visitBinaryMultiplicative(
      minicParser::BinaryMultiplicativeContext *ctx) override {
    ASTExprNode *node = new ASTExprNode();
    node->operation = ctx->OP->getText();
    node->expressions.push_back(visit(ctx->multiplicativeExpr()));
    node->expressions.push_back(visit(ctx->unaryExpr()));
    return (ASTExprNode *)node;
  }

  virtual antlrcpp::Any visitMultiplicativePass(
      minicParser::MultiplicativePassContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinaryAdditive(
      minicParser::BinaryAdditiveContext *ctx) override {
    ASTExprNode *node = new ASTExprNode();
    node->operation = ctx->OP->getText();
    node->expressions.push_back(visit(ctx->additiveExpr()));
    node->expressions.push_back(visit(ctx->multiplicativeExpr()));
    return (ASTExprNode *)node;
  }

  virtual antlrcpp::Any visitAdditivePass(
      minicParser::AdditivePassContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinaryComparison(
      minicParser::BinaryComparisonContext *ctx) override {
    ASTExprNode *node = new ASTExprNode();
    node->operation = ctx->OP->getText();
    for (auto &expr : ctx->additiveExpr()) {
      node->expressions.push_back(visit(expr));
    }
    return (ASTExprNode *)node;
  }

  virtual antlrcpp::Any visitComparisonPass(
      minicParser::ComparisonPassContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinaryBoolean(
      minicParser::BinaryBooleanContext *ctx) override {
    ASTExprNode *node = new ASTExprNode();
    node->operation = ctx->OP->getText();
    for (auto &expr : ctx->comparisonExpr()) {
      node->expressions.push_back(visit(expr));
    }
    return (ASTExprNode *)node;
  }

  virtual antlrcpp::Any visitBooleanPass(
      minicParser::BooleanPassContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprParenthesis(
      minicParser::ExprParenthesisContext *ctx) override {
    return visit(ctx->booleanExpr());
  }

  virtual antlrcpp::Any visitExprCall(
      minicParser::ExprCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprIdentifier(
      minicParser::ExprIdentifierContext *ctx) override {
    ASTExprNode *node = new ASTExprNode();
    node->operation = "+";
    ASTIdentifierNode *node2 = new ASTIdentifierNode();
    node2->id = ctx->identifier()->ID(0)->getText();
    node2->d = nullptr;
    if (!ctx->identifier()->comparisonExpr().empty()) {
      node2->d = visit(ctx->identifier()->comparisonExpr(0));
    }
    node->expressions.push_back(node2);
    return (ASTExprNode *)node;
  }
  virtual antlrcpp::Any visitExprNumber(
      minicParser::ExprNumberContext *ctx) override {
    ASTConstantNode *node = new ASTConstantNode();
    node->value = ctx->NUMBER()->getText();
    node->type = "integer";
    return (ASTExprNode *)node;
  }

  virtual antlrcpp::Any visitExprLiteral(
      minicParser::ExprLiteralContext *ctx) override {
    ASTConstantNode *node = new ASTConstantNode();
    node->value = ctx->LITERAL()->getText();
    node->type = "char";
    return (ASTExprNode *)node;
  }

  virtual antlrcpp::Any visitExprString(
      minicParser::ExprStringContext *ctx) override {
    ASTConstantNode *node = new ASTConstantNode();
    node->value = ctx->STRING()->getText();
    node->type = "string";
    return (ASTExprNode *)node;
  }

  virtual antlrcpp::Any visitAssign(minicParser::AssignContext *ctx) override {
    ASTAssignNode *node = new ASTAssignNode();
    node->l = visit(ctx->identifier());
    node->r = visit(ctx->booleanExpr());
    return (ASTProgramNode *)node;
  }

  virtual antlrcpp::Any visitDeclaration(
      minicParser::DeclarationContext *ctx) override {
    ASTDeclarationNode *node = new ASTDeclarationNode();
    node->type = visit(ctx->type());
    for (auto &x : ctx->identifier()) {
      node->identifiers.push_back({visit(x), (ASTExprNode *)nullptr});
    }
    for (auto &x : ctx->assign()) {
      node->identifiers.push_back(
          {visit(x->identifier()), visit(x->booleanExpr())});
    }
    return (ASTDeclarationNode *)node;
  }

  virtual antlrcpp::Any visitType(minicParser::TypeContext *ctx) override {
    ASTTypeNode *node = new ASTTypeNode();
    node->primitive = ctx->PRIMITIVE->getText();
    return (ASTTypeNode *)node;
  }

  virtual antlrcpp::Any visitExprStatement(
      minicParser::ExprStatementContext *ctx) override {
    ASTExprNode *node = new ASTExprNode();
    node->operation = "+";
    node->expressions.push_back(visit(ctx->booleanExpr()));
    return (ASTProgramNode *)node;
  }

  virtual antlrcpp::Any visitAssignStatement(
      minicParser::AssignStatementContext *ctx) override {
    for (auto &x : ctx->children) {
      return visit(x);
    }
  }

  virtual antlrcpp::Any visitDeclarationStatement(
      minicParser::DeclarationStatementContext *ctx) override {
    ASTDeclarationNode *node = visit(ctx->declaration());
    return (ASTProgramNode *)node;
  }

  virtual antlrcpp::Any visitRetStatement(
      minicParser::RetStatementContext *ctx) override {
    for (auto &x : ctx->children) {
      return visit(x);
    }
  }

  virtual antlrcpp::Any visitStructDeclarationStatement(
      minicParser::StructDeclarationStatementContext *ctx) override {
    for (auto &x : ctx->children) {
      return visit(x);
    }
  }

  virtual antlrcpp::Any visitNonControlDeclaration(
      minicParser::NonControlDeclarationContext *ctx) override {
    ASTDeclarationNode *node = visit(ctx->declaration());
    return (ASTProgramNode *)node;
  }

  virtual antlrcpp::Any visitNonControlAssign(
      minicParser::NonControlAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNonControlStructDeclaration(
      minicParser::NonControlStructDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfElse(minicParser::IfElseContext *ctx) override {
    ASTIfElseNode *node = new ASTIfElseNode();
    node->condition = visit(ctx->booleanExpr());
    node->onTrue = visit(ctx->block(0));
    if (ctx->block().size() > 1) {
      node->onFalse = visit(ctx->block(1));
    }
    return (ASTProgramNode *)node;
  }

  virtual antlrcpp::Any visitTernary(
      minicParser::TernaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitControl(
      minicParser::ControlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForStatement(
      minicParser::ForStatementContext *ctx) override {
    ASTForStatementNode *node = new ASTForStatementNode();
    node->init = visit(ctx->nonControl(0));
    node->condition = visit(ctx->booleanExpr());
    node->iteration = visit(ctx->nonControl(1));
    node->block = visit(ctx->block());
    return (ASTProgramNode *)node;
  }

  virtual antlrcpp::Any visitWhileStatement(
      minicParser::WhileStatementContext *ctx) override {
    ASTWhileStatementNode *node = new ASTWhileStatementNode();
    node->condition = visit(ctx->booleanExpr());
    node->block = visit(ctx->block());
    return (ASTProgramNode *)node;
  }

  virtual antlrcpp::Any visitProgram(
      minicParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(minicParser::BlockContext *ctx) override {
    ASTBlockNode *node = new ASTBlockNode();
    for (auto &x : ctx->program()) {
      node->programs.push_back(visit(x));
    }
    return (ASTBlockNode *)node;
  }

  virtual antlrcpp::Any visitParamList(
      minicParser::ParamListContext *ctx) override {
    ASTParamListNode *node = new ASTParamListNode();
    for (auto &x : ctx->declaration()) {
      node->declarations.push_back(visit(x));
    }
    return (ASTParamListNode *)node;
  }

  virtual antlrcpp::Any visitArgList(
      minicParser::ArgListContext *ctx) override {
    ASTArgListNode *node = new ASTArgListNode();
    for (auto &x : ctx->booleanExpr()) {
      node->args.push_back(visit(x));
    }
    return (ASTArgListNode *)node;
  }

  virtual antlrcpp::Any visitFunctionDeclaration(
      minicParser::FunctionDeclarationContext *ctx) override {
    ASTFunctionDeclarationNode *node = new ASTFunctionDeclarationNode();
    node->id = ctx->ID()->getText();
    node->returntype = visit(ctx->type());
    node->block = visit(ctx->block());
    if (ctx->paramList()) node->params = visit(ctx->paramList());
    return (ASTProgramNode *)node;
  }

  virtual antlrcpp::Any visitFunctionCall(
      minicParser::FunctionCallContext *ctx) override {
    ASTFunctionCallNode *node = new ASTFunctionCallNode();
    node->id = ctx->ID()->getText();
    cerr << "-build " << ctx->getText() << endl;
    if (ctx->argList()) node->argList = visit(ctx->argList());
    return (ASTExprNode *)node;
  }

  virtual antlrcpp::Any visitReturnStatement(
      minicParser::ReturnStatementContext *ctx) override {
    ASTReturnStatementNode *node = new ASTReturnStatementNode();
    node->value = visit(ctx->booleanExpr());
    return (ASTProgramNode *)node;
  }

  virtual antlrcpp::Any visitStructDeclaration(
      minicParser::StructDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInclude(
      minicParser::IncludeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifier(
      minicParser::IdentifierContext *ctx) override {
    ASTIdentifierNode *node = new ASTIdentifierNode();
    node->id = ctx->ID(0)->getText();
    node->d = nullptr;
    cerr << "-build visit " << node->id << " " << ctx->getText();
    if (!ctx->comparisonExpr().empty()) {
      cerr << "-access" << endl;
      node->d = visit(ctx->comparisonExpr(0));
      cerr << "-access returns " << node->d << endl;
    }
    return (ASTIdentifierNode *)node;
  }
};
