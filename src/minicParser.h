
// Generated from minic.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  minicParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, T__29 = 30, T__30 = 31, T__31 = 32, 
    T__32 = 33, T__33 = 34, T__34 = 35, T__35 = 36, T__36 = 37, T__37 = 38, 
    T__38 = 39, T__39 = 40, T__40 = 41, T__41 = 42, ID = 43, NUMBER = 44, 
    LITERAL = 45, STRING = 46, COMMENT = 47, NS = 48
  };

  enum {
    RuleProg = 0, RuleArrowExpr = 1, RuleUnaryExpr = 2, RuleMultiplicativeExpr = 3, 
    RuleAdditiveExpr = 4, RuleComparisonExpr = 5, RuleBooleanExpr = 6, RuleExpr = 7, 
    RuleAssign = 8, RuleDeclaration = 9, RuleType = 10, RuleStatement = 11, 
    RuleNonControl = 12, RuleIfElse = 13, RuleTernary = 14, RuleControl = 15, 
    RuleForStatement = 16, RuleWhileStatement = 17, RuleProgram = 18, RuleBlock = 19, 
    RuleParamList = 20, RuleArgList = 21, RuleFunctionDeclaration = 22, 
    RuleFunctionCall = 23, RuleReturnStatement = 24, RuleStructDeclaration = 25, 
    RuleInclude = 26, RuleIdentifier = 27
  };

  minicParser(antlr4::TokenStream *input);
  ~minicParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgContext;
  class ArrowExprContext;
  class UnaryExprContext;
  class MultiplicativeExprContext;
  class AdditiveExprContext;
  class ComparisonExprContext;
  class BooleanExprContext;
  class ExprContext;
  class AssignContext;
  class DeclarationContext;
  class TypeContext;
  class StatementContext;
  class NonControlContext;
  class IfElseContext;
  class TernaryContext;
  class ControlContext;
  class ForStatementContext;
  class WhileStatementContext;
  class ProgramContext;
  class BlockContext;
  class ParamListContext;
  class ArgListContext;
  class FunctionDeclarationContext;
  class FunctionCallContext;
  class ReturnStatementContext;
  class StructDeclarationContext;
  class IncludeContext;
  class IdentifierContext; 

  class  ProgContext : public antlr4::ParserRuleContext {
  public:
    ProgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<ProgramContext *> program();
    ProgramContext* program(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgContext* prog();

  class  ArrowExprContext : public antlr4::ParserRuleContext {
  public:
    ArrowExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ArrowExprContext() = default;
    void copyFrom(ArrowExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  BinaryArrowContext : public ArrowExprContext {
  public:
    BinaryArrowContext(ArrowExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ArrowPassContext : public ArrowExprContext {
  public:
    ArrowPassContext(ArrowExprContext *ctx);

    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ArrowExprContext* arrowExpr();

  class  UnaryExprContext : public antlr4::ParserRuleContext {
  public:
    UnaryExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    UnaryExprContext() = default;
    void copyFrom(UnaryExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  UnaryOperateContext : public UnaryExprContext {
  public:
    UnaryOperateContext(UnaryExprContext *ctx);

    antlr4::Token *OP = nullptr;
    ArrowExprContext *arrowExpr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UnaryPassContext : public UnaryExprContext {
  public:
    UnaryPassContext(UnaryExprContext *ctx);

    ArrowExprContext *arrowExpr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  UnaryExprContext* unaryExpr();

  class  MultiplicativeExprContext : public antlr4::ParserRuleContext {
  public:
    MultiplicativeExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    MultiplicativeExprContext() = default;
    void copyFrom(MultiplicativeExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  BinaryMultiplicativeContext : public MultiplicativeExprContext {
  public:
    BinaryMultiplicativeContext(MultiplicativeExprContext *ctx);

    antlr4::Token *OP = nullptr;
    MultiplicativeExprContext *multiplicativeExpr();
    UnaryExprContext *unaryExpr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MultiplicativePassContext : public MultiplicativeExprContext {
  public:
    MultiplicativePassContext(MultiplicativeExprContext *ctx);

    UnaryExprContext *unaryExpr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  MultiplicativeExprContext* multiplicativeExpr();
  MultiplicativeExprContext* multiplicativeExpr(int precedence);
  class  AdditiveExprContext : public antlr4::ParserRuleContext {
  public:
    AdditiveExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    AdditiveExprContext() = default;
    void copyFrom(AdditiveExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  BinaryAdditiveContext : public AdditiveExprContext {
  public:
    BinaryAdditiveContext(AdditiveExprContext *ctx);

    antlr4::Token *OP = nullptr;
    AdditiveExprContext *additiveExpr();
    MultiplicativeExprContext *multiplicativeExpr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AdditivePassContext : public AdditiveExprContext {
  public:
    AdditivePassContext(AdditiveExprContext *ctx);

    MultiplicativeExprContext *multiplicativeExpr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  AdditiveExprContext* additiveExpr();
  AdditiveExprContext* additiveExpr(int precedence);
  class  ComparisonExprContext : public antlr4::ParserRuleContext {
  public:
    ComparisonExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ComparisonExprContext() = default;
    void copyFrom(ComparisonExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  BinaryComparisonContext : public ComparisonExprContext {
  public:
    BinaryComparisonContext(ComparisonExprContext *ctx);

    antlr4::Token *OP = nullptr;
    std::vector<AdditiveExprContext *> additiveExpr();
    AdditiveExprContext* additiveExpr(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ComparisonPassContext : public ComparisonExprContext {
  public:
    ComparisonPassContext(ComparisonExprContext *ctx);

    AdditiveExprContext *additiveExpr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ComparisonExprContext* comparisonExpr();

  class  BooleanExprContext : public antlr4::ParserRuleContext {
  public:
    BooleanExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    BooleanExprContext() = default;
    void copyFrom(BooleanExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  BooleanPassContext : public BooleanExprContext {
  public:
    BooleanPassContext(BooleanExprContext *ctx);

    ComparisonExprContext *comparisonExpr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BinaryBooleanContext : public BooleanExprContext {
  public:
    BinaryBooleanContext(BooleanExprContext *ctx);

    antlr4::Token *OP = nullptr;
    std::vector<ComparisonExprContext *> comparisonExpr();
    ComparisonExprContext* comparisonExpr(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  BooleanExprContext* booleanExpr();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprContext() = default;
    void copyFrom(ExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ExprCallContext : public ExprContext {
  public:
    ExprCallContext(ExprContext *ctx);

    FunctionCallContext *functionCall();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprStringContext : public ExprContext {
  public:
    ExprStringContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprIdentifierContext : public ExprContext {
  public:
    ExprIdentifierContext(ExprContext *ctx);

    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprParenthesisContext : public ExprContext {
  public:
    ExprParenthesisContext(ExprContext *ctx);

    BooleanExprContext *booleanExpr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprNumberContext : public ExprContext {
  public:
    ExprNumberContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *NUMBER();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprLiteralContext : public ExprContext {
  public:
    ExprLiteralContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *LITERAL();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprContext* expr();

  class  AssignContext : public antlr4::ParserRuleContext {
  public:
    AssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    BooleanExprContext *booleanExpr();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignContext* assign();

  class  DeclarationContext : public antlr4::ParserRuleContext {
  public:
    DeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);
    std::vector<AssignContext *> assign();
    AssignContext* assign(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationContext* declaration();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *PRIMITIVE = nullptr;;
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    std::vector<BooleanExprContext *> booleanExpr();
    BooleanExprContext* booleanExpr(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeContext* type();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StatementContext() = default;
    void copyFrom(StatementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  DeclarationStatementContext : public StatementContext {
  public:
    DeclarationStatementContext(StatementContext *ctx);

    DeclarationContext *declaration();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprStatementContext : public StatementContext {
  public:
    ExprStatementContext(StatementContext *ctx);

    BooleanExprContext *booleanExpr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RetStatementContext : public StatementContext {
  public:
    RetStatementContext(StatementContext *ctx);

    ReturnStatementContext *returnStatement();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignStatementContext : public StatementContext {
  public:
    AssignStatementContext(StatementContext *ctx);

    AssignContext *assign();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StructDeclarationStatementContext : public StatementContext {
  public:
    StructDeclarationStatementContext(StatementContext *ctx);

    StructDeclarationContext *structDeclaration();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StatementContext* statement();

  class  NonControlContext : public antlr4::ParserRuleContext {
  public:
    NonControlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    NonControlContext() = default;
    void copyFrom(NonControlContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NonControlStructDeclarationContext : public NonControlContext {
  public:
    NonControlStructDeclarationContext(NonControlContext *ctx);

    StructDeclarationContext *structDeclaration();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NonControlAssignContext : public NonControlContext {
  public:
    NonControlAssignContext(NonControlContext *ctx);

    AssignContext *assign();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NonControlDeclarationContext : public NonControlContext {
  public:
    NonControlDeclarationContext(NonControlContext *ctx);

    DeclarationContext *declaration();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  NonControlContext* nonControl();

  class  IfElseContext : public antlr4::ParserRuleContext {
  public:
    IfElseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BooleanExprContext *booleanExpr();
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfElseContext* ifElse();

  class  TernaryContext : public antlr4::ParserRuleContext {
  public:
    TernaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<BooleanExprContext *> booleanExpr();
    BooleanExprContext* booleanExpr(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TernaryContext* ternary();

  class  ControlContext : public antlr4::ParserRuleContext {
  public:
    ControlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ForStatementContext *forStatement();
    WhileStatementContext *whileStatement();
    IfElseContext *ifElse();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ControlContext* control();

  class  ForStatementContext : public antlr4::ParserRuleContext {
  public:
    ForStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<NonControlContext *> nonControl();
    NonControlContext* nonControl(size_t i);
    BooleanExprContext *booleanExpr();
    BlockContext *block();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForStatementContext* forStatement();

  class  WhileStatementContext : public antlr4::ParserRuleContext {
  public:
    WhileStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BooleanExprContext *booleanExpr();
    BlockContext *block();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhileStatementContext* whileStatement();

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();
    StatementContext *statement();
    ControlContext *control();
    FunctionDeclarationContext *functionDeclaration();
    FunctionCallContext *functionCall();
    IncludeContext *include();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ProgramContext *> program();
    ProgramContext* program(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  ParamListContext : public antlr4::ParserRuleContext {
  public:
    ParamListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<DeclarationContext *> declaration();
    DeclarationContext* declaration(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamListContext* paramList();

  class  ArgListContext : public antlr4::ParserRuleContext {
  public:
    ArgListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<BooleanExprContext *> booleanExpr();
    BooleanExprContext* booleanExpr(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgListContext* argList();

  class  FunctionDeclarationContext : public antlr4::ParserRuleContext {
  public:
    FunctionDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    antlr4::tree::TerminalNode *ID();
    BlockContext *block();
    ParamListContext *paramList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionDeclarationContext* functionDeclaration();

  class  FunctionCallContext : public antlr4::ParserRuleContext {
  public:
    FunctionCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    ArgListContext *argList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionCallContext* functionCall();

  class  ReturnStatementContext : public antlr4::ParserRuleContext {
  public:
    ReturnStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BooleanExprContext *booleanExpr();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReturnStatementContext* returnStatement();

  class  StructDeclarationContext : public antlr4::ParserRuleContext {
  public:
    StructDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    ParamListContext *paramList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StructDeclarationContext* structDeclaration();

  class  IncludeContext : public antlr4::ParserRuleContext {
  public:
    IncludeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IncludeContext* include();

  class  IdentifierContext : public antlr4::ParserRuleContext {
  public:
    IdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    std::vector<ComparisonExprContext *> comparisonExpr();
    ComparisonExprContext* comparisonExpr(size_t i);
    std::vector<TernaryContext *> ternary();
    TernaryContext* ternary(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdentifierContext* identifier();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool multiplicativeExprSempred(MultiplicativeExprContext *_localctx, size_t predicateIndex);
  bool additiveExprSempred(AdditiveExprContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

