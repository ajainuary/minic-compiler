
// Generated from minic.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "minicParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by minicParser.
 */
class  minicVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by minicParser.
   */
    virtual antlrcpp::Any visitProg(minicParser::ProgContext *context) = 0;

    virtual antlrcpp::Any visitArrowPass(minicParser::ArrowPassContext *context) = 0;

    virtual antlrcpp::Any visitBinaryArrow(minicParser::BinaryArrowContext *context) = 0;

    virtual antlrcpp::Any visitUnaryOperate(minicParser::UnaryOperateContext *context) = 0;

    virtual antlrcpp::Any visitUnaryPass(minicParser::UnaryPassContext *context) = 0;

    virtual antlrcpp::Any visitBinaryMultiplicative(minicParser::BinaryMultiplicativeContext *context) = 0;

    virtual antlrcpp::Any visitMultiplicativePass(minicParser::MultiplicativePassContext *context) = 0;

    virtual antlrcpp::Any visitBinaryAdditive(minicParser::BinaryAdditiveContext *context) = 0;

    virtual antlrcpp::Any visitAdditivePass(minicParser::AdditivePassContext *context) = 0;

    virtual antlrcpp::Any visitBinaryComparison(minicParser::BinaryComparisonContext *context) = 0;

    virtual antlrcpp::Any visitComparisonPass(minicParser::ComparisonPassContext *context) = 0;

    virtual antlrcpp::Any visitBinaryBoolean(minicParser::BinaryBooleanContext *context) = 0;

    virtual antlrcpp::Any visitBooleanPass(minicParser::BooleanPassContext *context) = 0;

    virtual antlrcpp::Any visitExprParenthesis(minicParser::ExprParenthesisContext *context) = 0;

    virtual antlrcpp::Any visitExprCall(minicParser::ExprCallContext *context) = 0;

    virtual antlrcpp::Any visitExprIdentifier(minicParser::ExprIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitExprNumber(minicParser::ExprNumberContext *context) = 0;

    virtual antlrcpp::Any visitExprLiteral(minicParser::ExprLiteralContext *context) = 0;

    virtual antlrcpp::Any visitExprString(minicParser::ExprStringContext *context) = 0;

    virtual antlrcpp::Any visitAssign(minicParser::AssignContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration(minicParser::DeclarationContext *context) = 0;

    virtual antlrcpp::Any visitType(minicParser::TypeContext *context) = 0;

    virtual antlrcpp::Any visitExprStatement(minicParser::ExprStatementContext *context) = 0;

    virtual antlrcpp::Any visitAssignStatement(minicParser::AssignStatementContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationStatement(minicParser::DeclarationStatementContext *context) = 0;

    virtual antlrcpp::Any visitRetStatement(minicParser::RetStatementContext *context) = 0;

    virtual antlrcpp::Any visitStructDeclarationStatement(minicParser::StructDeclarationStatementContext *context) = 0;

    virtual antlrcpp::Any visitNonControlDeclaration(minicParser::NonControlDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitNonControlAssign(minicParser::NonControlAssignContext *context) = 0;

    virtual antlrcpp::Any visitNonControlStructDeclaration(minicParser::NonControlStructDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitIfElse(minicParser::IfElseContext *context) = 0;

    virtual antlrcpp::Any visitTernary(minicParser::TernaryContext *context) = 0;

    virtual antlrcpp::Any visitControl(minicParser::ControlContext *context) = 0;

    virtual antlrcpp::Any visitForStatement(minicParser::ForStatementContext *context) = 0;

    virtual antlrcpp::Any visitWhileStatement(minicParser::WhileStatementContext *context) = 0;

    virtual antlrcpp::Any visitProgram(minicParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitBlock(minicParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitParamList(minicParser::ParamListContext *context) = 0;

    virtual antlrcpp::Any visitArgList(minicParser::ArgListContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDeclaration(minicParser::FunctionDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitFunctionCall(minicParser::FunctionCallContext *context) = 0;

    virtual antlrcpp::Any visitReturnStatement(minicParser::ReturnStatementContext *context) = 0;

    virtual antlrcpp::Any visitStructDeclaration(minicParser::StructDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitInclude(minicParser::IncludeContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier(minicParser::IdentifierContext *context) = 0;


};

