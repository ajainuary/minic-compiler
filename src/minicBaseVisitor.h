
// Generated from minic.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "minicVisitor.h"


/**
 * This class provides an empty implementation of minicVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  minicBaseVisitor : public minicVisitor {
public:

  virtual antlrcpp::Any visitProg(minicParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrowPass(minicParser::ArrowPassContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinaryArrow(minicParser::BinaryArrowContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryOperate(minicParser::UnaryOperateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryPass(minicParser::UnaryPassContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinaryMultiplicative(minicParser::BinaryMultiplicativeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultiplicativePass(minicParser::MultiplicativePassContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinaryAdditive(minicParser::BinaryAdditiveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAdditivePass(minicParser::AdditivePassContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinaryComparison(minicParser::BinaryComparisonContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComparisonPass(minicParser::ComparisonPassContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinaryBoolean(minicParser::BinaryBooleanContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBooleanPass(minicParser::BooleanPassContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprParenthesis(minicParser::ExprParenthesisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprCall(minicParser::ExprCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprIdentifier(minicParser::ExprIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprNumber(minicParser::ExprNumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprLiteral(minicParser::ExprLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprString(minicParser::ExprStringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssign(minicParser::AssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclaration(minicParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(minicParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprStatement(minicParser::ExprStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignStatement(minicParser::AssignStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarationStatement(minicParser::DeclarationStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRetStatement(minicParser::RetStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStructDeclarationStatement(minicParser::StructDeclarationStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNonControlDeclaration(minicParser::NonControlDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNonControlAssign(minicParser::NonControlAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNonControlStructDeclaration(minicParser::NonControlStructDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfElse(minicParser::IfElseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTernary(minicParser::TernaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitControl(minicParser::ControlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForStatement(minicParser::ForStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileStatement(minicParser::WhileStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProgram(minicParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(minicParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParamList(minicParser::ParamListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgList(minicParser::ArgListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDeclaration(minicParser::FunctionDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionCall(minicParser::FunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturnStatement(minicParser::ReturnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStructDeclaration(minicParser::StructDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInclude(minicParser::IncludeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifier(minicParser::IdentifierContext *ctx) override {
    return visitChildren(ctx);
  }


};

