
// Generated from minic.g4 by ANTLR 4.8


#include "minicVisitor.h"

#include "minicParser.h"


using namespace antlrcpp;
using namespace antlr4;

minicParser::minicParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

minicParser::~minicParser() {
  delete _interpreter;
}

std::string minicParser::getGrammarFileName() const {
  return "minic.g4";
}

const std::vector<std::string>& minicParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& minicParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgContext ------------------------------------------------------------------

minicParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* minicParser::ProgContext::EOF() {
  return getToken(minicParser::EOF, 0);
}

std::vector<minicParser::ProgramContext *> minicParser::ProgContext::program() {
  return getRuleContexts<minicParser::ProgramContext>();
}

minicParser::ProgramContext* minicParser::ProgContext::program(size_t i) {
  return getRuleContext<minicParser::ProgramContext>(i);
}


size_t minicParser::ProgContext::getRuleIndex() const {
  return minicParser::RuleProg;
}


antlrcpp::Any minicParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

minicParser::ProgContext* minicParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, minicParser::RuleProg);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(57); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(56);
      program();
      setState(59); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << minicParser::T__1)
      | (1ULL << minicParser::T__2)
      | (1ULL << minicParser::T__3)
      | (1ULL << minicParser::T__4)
      | (1ULL << minicParser::T__5)
      | (1ULL << minicParser::T__16)
      | (1ULL << minicParser::T__20)
      | (1ULL << minicParser::T__21)
      | (1ULL << minicParser::T__22)
      | (1ULL << minicParser::T__23)
      | (1ULL << minicParser::T__24)
      | (1ULL << minicParser::T__27)
      | (1ULL << minicParser::T__29)
      | (1ULL << minicParser::T__33)
      | (1ULL << minicParser::T__34)
      | (1ULL << minicParser::T__35)
      | (1ULL << minicParser::T__37)
      | (1ULL << minicParser::T__38)
      | (1ULL << minicParser::ID)
      | (1ULL << minicParser::NUMBER)
      | (1ULL << minicParser::LITERAL)
      | (1ULL << minicParser::STRING))) != 0));
    setState(61);
    match(minicParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrowExprContext ------------------------------------------------------------------

minicParser::ArrowExprContext::ArrowExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t minicParser::ArrowExprContext::getRuleIndex() const {
  return minicParser::RuleArrowExpr;
}

void minicParser::ArrowExprContext::copyFrom(ArrowExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BinaryArrowContext ------------------------------------------------------------------

std::vector<minicParser::ExprContext *> minicParser::BinaryArrowContext::expr() {
  return getRuleContexts<minicParser::ExprContext>();
}

minicParser::ExprContext* minicParser::BinaryArrowContext::expr(size_t i) {
  return getRuleContext<minicParser::ExprContext>(i);
}

minicParser::BinaryArrowContext::BinaryArrowContext(ArrowExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any minicParser::BinaryArrowContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitBinaryArrow(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrowPassContext ------------------------------------------------------------------

minicParser::ExprContext* minicParser::ArrowPassContext::expr() {
  return getRuleContext<minicParser::ExprContext>(0);
}

minicParser::ArrowPassContext::ArrowPassContext(ArrowExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any minicParser::ArrowPassContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitArrowPass(this);
  else
    return visitor->visitChildren(this);
}
minicParser::ArrowExprContext* minicParser::arrowExpr() {
  ArrowExprContext *_localctx = _tracker.createInstance<ArrowExprContext>(_ctx, getState());
  enterRule(_localctx, 2, minicParser::RuleArrowExpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(68);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<ArrowExprContext *>(_tracker.createInstance<minicParser::ArrowPassContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(63);
      expr();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<ArrowExprContext *>(_tracker.createInstance<minicParser::BinaryArrowContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(64);
      expr();
      setState(65);
      match(minicParser::T__0);
      setState(66);
      expr();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryExprContext ------------------------------------------------------------------

minicParser::UnaryExprContext::UnaryExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t minicParser::UnaryExprContext::getRuleIndex() const {
  return minicParser::RuleUnaryExpr;
}

void minicParser::UnaryExprContext::copyFrom(UnaryExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- UnaryOperateContext ------------------------------------------------------------------

minicParser::ArrowExprContext* minicParser::UnaryOperateContext::arrowExpr() {
  return getRuleContext<minicParser::ArrowExprContext>(0);
}

minicParser::UnaryOperateContext::UnaryOperateContext(UnaryExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any minicParser::UnaryOperateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitUnaryOperate(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryPassContext ------------------------------------------------------------------

minicParser::ArrowExprContext* minicParser::UnaryPassContext::arrowExpr() {
  return getRuleContext<minicParser::ArrowExprContext>(0);
}

minicParser::UnaryPassContext::UnaryPassContext(UnaryExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any minicParser::UnaryPassContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitUnaryPass(this);
  else
    return visitor->visitChildren(this);
}
minicParser::UnaryExprContext* minicParser::unaryExpr() {
  UnaryExprContext *_localctx = _tracker.createInstance<UnaryExprContext>(_ctx, getState());
  enterRule(_localctx, 4, minicParser::RuleUnaryExpr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(73);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case minicParser::T__1:
      case minicParser::T__2:
      case minicParser::T__3:
      case minicParser::T__4:
      case minicParser::T__5: {
        _localctx = dynamic_cast<UnaryExprContext *>(_tracker.createInstance<minicParser::UnaryOperateContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(70);
        dynamic_cast<UnaryOperateContext *>(_localctx)->OP = _input->LT(1);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << minicParser::T__1)
          | (1ULL << minicParser::T__2)
          | (1ULL << minicParser::T__3)
          | (1ULL << minicParser::T__4)
          | (1ULL << minicParser::T__5))) != 0))) {
          dynamic_cast<UnaryOperateContext *>(_localctx)->OP = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(71);
        arrowExpr();
        break;
      }

      case minicParser::T__16:
      case minicParser::ID:
      case minicParser::NUMBER:
      case minicParser::LITERAL:
      case minicParser::STRING: {
        _localctx = dynamic_cast<UnaryExprContext *>(_tracker.createInstance<minicParser::UnaryPassContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(72);
        arrowExpr();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MultiplicativeExprContext ------------------------------------------------------------------

minicParser::MultiplicativeExprContext::MultiplicativeExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t minicParser::MultiplicativeExprContext::getRuleIndex() const {
  return minicParser::RuleMultiplicativeExpr;
}

void minicParser::MultiplicativeExprContext::copyFrom(MultiplicativeExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BinaryMultiplicativeContext ------------------------------------------------------------------

minicParser::MultiplicativeExprContext* minicParser::BinaryMultiplicativeContext::multiplicativeExpr() {
  return getRuleContext<minicParser::MultiplicativeExprContext>(0);
}

minicParser::UnaryExprContext* minicParser::BinaryMultiplicativeContext::unaryExpr() {
  return getRuleContext<minicParser::UnaryExprContext>(0);
}

minicParser::BinaryMultiplicativeContext::BinaryMultiplicativeContext(MultiplicativeExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any minicParser::BinaryMultiplicativeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitBinaryMultiplicative(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultiplicativePassContext ------------------------------------------------------------------

minicParser::UnaryExprContext* minicParser::MultiplicativePassContext::unaryExpr() {
  return getRuleContext<minicParser::UnaryExprContext>(0);
}

minicParser::MultiplicativePassContext::MultiplicativePassContext(MultiplicativeExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any minicParser::MultiplicativePassContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitMultiplicativePass(this);
  else
    return visitor->visitChildren(this);
}

minicParser::MultiplicativeExprContext* minicParser::multiplicativeExpr() {
   return multiplicativeExpr(0);
}

minicParser::MultiplicativeExprContext* minicParser::multiplicativeExpr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  minicParser::MultiplicativeExprContext *_localctx = _tracker.createInstance<MultiplicativeExprContext>(_ctx, parentState);
  minicParser::MultiplicativeExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, minicParser::RuleMultiplicativeExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<MultiplicativePassContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(76);
    unaryExpr();
    _ctx->stop = _input->LT(-1);
    setState(83);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<BinaryMultiplicativeContext>(_tracker.createInstance<MultiplicativeExprContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleMultiplicativeExpr);
        setState(78);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(79);
        dynamic_cast<BinaryMultiplicativeContext *>(_localctx)->OP = _input->LT(1);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << minicParser::T__4)
          | (1ULL << minicParser::T__6)
          | (1ULL << minicParser::T__7))) != 0))) {
          dynamic_cast<BinaryMultiplicativeContext *>(_localctx)->OP = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(80);
        unaryExpr(); 
      }
      setState(85);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AdditiveExprContext ------------------------------------------------------------------

minicParser::AdditiveExprContext::AdditiveExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t minicParser::AdditiveExprContext::getRuleIndex() const {
  return minicParser::RuleAdditiveExpr;
}

void minicParser::AdditiveExprContext::copyFrom(AdditiveExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BinaryAdditiveContext ------------------------------------------------------------------

minicParser::AdditiveExprContext* minicParser::BinaryAdditiveContext::additiveExpr() {
  return getRuleContext<minicParser::AdditiveExprContext>(0);
}

minicParser::MultiplicativeExprContext* minicParser::BinaryAdditiveContext::multiplicativeExpr() {
  return getRuleContext<minicParser::MultiplicativeExprContext>(0);
}

minicParser::BinaryAdditiveContext::BinaryAdditiveContext(AdditiveExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any minicParser::BinaryAdditiveContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitBinaryAdditive(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AdditivePassContext ------------------------------------------------------------------

minicParser::MultiplicativeExprContext* minicParser::AdditivePassContext::multiplicativeExpr() {
  return getRuleContext<minicParser::MultiplicativeExprContext>(0);
}

minicParser::AdditivePassContext::AdditivePassContext(AdditiveExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any minicParser::AdditivePassContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitAdditivePass(this);
  else
    return visitor->visitChildren(this);
}

minicParser::AdditiveExprContext* minicParser::additiveExpr() {
   return additiveExpr(0);
}

minicParser::AdditiveExprContext* minicParser::additiveExpr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  minicParser::AdditiveExprContext *_localctx = _tracker.createInstance<AdditiveExprContext>(_ctx, parentState);
  minicParser::AdditiveExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 8;
  enterRecursionRule(_localctx, 8, minicParser::RuleAdditiveExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<AdditivePassContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(87);
    multiplicativeExpr(0);
    _ctx->stop = _input->LT(-1);
    setState(94);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<BinaryAdditiveContext>(_tracker.createInstance<AdditiveExprContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleAdditiveExpr);
        setState(89);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(90);
        dynamic_cast<BinaryAdditiveContext *>(_localctx)->OP = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == minicParser::T__1

        || _la == minicParser::T__2)) {
          dynamic_cast<BinaryAdditiveContext *>(_localctx)->OP = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(91);
        multiplicativeExpr(0); 
      }
      setState(96);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ComparisonExprContext ------------------------------------------------------------------

minicParser::ComparisonExprContext::ComparisonExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t minicParser::ComparisonExprContext::getRuleIndex() const {
  return minicParser::RuleComparisonExpr;
}

void minicParser::ComparisonExprContext::copyFrom(ComparisonExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BinaryComparisonContext ------------------------------------------------------------------

std::vector<minicParser::AdditiveExprContext *> minicParser::BinaryComparisonContext::additiveExpr() {
  return getRuleContexts<minicParser::AdditiveExprContext>();
}

minicParser::AdditiveExprContext* minicParser::BinaryComparisonContext::additiveExpr(size_t i) {
  return getRuleContext<minicParser::AdditiveExprContext>(i);
}

minicParser::BinaryComparisonContext::BinaryComparisonContext(ComparisonExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any minicParser::BinaryComparisonContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitBinaryComparison(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ComparisonPassContext ------------------------------------------------------------------

minicParser::AdditiveExprContext* minicParser::ComparisonPassContext::additiveExpr() {
  return getRuleContext<minicParser::AdditiveExprContext>(0);
}

minicParser::ComparisonPassContext::ComparisonPassContext(ComparisonExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any minicParser::ComparisonPassContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitComparisonPass(this);
  else
    return visitor->visitChildren(this);
}
minicParser::ComparisonExprContext* minicParser::comparisonExpr() {
  ComparisonExprContext *_localctx = _tracker.createInstance<ComparisonExprContext>(_ctx, getState());
  enterRule(_localctx, 10, minicParser::RuleComparisonExpr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(102);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<ComparisonExprContext *>(_tracker.createInstance<minicParser::BinaryComparisonContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(97);
      additiveExpr(0);
      setState(98);
      dynamic_cast<BinaryComparisonContext *>(_localctx)->OP = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << minicParser::T__8)
        | (1ULL << minicParser::T__9)
        | (1ULL << minicParser::T__10)
        | (1ULL << minicParser::T__11)
        | (1ULL << minicParser::T__12)
        | (1ULL << minicParser::T__13))) != 0))) {
        dynamic_cast<BinaryComparisonContext *>(_localctx)->OP = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(99);
      additiveExpr(0);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<ComparisonExprContext *>(_tracker.createInstance<minicParser::ComparisonPassContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(101);
      additiveExpr(0);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BooleanExprContext ------------------------------------------------------------------

minicParser::BooleanExprContext::BooleanExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t minicParser::BooleanExprContext::getRuleIndex() const {
  return minicParser::RuleBooleanExpr;
}

void minicParser::BooleanExprContext::copyFrom(BooleanExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BooleanPassContext ------------------------------------------------------------------

minicParser::ComparisonExprContext* minicParser::BooleanPassContext::comparisonExpr() {
  return getRuleContext<minicParser::ComparisonExprContext>(0);
}

minicParser::BooleanPassContext::BooleanPassContext(BooleanExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any minicParser::BooleanPassContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitBooleanPass(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BinaryBooleanContext ------------------------------------------------------------------

std::vector<minicParser::ComparisonExprContext *> minicParser::BinaryBooleanContext::comparisonExpr() {
  return getRuleContexts<minicParser::ComparisonExprContext>();
}

minicParser::ComparisonExprContext* minicParser::BinaryBooleanContext::comparisonExpr(size_t i) {
  return getRuleContext<minicParser::ComparisonExprContext>(i);
}

minicParser::BinaryBooleanContext::BinaryBooleanContext(BooleanExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any minicParser::BinaryBooleanContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitBinaryBoolean(this);
  else
    return visitor->visitChildren(this);
}
minicParser::BooleanExprContext* minicParser::booleanExpr() {
  BooleanExprContext *_localctx = _tracker.createInstance<BooleanExprContext>(_ctx, getState());
  enterRule(_localctx, 12, minicParser::RuleBooleanExpr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(109);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<BooleanExprContext *>(_tracker.createInstance<minicParser::BinaryBooleanContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(104);
      comparisonExpr();
      setState(105);
      dynamic_cast<BinaryBooleanContext *>(_localctx)->OP = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == minicParser::T__14

      || _la == minicParser::T__15)) {
        dynamic_cast<BinaryBooleanContext *>(_localctx)->OP = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(106);
      comparisonExpr();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<BooleanExprContext *>(_tracker.createInstance<minicParser::BooleanPassContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(108);
      comparisonExpr();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

minicParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t minicParser::ExprContext::getRuleIndex() const {
  return minicParser::RuleExpr;
}

void minicParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExprCallContext ------------------------------------------------------------------

minicParser::FunctionCallContext* minicParser::ExprCallContext::functionCall() {
  return getRuleContext<minicParser::FunctionCallContext>(0);
}

minicParser::ExprCallContext::ExprCallContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any minicParser::ExprCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitExprCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprStringContext ------------------------------------------------------------------

tree::TerminalNode* minicParser::ExprStringContext::STRING() {
  return getToken(minicParser::STRING, 0);
}

minicParser::ExprStringContext::ExprStringContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any minicParser::ExprStringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitExprString(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprIdentifierContext ------------------------------------------------------------------

minicParser::IdentifierContext* minicParser::ExprIdentifierContext::identifier() {
  return getRuleContext<minicParser::IdentifierContext>(0);
}

minicParser::ExprIdentifierContext::ExprIdentifierContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any minicParser::ExprIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitExprIdentifier(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprParenthesisContext ------------------------------------------------------------------

minicParser::BooleanExprContext* minicParser::ExprParenthesisContext::booleanExpr() {
  return getRuleContext<minicParser::BooleanExprContext>(0);
}

minicParser::ExprParenthesisContext::ExprParenthesisContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any minicParser::ExprParenthesisContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitExprParenthesis(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprNumberContext ------------------------------------------------------------------

tree::TerminalNode* minicParser::ExprNumberContext::NUMBER() {
  return getToken(minicParser::NUMBER, 0);
}

minicParser::ExprNumberContext::ExprNumberContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any minicParser::ExprNumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitExprNumber(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprLiteralContext ------------------------------------------------------------------

tree::TerminalNode* minicParser::ExprLiteralContext::LITERAL() {
  return getToken(minicParser::LITERAL, 0);
}

minicParser::ExprLiteralContext::ExprLiteralContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any minicParser::ExprLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitExprLiteral(this);
  else
    return visitor->visitChildren(this);
}
minicParser::ExprContext* minicParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 14, minicParser::RuleExpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(120);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<ExprContext *>(_tracker.createInstance<minicParser::ExprParenthesisContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(111);
      match(minicParser::T__16);
      setState(112);
      booleanExpr();
      setState(113);
      match(minicParser::T__17);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<ExprContext *>(_tracker.createInstance<minicParser::ExprCallContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(115);
      functionCall();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<ExprContext *>(_tracker.createInstance<minicParser::ExprIdentifierContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(116);
      identifier();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<ExprContext *>(_tracker.createInstance<minicParser::ExprNumberContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(117);
      match(minicParser::NUMBER);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<ExprContext *>(_tracker.createInstance<minicParser::ExprLiteralContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(118);
      match(minicParser::LITERAL);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<ExprContext *>(_tracker.createInstance<minicParser::ExprStringContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(119);
      match(minicParser::STRING);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignContext ------------------------------------------------------------------

minicParser::AssignContext::AssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

minicParser::IdentifierContext* minicParser::AssignContext::identifier() {
  return getRuleContext<minicParser::IdentifierContext>(0);
}

minicParser::BooleanExprContext* minicParser::AssignContext::booleanExpr() {
  return getRuleContext<minicParser::BooleanExprContext>(0);
}


size_t minicParser::AssignContext::getRuleIndex() const {
  return minicParser::RuleAssign;
}


antlrcpp::Any minicParser::AssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitAssign(this);
  else
    return visitor->visitChildren(this);
}

minicParser::AssignContext* minicParser::assign() {
  AssignContext *_localctx = _tracker.createInstance<AssignContext>(_ctx, getState());
  enterRule(_localctx, 16, minicParser::RuleAssign);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    identifier();
    setState(123);
    match(minicParser::T__18);
    setState(124);
    booleanExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

minicParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

minicParser::TypeContext* minicParser::DeclarationContext::type() {
  return getRuleContext<minicParser::TypeContext>(0);
}

std::vector<minicParser::IdentifierContext *> minicParser::DeclarationContext::identifier() {
  return getRuleContexts<minicParser::IdentifierContext>();
}

minicParser::IdentifierContext* minicParser::DeclarationContext::identifier(size_t i) {
  return getRuleContext<minicParser::IdentifierContext>(i);
}

std::vector<minicParser::AssignContext *> minicParser::DeclarationContext::assign() {
  return getRuleContexts<minicParser::AssignContext>();
}

minicParser::AssignContext* minicParser::DeclarationContext::assign(size_t i) {
  return getRuleContext<minicParser::AssignContext>(i);
}


size_t minicParser::DeclarationContext::getRuleIndex() const {
  return minicParser::RuleDeclaration;
}


antlrcpp::Any minicParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

minicParser::DeclarationContext* minicParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 18, minicParser::RuleDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(126);
    type();
    setState(129);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      setState(127);
      identifier();
      break;
    }

    case 2: {
      setState(128);
      assign();
      break;
    }

    }
    setState(138);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(131);
        match(minicParser::T__19);
        setState(134);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
        case 1: {
          setState(132);
          identifier();
          break;
        }

        case 2: {
          setState(133);
          assign();
          break;
        }

        } 
      }
      setState(140);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

minicParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* minicParser::TypeContext::ID() {
  return getToken(minicParser::ID, 0);
}

std::vector<minicParser::BooleanExprContext *> minicParser::TypeContext::booleanExpr() {
  return getRuleContexts<minicParser::BooleanExprContext>();
}

minicParser::BooleanExprContext* minicParser::TypeContext::booleanExpr(size_t i) {
  return getRuleContext<minicParser::BooleanExprContext>(i);
}


size_t minicParser::TypeContext::getRuleIndex() const {
  return minicParser::RuleType;
}


antlrcpp::Any minicParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

minicParser::TypeContext* minicParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 20, minicParser::RuleType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(154);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case minicParser::T__20:
      case minicParser::T__21:
      case minicParser::T__22:
      case minicParser::T__23:
      case minicParser::T__24: {
        setState(141);
        dynamic_cast<TypeContext *>(_localctx)->PRIMITIVE = _input->LT(1);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << minicParser::T__20)
          | (1ULL << minicParser::T__21)
          | (1ULL << minicParser::T__22)
          | (1ULL << minicParser::T__23)
          | (1ULL << minicParser::T__24))) != 0))) {
          dynamic_cast<TypeContext *>(_localctx)->PRIMITIVE = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(149);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == minicParser::T__25) {
          setState(142);
          match(minicParser::T__25);
          setState(144);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << minicParser::T__1)
            | (1ULL << minicParser::T__2)
            | (1ULL << minicParser::T__3)
            | (1ULL << minicParser::T__4)
            | (1ULL << minicParser::T__5)
            | (1ULL << minicParser::T__16)
            | (1ULL << minicParser::ID)
            | (1ULL << minicParser::NUMBER)
            | (1ULL << minicParser::LITERAL)
            | (1ULL << minicParser::STRING))) != 0)) {
            setState(143);
            booleanExpr();
          }
          setState(146);
          match(minicParser::T__26);
          setState(151);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case minicParser::T__27: {
        setState(152);
        match(minicParser::T__27);
        setState(153);
        match(minicParser::ID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(157);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == minicParser::T__4) {
      setState(156);
      match(minicParser::T__4);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

minicParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t minicParser::StatementContext::getRuleIndex() const {
  return minicParser::RuleStatement;
}

void minicParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DeclarationStatementContext ------------------------------------------------------------------

minicParser::DeclarationContext* minicParser::DeclarationStatementContext::declaration() {
  return getRuleContext<minicParser::DeclarationContext>(0);
}

minicParser::DeclarationStatementContext::DeclarationStatementContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any minicParser::DeclarationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitDeclarationStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprStatementContext ------------------------------------------------------------------

minicParser::BooleanExprContext* minicParser::ExprStatementContext::booleanExpr() {
  return getRuleContext<minicParser::BooleanExprContext>(0);
}

minicParser::ExprStatementContext::ExprStatementContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any minicParser::ExprStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitExprStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RetStatementContext ------------------------------------------------------------------

minicParser::ReturnStatementContext* minicParser::RetStatementContext::returnStatement() {
  return getRuleContext<minicParser::ReturnStatementContext>(0);
}

minicParser::RetStatementContext::RetStatementContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any minicParser::RetStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitRetStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignStatementContext ------------------------------------------------------------------

minicParser::AssignContext* minicParser::AssignStatementContext::assign() {
  return getRuleContext<minicParser::AssignContext>(0);
}

minicParser::AssignStatementContext::AssignStatementContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any minicParser::AssignStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitAssignStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StructDeclarationStatementContext ------------------------------------------------------------------

minicParser::StructDeclarationContext* minicParser::StructDeclarationStatementContext::structDeclaration() {
  return getRuleContext<minicParser::StructDeclarationContext>(0);
}

minicParser::StructDeclarationStatementContext::StructDeclarationStatementContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any minicParser::StructDeclarationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitStructDeclarationStatement(this);
  else
    return visitor->visitChildren(this);
}
minicParser::StatementContext* minicParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 22, minicParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(174);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<minicParser::ExprStatementContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(159);
      booleanExpr();
      setState(160);
      match(minicParser::T__28);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<minicParser::AssignStatementContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(162);
      assign();
      setState(163);
      match(minicParser::T__28);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<minicParser::DeclarationStatementContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(165);
      declaration();
      setState(166);
      match(minicParser::T__28);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<minicParser::RetStatementContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(168);
      returnStatement();
      setState(169);
      match(minicParser::T__28);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<minicParser::StructDeclarationStatementContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(171);
      structDeclaration();
      setState(172);
      match(minicParser::T__28);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NonControlContext ------------------------------------------------------------------

minicParser::NonControlContext::NonControlContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t minicParser::NonControlContext::getRuleIndex() const {
  return minicParser::RuleNonControl;
}

void minicParser::NonControlContext::copyFrom(NonControlContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NonControlStructDeclarationContext ------------------------------------------------------------------

minicParser::StructDeclarationContext* minicParser::NonControlStructDeclarationContext::structDeclaration() {
  return getRuleContext<minicParser::StructDeclarationContext>(0);
}

minicParser::NonControlStructDeclarationContext::NonControlStructDeclarationContext(NonControlContext *ctx) { copyFrom(ctx); }


antlrcpp::Any minicParser::NonControlStructDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitNonControlStructDeclaration(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NonControlAssignContext ------------------------------------------------------------------

minicParser::AssignContext* minicParser::NonControlAssignContext::assign() {
  return getRuleContext<minicParser::AssignContext>(0);
}

minicParser::NonControlAssignContext::NonControlAssignContext(NonControlContext *ctx) { copyFrom(ctx); }


antlrcpp::Any minicParser::NonControlAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitNonControlAssign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NonControlDeclarationContext ------------------------------------------------------------------

minicParser::DeclarationContext* minicParser::NonControlDeclarationContext::declaration() {
  return getRuleContext<minicParser::DeclarationContext>(0);
}

minicParser::NonControlDeclarationContext::NonControlDeclarationContext(NonControlContext *ctx) { copyFrom(ctx); }


antlrcpp::Any minicParser::NonControlDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitNonControlDeclaration(this);
  else
    return visitor->visitChildren(this);
}
minicParser::NonControlContext* minicParser::nonControl() {
  NonControlContext *_localctx = _tracker.createInstance<NonControlContext>(_ctx, getState());
  enterRule(_localctx, 24, minicParser::RuleNonControl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(179);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<NonControlContext *>(_tracker.createInstance<minicParser::NonControlDeclarationContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(176);
      declaration();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<NonControlContext *>(_tracker.createInstance<minicParser::NonControlAssignContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(177);
      assign();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<NonControlContext *>(_tracker.createInstance<minicParser::NonControlStructDeclarationContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(178);
      structDeclaration();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfElseContext ------------------------------------------------------------------

minicParser::IfElseContext::IfElseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

minicParser::BooleanExprContext* minicParser::IfElseContext::booleanExpr() {
  return getRuleContext<minicParser::BooleanExprContext>(0);
}

std::vector<minicParser::BlockContext *> minicParser::IfElseContext::block() {
  return getRuleContexts<minicParser::BlockContext>();
}

minicParser::BlockContext* minicParser::IfElseContext::block(size_t i) {
  return getRuleContext<minicParser::BlockContext>(i);
}


size_t minicParser::IfElseContext::getRuleIndex() const {
  return minicParser::RuleIfElse;
}


antlrcpp::Any minicParser::IfElseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitIfElse(this);
  else
    return visitor->visitChildren(this);
}

minicParser::IfElseContext* minicParser::ifElse() {
  IfElseContext *_localctx = _tracker.createInstance<IfElseContext>(_ctx, getState());
  enterRule(_localctx, 26, minicParser::RuleIfElse);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(181);
    match(minicParser::T__29);
    setState(182);
    booleanExpr();
    setState(183);
    block();
    setState(186);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == minicParser::T__30) {
      setState(184);
      match(minicParser::T__30);
      setState(185);
      block();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TernaryContext ------------------------------------------------------------------

minicParser::TernaryContext::TernaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<minicParser::BooleanExprContext *> minicParser::TernaryContext::booleanExpr() {
  return getRuleContexts<minicParser::BooleanExprContext>();
}

minicParser::BooleanExprContext* minicParser::TernaryContext::booleanExpr(size_t i) {
  return getRuleContext<minicParser::BooleanExprContext>(i);
}


size_t minicParser::TernaryContext::getRuleIndex() const {
  return minicParser::RuleTernary;
}


antlrcpp::Any minicParser::TernaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitTernary(this);
  else
    return visitor->visitChildren(this);
}

minicParser::TernaryContext* minicParser::ternary() {
  TernaryContext *_localctx = _tracker.createInstance<TernaryContext>(_ctx, getState());
  enterRule(_localctx, 28, minicParser::RuleTernary);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(188);
    booleanExpr();
    setState(189);
    match(minicParser::T__31);
    setState(190);
    booleanExpr();
    setState(191);
    match(minicParser::T__32);
    setState(192);
    booleanExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ControlContext ------------------------------------------------------------------

minicParser::ControlContext::ControlContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

minicParser::ForStatementContext* minicParser::ControlContext::forStatement() {
  return getRuleContext<minicParser::ForStatementContext>(0);
}

minicParser::WhileStatementContext* minicParser::ControlContext::whileStatement() {
  return getRuleContext<minicParser::WhileStatementContext>(0);
}

minicParser::IfElseContext* minicParser::ControlContext::ifElse() {
  return getRuleContext<minicParser::IfElseContext>(0);
}


size_t minicParser::ControlContext::getRuleIndex() const {
  return minicParser::RuleControl;
}


antlrcpp::Any minicParser::ControlContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitControl(this);
  else
    return visitor->visitChildren(this);
}

minicParser::ControlContext* minicParser::control() {
  ControlContext *_localctx = _tracker.createInstance<ControlContext>(_ctx, getState());
  enterRule(_localctx, 30, minicParser::RuleControl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(197);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case minicParser::T__33: {
        enterOuterAlt(_localctx, 1);
        setState(194);
        forStatement();
        break;
      }

      case minicParser::T__34: {
        enterOuterAlt(_localctx, 2);
        setState(195);
        whileStatement();
        break;
      }

      case minicParser::T__29: {
        enterOuterAlt(_localctx, 3);
        setState(196);
        ifElse();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStatementContext ------------------------------------------------------------------

minicParser::ForStatementContext::ForStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<minicParser::NonControlContext *> minicParser::ForStatementContext::nonControl() {
  return getRuleContexts<minicParser::NonControlContext>();
}

minicParser::NonControlContext* minicParser::ForStatementContext::nonControl(size_t i) {
  return getRuleContext<minicParser::NonControlContext>(i);
}

minicParser::BooleanExprContext* minicParser::ForStatementContext::booleanExpr() {
  return getRuleContext<minicParser::BooleanExprContext>(0);
}

minicParser::BlockContext* minicParser::ForStatementContext::block() {
  return getRuleContext<minicParser::BlockContext>(0);
}


size_t minicParser::ForStatementContext::getRuleIndex() const {
  return minicParser::RuleForStatement;
}


antlrcpp::Any minicParser::ForStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitForStatement(this);
  else
    return visitor->visitChildren(this);
}

minicParser::ForStatementContext* minicParser::forStatement() {
  ForStatementContext *_localctx = _tracker.createInstance<ForStatementContext>(_ctx, getState());
  enterRule(_localctx, 32, minicParser::RuleForStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(199);
    match(minicParser::T__33);
    setState(200);
    match(minicParser::T__16);
    setState(201);
    nonControl();
    setState(202);
    match(minicParser::T__28);
    setState(203);
    booleanExpr();
    setState(204);
    match(minicParser::T__28);
    setState(205);
    nonControl();
    setState(206);
    match(minicParser::T__17);
    setState(207);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStatementContext ------------------------------------------------------------------

minicParser::WhileStatementContext::WhileStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

minicParser::BooleanExprContext* minicParser::WhileStatementContext::booleanExpr() {
  return getRuleContext<minicParser::BooleanExprContext>(0);
}

minicParser::BlockContext* minicParser::WhileStatementContext::block() {
  return getRuleContext<minicParser::BlockContext>(0);
}


size_t minicParser::WhileStatementContext::getRuleIndex() const {
  return minicParser::RuleWhileStatement;
}


antlrcpp::Any minicParser::WhileStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitWhileStatement(this);
  else
    return visitor->visitChildren(this);
}

minicParser::WhileStatementContext* minicParser::whileStatement() {
  WhileStatementContext *_localctx = _tracker.createInstance<WhileStatementContext>(_ctx, getState());
  enterRule(_localctx, 34, minicParser::RuleWhileStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(209);
    match(minicParser::T__34);
    setState(210);
    match(minicParser::T__16);
    setState(211);
    booleanExpr();
    setState(212);
    match(minicParser::T__17);
    setState(213);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

minicParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

minicParser::BlockContext* minicParser::ProgramContext::block() {
  return getRuleContext<minicParser::BlockContext>(0);
}

minicParser::StatementContext* minicParser::ProgramContext::statement() {
  return getRuleContext<minicParser::StatementContext>(0);
}

minicParser::ControlContext* minicParser::ProgramContext::control() {
  return getRuleContext<minicParser::ControlContext>(0);
}

minicParser::FunctionDeclarationContext* minicParser::ProgramContext::functionDeclaration() {
  return getRuleContext<minicParser::FunctionDeclarationContext>(0);
}

minicParser::FunctionCallContext* minicParser::ProgramContext::functionCall() {
  return getRuleContext<minicParser::FunctionCallContext>(0);
}

minicParser::IncludeContext* minicParser::ProgramContext::include() {
  return getRuleContext<minicParser::IncludeContext>(0);
}


size_t minicParser::ProgramContext::getRuleIndex() const {
  return minicParser::RuleProgram;
}


antlrcpp::Any minicParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

minicParser::ProgramContext* minicParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 36, minicParser::RuleProgram);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(221);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(215);
      block();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(216);
      statement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(217);
      control();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(218);
      functionDeclaration();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(219);
      functionCall();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(220);
      include();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

minicParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<minicParser::ProgramContext *> minicParser::BlockContext::program() {
  return getRuleContexts<minicParser::ProgramContext>();
}

minicParser::ProgramContext* minicParser::BlockContext::program(size_t i) {
  return getRuleContext<minicParser::ProgramContext>(i);
}


size_t minicParser::BlockContext::getRuleIndex() const {
  return minicParser::RuleBlock;
}


antlrcpp::Any minicParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

minicParser::BlockContext* minicParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 38, minicParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(223);
    match(minicParser::T__35);
    setState(227);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << minicParser::T__1)
      | (1ULL << minicParser::T__2)
      | (1ULL << minicParser::T__3)
      | (1ULL << minicParser::T__4)
      | (1ULL << minicParser::T__5)
      | (1ULL << minicParser::T__16)
      | (1ULL << minicParser::T__20)
      | (1ULL << minicParser::T__21)
      | (1ULL << minicParser::T__22)
      | (1ULL << minicParser::T__23)
      | (1ULL << minicParser::T__24)
      | (1ULL << minicParser::T__27)
      | (1ULL << minicParser::T__29)
      | (1ULL << minicParser::T__33)
      | (1ULL << minicParser::T__34)
      | (1ULL << minicParser::T__35)
      | (1ULL << minicParser::T__37)
      | (1ULL << minicParser::T__38)
      | (1ULL << minicParser::ID)
      | (1ULL << minicParser::NUMBER)
      | (1ULL << minicParser::LITERAL)
      | (1ULL << minicParser::STRING))) != 0)) {
      setState(224);
      program();
      setState(229);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(230);
    match(minicParser::T__36);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamListContext ------------------------------------------------------------------

minicParser::ParamListContext::ParamListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<minicParser::DeclarationContext *> minicParser::ParamListContext::declaration() {
  return getRuleContexts<minicParser::DeclarationContext>();
}

minicParser::DeclarationContext* minicParser::ParamListContext::declaration(size_t i) {
  return getRuleContext<minicParser::DeclarationContext>(i);
}


size_t minicParser::ParamListContext::getRuleIndex() const {
  return minicParser::RuleParamList;
}


antlrcpp::Any minicParser::ParamListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitParamList(this);
  else
    return visitor->visitChildren(this);
}

minicParser::ParamListContext* minicParser::paramList() {
  ParamListContext *_localctx = _tracker.createInstance<ParamListContext>(_ctx, getState());
  enterRule(_localctx, 40, minicParser::RuleParamList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(232);
    declaration();
    setState(237);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == minicParser::T__19) {
      setState(233);
      match(minicParser::T__19);
      setState(234);
      declaration();
      setState(239);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgListContext ------------------------------------------------------------------

minicParser::ArgListContext::ArgListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<minicParser::BooleanExprContext *> minicParser::ArgListContext::booleanExpr() {
  return getRuleContexts<minicParser::BooleanExprContext>();
}

minicParser::BooleanExprContext* minicParser::ArgListContext::booleanExpr(size_t i) {
  return getRuleContext<minicParser::BooleanExprContext>(i);
}


size_t minicParser::ArgListContext::getRuleIndex() const {
  return minicParser::RuleArgList;
}


antlrcpp::Any minicParser::ArgListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitArgList(this);
  else
    return visitor->visitChildren(this);
}

minicParser::ArgListContext* minicParser::argList() {
  ArgListContext *_localctx = _tracker.createInstance<ArgListContext>(_ctx, getState());
  enterRule(_localctx, 42, minicParser::RuleArgList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(240);
    booleanExpr();
    setState(245);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == minicParser::T__19) {
      setState(241);
      match(minicParser::T__19);
      setState(242);
      booleanExpr();
      setState(247);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclarationContext ------------------------------------------------------------------

minicParser::FunctionDeclarationContext::FunctionDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

minicParser::TypeContext* minicParser::FunctionDeclarationContext::type() {
  return getRuleContext<minicParser::TypeContext>(0);
}

tree::TerminalNode* minicParser::FunctionDeclarationContext::ID() {
  return getToken(minicParser::ID, 0);
}

minicParser::BlockContext* minicParser::FunctionDeclarationContext::block() {
  return getRuleContext<minicParser::BlockContext>(0);
}

minicParser::ParamListContext* minicParser::FunctionDeclarationContext::paramList() {
  return getRuleContext<minicParser::ParamListContext>(0);
}


size_t minicParser::FunctionDeclarationContext::getRuleIndex() const {
  return minicParser::RuleFunctionDeclaration;
}


antlrcpp::Any minicParser::FunctionDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitFunctionDeclaration(this);
  else
    return visitor->visitChildren(this);
}

minicParser::FunctionDeclarationContext* minicParser::functionDeclaration() {
  FunctionDeclarationContext *_localctx = _tracker.createInstance<FunctionDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 44, minicParser::RuleFunctionDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(248);
    type();
    setState(249);
    match(minicParser::ID);
    setState(250);
    match(minicParser::T__16);
    setState(252);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << minicParser::T__20)
      | (1ULL << minicParser::T__21)
      | (1ULL << minicParser::T__22)
      | (1ULL << minicParser::T__23)
      | (1ULL << minicParser::T__24)
      | (1ULL << minicParser::T__27))) != 0)) {
      setState(251);
      paramList();
    }
    setState(254);
    match(minicParser::T__17);
    setState(255);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallContext ------------------------------------------------------------------

minicParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* minicParser::FunctionCallContext::ID() {
  return getToken(minicParser::ID, 0);
}

minicParser::ArgListContext* minicParser::FunctionCallContext::argList() {
  return getRuleContext<minicParser::ArgListContext>(0);
}


size_t minicParser::FunctionCallContext::getRuleIndex() const {
  return minicParser::RuleFunctionCall;
}


antlrcpp::Any minicParser::FunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitFunctionCall(this);
  else
    return visitor->visitChildren(this);
}

minicParser::FunctionCallContext* minicParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 46, minicParser::RuleFunctionCall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(257);
    match(minicParser::ID);
    setState(258);
    match(minicParser::T__16);
    setState(260);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << minicParser::T__1)
      | (1ULL << minicParser::T__2)
      | (1ULL << minicParser::T__3)
      | (1ULL << minicParser::T__4)
      | (1ULL << minicParser::T__5)
      | (1ULL << minicParser::T__16)
      | (1ULL << minicParser::ID)
      | (1ULL << minicParser::NUMBER)
      | (1ULL << minicParser::LITERAL)
      | (1ULL << minicParser::STRING))) != 0)) {
      setState(259);
      argList();
    }
    setState(262);
    match(minicParser::T__17);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

minicParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

minicParser::BooleanExprContext* minicParser::ReturnStatementContext::booleanExpr() {
  return getRuleContext<minicParser::BooleanExprContext>(0);
}


size_t minicParser::ReturnStatementContext::getRuleIndex() const {
  return minicParser::RuleReturnStatement;
}


antlrcpp::Any minicParser::ReturnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitReturnStatement(this);
  else
    return visitor->visitChildren(this);
}

minicParser::ReturnStatementContext* minicParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 48, minicParser::RuleReturnStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(264);
    match(minicParser::T__37);
    setState(266);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << minicParser::T__1)
      | (1ULL << minicParser::T__2)
      | (1ULL << minicParser::T__3)
      | (1ULL << minicParser::T__4)
      | (1ULL << minicParser::T__5)
      | (1ULL << minicParser::T__16)
      | (1ULL << minicParser::ID)
      | (1ULL << minicParser::NUMBER)
      | (1ULL << minicParser::LITERAL)
      | (1ULL << minicParser::STRING))) != 0)) {
      setState(265);
      booleanExpr();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructDeclarationContext ------------------------------------------------------------------

minicParser::StructDeclarationContext::StructDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* minicParser::StructDeclarationContext::ID() {
  return getToken(minicParser::ID, 0);
}

minicParser::ParamListContext* minicParser::StructDeclarationContext::paramList() {
  return getRuleContext<minicParser::ParamListContext>(0);
}


size_t minicParser::StructDeclarationContext::getRuleIndex() const {
  return minicParser::RuleStructDeclaration;
}


antlrcpp::Any minicParser::StructDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitStructDeclaration(this);
  else
    return visitor->visitChildren(this);
}

minicParser::StructDeclarationContext* minicParser::structDeclaration() {
  StructDeclarationContext *_localctx = _tracker.createInstance<StructDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 50, minicParser::RuleStructDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(268);
    match(minicParser::T__27);
    setState(269);
    match(minicParser::ID);
    setState(270);
    match(minicParser::T__35);
    setState(271);
    paramList();
    setState(272);
    match(minicParser::T__36);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IncludeContext ------------------------------------------------------------------

minicParser::IncludeContext::IncludeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> minicParser::IncludeContext::ID() {
  return getTokens(minicParser::ID);
}

tree::TerminalNode* minicParser::IncludeContext::ID(size_t i) {
  return getToken(minicParser::ID, i);
}


size_t minicParser::IncludeContext::getRuleIndex() const {
  return minicParser::RuleInclude;
}


antlrcpp::Any minicParser::IncludeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitInclude(this);
  else
    return visitor->visitChildren(this);
}

minicParser::IncludeContext* minicParser::include() {
  IncludeContext *_localctx = _tracker.createInstance<IncludeContext>(_ctx, getState());
  enterRule(_localctx, 52, minicParser::RuleInclude);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(274);
    match(minicParser::T__38);
    setState(275);
    match(minicParser::T__39);
    setState(276);
    match(minicParser::T__11);
    setState(281);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(277);
        match(minicParser::ID);
        setState(278);
        match(minicParser::T__6); 
      }
      setState(283);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    }
    setState(284);
    match(minicParser::ID);
    setState(285);
    match(minicParser::T__40);
    setState(286);
    match(minicParser::T__12);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierContext ------------------------------------------------------------------

minicParser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> minicParser::IdentifierContext::ID() {
  return getTokens(minicParser::ID);
}

tree::TerminalNode* minicParser::IdentifierContext::ID(size_t i) {
  return getToken(minicParser::ID, i);
}

std::vector<minicParser::ComparisonExprContext *> minicParser::IdentifierContext::comparisonExpr() {
  return getRuleContexts<minicParser::ComparisonExprContext>();
}

minicParser::ComparisonExprContext* minicParser::IdentifierContext::comparisonExpr(size_t i) {
  return getRuleContext<minicParser::ComparisonExprContext>(i);
}

std::vector<minicParser::TernaryContext *> minicParser::IdentifierContext::ternary() {
  return getRuleContexts<minicParser::TernaryContext>();
}

minicParser::TernaryContext* minicParser::IdentifierContext::ternary(size_t i) {
  return getRuleContext<minicParser::TernaryContext>(i);
}


size_t minicParser::IdentifierContext::getRuleIndex() const {
  return minicParser::RuleIdentifier;
}


antlrcpp::Any minicParser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<minicVisitor*>(visitor))
    return parserVisitor->visitIdentifier(this);
  else
    return visitor->visitChildren(this);
}

minicParser::IdentifierContext* minicParser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 54, minicParser::RuleIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(288);
    match(minicParser::ID);
    setState(300);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(298);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case minicParser::T__25: {
            setState(289);
            match(minicParser::T__25);
            setState(292);
            _errHandler->sync(this);
            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
            case 1: {
              setState(290);
              comparisonExpr();
              break;
            }

            case 2: {
              setState(291);
              ternary();
              break;
            }

            }
            setState(294);
            match(minicParser::T__26);
            break;
          }

          case minicParser::T__41: {
            setState(296);
            match(minicParser::T__41);
            setState(297);
            match(minicParser::ID);
            break;
          }

        default:
          throw NoViableAltException(this);
        } 
      }
      setState(302);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool minicParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 3: return multiplicativeExprSempred(dynamic_cast<MultiplicativeExprContext *>(context), predicateIndex);
    case 4: return additiveExprSempred(dynamic_cast<AdditiveExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool minicParser::multiplicativeExprSempred(MultiplicativeExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool minicParser::additiveExprSempred(AdditiveExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> minicParser::_decisionToDFA;
atn::PredictionContextCache minicParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN minicParser::_atn;
std::vector<uint16_t> minicParser::_serializedATN;

std::vector<std::string> minicParser::_ruleNames = {
  "prog", "arrowExpr", "unaryExpr", "multiplicativeExpr", "additiveExpr", 
  "comparisonExpr", "booleanExpr", "expr", "assign", "declaration", "type", 
  "statement", "nonControl", "ifElse", "ternary", "control", "forStatement", 
  "whileStatement", "program", "block", "paramList", "argList", "functionDeclaration", 
  "functionCall", "returnStatement", "structDeclaration", "include", "identifier"
};

std::vector<std::string> minicParser::_literalNames = {
  "", "'->'", "'+'", "'-'", "'&'", "'*'", "'!'", "'/'", "'mod'", "'=='", 
  "'<='", "'>='", "'<'", "'>'", "'!='", "'and'", "'or'", "'('", "')'", "'='", 
  "','", "'integer'", "'float'", "'char'", "'bool'", "'void'", "'['", "']'", 
  "'struct'", "';'", "'if'", "'else'", "'?'", "':'", "'for'", "'while'", 
  "'{'", "'}'", "'return'", "'#'", "'include'", "'.h'", "'.'"
};

std::vector<std::string> minicParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "ID", "NUMBER", "LITERAL", "STRING", "COMMENT", 
  "NS"
};

dfa::Vocabulary minicParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> minicParser::_tokenNames;

minicParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x32, 0x132, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x3, 0x2, 0x6, 0x2, 0x3c, 
    0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x3d, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x47, 0xa, 0x3, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x4c, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x54, 0xa, 0x5, 0xc, 0x5, 
    0xe, 0x5, 0x57, 0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x7, 0x6, 0x5f, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x62, 0xb, 
    0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x69, 
    0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 
    0x70, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x7b, 0xa, 0x9, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 
    0x84, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x89, 0xa, 0xb, 
    0x7, 0xb, 0x8b, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x8e, 0xb, 0xb, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x93, 0xa, 0xc, 0x3, 0xc, 0x7, 0xc, 0x96, 
    0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x99, 0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 
    0xc, 0x9d, 0xa, 0xc, 0x3, 0xc, 0x5, 0xc, 0xa0, 0xa, 0xc, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 
    0xd, 0xb1, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xb6, 0xa, 
    0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xbd, 
    0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xc8, 0xa, 0x11, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0xe0, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 
    0x7, 0x15, 0xe4, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0xe7, 0xb, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x7, 0x16, 0xee, 0xa, 
    0x16, 0xc, 0x16, 0xe, 0x16, 0xf1, 0xb, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 
    0x17, 0x7, 0x17, 0xf6, 0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 0xf9, 0xb, 0x17, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0xff, 0xa, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 
    0x19, 0x107, 0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 
    0x5, 0x1a, 0x10d, 0xa, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
    0x1c, 0x7, 0x1c, 0x11a, 0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 0x11d, 0xb, 
    0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x127, 0xa, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x7, 0x1d, 0x12d, 0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 
    0x130, 0xb, 0x1d, 0x3, 0x1d, 0x2, 0x4, 0x8, 0xa, 0x1e, 0x2, 0x4, 0x6, 
    0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
    0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 
    0x38, 0x2, 0x8, 0x3, 0x2, 0x4, 0x8, 0x4, 0x2, 0x7, 0x7, 0x9, 0xa, 0x3, 
    0x2, 0x4, 0x5, 0x3, 0x2, 0xb, 0x10, 0x3, 0x2, 0x11, 0x12, 0x3, 0x2, 
    0x17, 0x1b, 0x2, 0x140, 0x2, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x4, 0x46, 0x3, 
    0x2, 0x2, 0x2, 0x6, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x8, 0x4d, 0x3, 0x2, 0x2, 
    0x2, 0xa, 0x58, 0x3, 0x2, 0x2, 0x2, 0xc, 0x68, 0x3, 0x2, 0x2, 0x2, 0xe, 
    0x6f, 0x3, 0x2, 0x2, 0x2, 0x10, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x12, 0x7c, 
    0x3, 0x2, 0x2, 0x2, 0x14, 0x80, 0x3, 0x2, 0x2, 0x2, 0x16, 0x9c, 0x3, 
    0x2, 0x2, 0x2, 0x18, 0xb0, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xb5, 0x3, 0x2, 
    0x2, 0x2, 0x1c, 0xb7, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xbe, 0x3, 0x2, 0x2, 
    0x2, 0x20, 0xc7, 0x3, 0x2, 0x2, 0x2, 0x22, 0xc9, 0x3, 0x2, 0x2, 0x2, 
    0x24, 0xd3, 0x3, 0x2, 0x2, 0x2, 0x26, 0xdf, 0x3, 0x2, 0x2, 0x2, 0x28, 
    0xe1, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xea, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xf2, 
    0x3, 0x2, 0x2, 0x2, 0x2e, 0xfa, 0x3, 0x2, 0x2, 0x2, 0x30, 0x103, 0x3, 
    0x2, 0x2, 0x2, 0x32, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x34, 0x10e, 0x3, 0x2, 
    0x2, 0x2, 0x36, 0x114, 0x3, 0x2, 0x2, 0x2, 0x38, 0x122, 0x3, 0x2, 0x2, 
    0x2, 0x3a, 0x3c, 0x5, 0x26, 0x14, 0x2, 0x3b, 0x3a, 0x3, 0x2, 0x2, 0x2, 
    0x3c, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3d, 
    0x3e, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 
    0x7, 0x2, 0x2, 0x3, 0x40, 0x3, 0x3, 0x2, 0x2, 0x2, 0x41, 0x47, 0x5, 
    0x10, 0x9, 0x2, 0x42, 0x43, 0x5, 0x10, 0x9, 0x2, 0x43, 0x44, 0x7, 0x3, 
    0x2, 0x2, 0x44, 0x45, 0x5, 0x10, 0x9, 0x2, 0x45, 0x47, 0x3, 0x2, 0x2, 
    0x2, 0x46, 0x41, 0x3, 0x2, 0x2, 0x2, 0x46, 0x42, 0x3, 0x2, 0x2, 0x2, 
    0x47, 0x5, 0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x9, 0x2, 0x2, 0x2, 0x49, 
    0x4c, 0x5, 0x4, 0x3, 0x2, 0x4a, 0x4c, 0x5, 0x4, 0x3, 0x2, 0x4b, 0x48, 
    0x3, 0x2, 0x2, 0x2, 0x4b, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x7, 0x3, 
    0x2, 0x2, 0x2, 0x4d, 0x4e, 0x8, 0x5, 0x1, 0x2, 0x4e, 0x4f, 0x5, 0x6, 
    0x4, 0x2, 0x4f, 0x55, 0x3, 0x2, 0x2, 0x2, 0x50, 0x51, 0xc, 0x3, 0x2, 
    0x2, 0x51, 0x52, 0x9, 0x3, 0x2, 0x2, 0x52, 0x54, 0x5, 0x6, 0x4, 0x2, 
    0x53, 0x50, 0x3, 0x2, 0x2, 0x2, 0x54, 0x57, 0x3, 0x2, 0x2, 0x2, 0x55, 
    0x53, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x3, 0x2, 0x2, 0x2, 0x56, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x57, 0x55, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x8, 
    0x6, 0x1, 0x2, 0x59, 0x5a, 0x5, 0x8, 0x5, 0x2, 0x5a, 0x60, 0x3, 0x2, 
    0x2, 0x2, 0x5b, 0x5c, 0xc, 0x3, 0x2, 0x2, 0x5c, 0x5d, 0x9, 0x4, 0x2, 
    0x2, 0x5d, 0x5f, 0x5, 0x8, 0x5, 0x2, 0x5e, 0x5b, 0x3, 0x2, 0x2, 0x2, 
    0x5f, 0x62, 0x3, 0x2, 0x2, 0x2, 0x60, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x60, 
    0x61, 0x3, 0x2, 0x2, 0x2, 0x61, 0xb, 0x3, 0x2, 0x2, 0x2, 0x62, 0x60, 
    0x3, 0x2, 0x2, 0x2, 0x63, 0x64, 0x5, 0xa, 0x6, 0x2, 0x64, 0x65, 0x9, 
    0x5, 0x2, 0x2, 0x65, 0x66, 0x5, 0xa, 0x6, 0x2, 0x66, 0x69, 0x3, 0x2, 
    0x2, 0x2, 0x67, 0x69, 0x5, 0xa, 0x6, 0x2, 0x68, 0x63, 0x3, 0x2, 0x2, 
    0x2, 0x68, 0x67, 0x3, 0x2, 0x2, 0x2, 0x69, 0xd, 0x3, 0x2, 0x2, 0x2, 
    0x6a, 0x6b, 0x5, 0xc, 0x7, 0x2, 0x6b, 0x6c, 0x9, 0x6, 0x2, 0x2, 0x6c, 
    0x6d, 0x5, 0xc, 0x7, 0x2, 0x6d, 0x70, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x70, 
    0x5, 0xc, 0x7, 0x2, 0x6f, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x6e, 0x3, 
    0x2, 0x2, 0x2, 0x70, 0xf, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 0x7, 0x13, 
    0x2, 0x2, 0x72, 0x73, 0x5, 0xe, 0x8, 0x2, 0x73, 0x74, 0x7, 0x14, 0x2, 
    0x2, 0x74, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x75, 0x7b, 0x5, 0x30, 0x19, 0x2, 
    0x76, 0x7b, 0x5, 0x38, 0x1d, 0x2, 0x77, 0x7b, 0x7, 0x2e, 0x2, 0x2, 0x78, 
    0x7b, 0x7, 0x2f, 0x2, 0x2, 0x79, 0x7b, 0x7, 0x30, 0x2, 0x2, 0x7a, 0x71, 
    0x3, 0x2, 0x2, 0x2, 0x7a, 0x75, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x76, 0x3, 
    0x2, 0x2, 0x2, 0x7a, 0x77, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x78, 0x3, 0x2, 
    0x2, 0x2, 0x7a, 0x79, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x11, 0x3, 0x2, 0x2, 
    0x2, 0x7c, 0x7d, 0x5, 0x38, 0x1d, 0x2, 0x7d, 0x7e, 0x7, 0x15, 0x2, 0x2, 
    0x7e, 0x7f, 0x5, 0xe, 0x8, 0x2, 0x7f, 0x13, 0x3, 0x2, 0x2, 0x2, 0x80, 
    0x83, 0x5, 0x16, 0xc, 0x2, 0x81, 0x84, 0x5, 0x38, 0x1d, 0x2, 0x82, 0x84, 
    0x5, 0x12, 0xa, 0x2, 0x83, 0x81, 0x3, 0x2, 0x2, 0x2, 0x83, 0x82, 0x3, 
    0x2, 0x2, 0x2, 0x84, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x85, 0x88, 0x7, 0x16, 
    0x2, 0x2, 0x86, 0x89, 0x5, 0x38, 0x1d, 0x2, 0x87, 0x89, 0x5, 0x12, 0xa, 
    0x2, 0x88, 0x86, 0x3, 0x2, 0x2, 0x2, 0x88, 0x87, 0x3, 0x2, 0x2, 0x2, 
    0x89, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x85, 0x3, 0x2, 0x2, 0x2, 0x8b, 
    0x8e, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 
    0x3, 0x2, 0x2, 0x2, 0x8d, 0x15, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8c, 0x3, 
    0x2, 0x2, 0x2, 0x8f, 0x97, 0x9, 0x7, 0x2, 0x2, 0x90, 0x92, 0x7, 0x1c, 
    0x2, 0x2, 0x91, 0x93, 0x5, 0xe, 0x8, 0x2, 0x92, 0x91, 0x3, 0x2, 0x2, 
    0x2, 0x92, 0x93, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x3, 0x2, 0x2, 0x2, 
    0x94, 0x96, 0x7, 0x1d, 0x2, 0x2, 0x95, 0x90, 0x3, 0x2, 0x2, 0x2, 0x96, 
    0x99, 0x3, 0x2, 0x2, 0x2, 0x97, 0x95, 0x3, 0x2, 0x2, 0x2, 0x97, 0x98, 
    0x3, 0x2, 0x2, 0x2, 0x98, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x99, 0x97, 0x3, 
    0x2, 0x2, 0x2, 0x9a, 0x9b, 0x7, 0x1e, 0x2, 0x2, 0x9b, 0x9d, 0x7, 0x2d, 
    0x2, 0x2, 0x9c, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9a, 0x3, 0x2, 0x2, 
    0x2, 0x9d, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x9e, 0xa0, 0x7, 0x7, 0x2, 0x2, 
    0x9f, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa0, 
    0x17, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x5, 0xe, 0x8, 0x2, 0xa2, 0xa3, 
    0x7, 0x1f, 0x2, 0x2, 0xa3, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 0x5, 
    0x12, 0xa, 0x2, 0xa5, 0xa6, 0x7, 0x1f, 0x2, 0x2, 0xa6, 0xb1, 0x3, 0x2, 
    0x2, 0x2, 0xa7, 0xa8, 0x5, 0x14, 0xb, 0x2, 0xa8, 0xa9, 0x7, 0x1f, 0x2, 
    0x2, 0xa9, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 0x5, 0x32, 0x1a, 0x2, 
    0xab, 0xac, 0x7, 0x1f, 0x2, 0x2, 0xac, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xad, 
    0xae, 0x5, 0x34, 0x1b, 0x2, 0xae, 0xaf, 0x7, 0x1f, 0x2, 0x2, 0xaf, 0xb1, 
    0x3, 0x2, 0x2, 0x2, 0xb0, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xa4, 0x3, 
    0x2, 0x2, 0x2, 0xb0, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xaa, 0x3, 0x2, 
    0x2, 0x2, 0xb0, 0xad, 0x3, 0x2, 0x2, 0x2, 0xb1, 0x19, 0x3, 0x2, 0x2, 
    0x2, 0xb2, 0xb6, 0x5, 0x14, 0xb, 0x2, 0xb3, 0xb6, 0x5, 0x12, 0xa, 0x2, 
    0xb4, 0xb6, 0x5, 0x34, 0x1b, 0x2, 0xb5, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb5, 
    0xb3, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb6, 0x1b, 
    0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x7, 0x20, 0x2, 0x2, 0xb8, 0xb9, 0x5, 
    0xe, 0x8, 0x2, 0xb9, 0xbc, 0x5, 0x28, 0x15, 0x2, 0xba, 0xbb, 0x7, 0x21, 
    0x2, 0x2, 0xbb, 0xbd, 0x5, 0x28, 0x15, 0x2, 0xbc, 0xba, 0x3, 0x2, 0x2, 
    0x2, 0xbc, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbd, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0xbe, 0xbf, 0x5, 0xe, 0x8, 0x2, 0xbf, 0xc0, 0x7, 0x22, 0x2, 0x2, 0xc0, 
    0xc1, 0x5, 0xe, 0x8, 0x2, 0xc1, 0xc2, 0x7, 0x23, 0x2, 0x2, 0xc2, 0xc3, 
    0x5, 0xe, 0x8, 0x2, 0xc3, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc8, 0x5, 
    0x22, 0x12, 0x2, 0xc5, 0xc8, 0x5, 0x24, 0x13, 0x2, 0xc6, 0xc8, 0x5, 
    0x1c, 0xf, 0x2, 0xc7, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc5, 0x3, 0x2, 
    0x2, 0x2, 0xc7, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc8, 0x21, 0x3, 0x2, 0x2, 
    0x2, 0xc9, 0xca, 0x7, 0x24, 0x2, 0x2, 0xca, 0xcb, 0x7, 0x13, 0x2, 0x2, 
    0xcb, 0xcc, 0x5, 0x1a, 0xe, 0x2, 0xcc, 0xcd, 0x7, 0x1f, 0x2, 0x2, 0xcd, 
    0xce, 0x5, 0xe, 0x8, 0x2, 0xce, 0xcf, 0x7, 0x1f, 0x2, 0x2, 0xcf, 0xd0, 
    0x5, 0x1a, 0xe, 0x2, 0xd0, 0xd1, 0x7, 0x14, 0x2, 0x2, 0xd1, 0xd2, 0x5, 
    0x28, 0x15, 0x2, 0xd2, 0x23, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x7, 0x25, 
    0x2, 0x2, 0xd4, 0xd5, 0x7, 0x13, 0x2, 0x2, 0xd5, 0xd6, 0x5, 0xe, 0x8, 
    0x2, 0xd6, 0xd7, 0x7, 0x14, 0x2, 0x2, 0xd7, 0xd8, 0x5, 0x28, 0x15, 0x2, 
    0xd8, 0x25, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xe0, 0x5, 0x28, 0x15, 0x2, 0xda, 
    0xe0, 0x5, 0x18, 0xd, 0x2, 0xdb, 0xe0, 0x5, 0x20, 0x11, 0x2, 0xdc, 0xe0, 
    0x5, 0x2e, 0x18, 0x2, 0xdd, 0xe0, 0x5, 0x30, 0x19, 0x2, 0xde, 0xe0, 
    0x5, 0x36, 0x1c, 0x2, 0xdf, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xda, 0x3, 
    0x2, 0x2, 0x2, 0xdf, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xdc, 0x3, 0x2, 
    0x2, 0x2, 0xdf, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xde, 0x3, 0x2, 0x2, 
    0x2, 0xe0, 0x27, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe5, 0x7, 0x26, 0x2, 0x2, 
    0xe2, 0xe4, 0x5, 0x26, 0x14, 0x2, 0xe3, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe4, 
    0xe7, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe6, 
    0x3, 0x2, 0x2, 0x2, 0xe6, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe5, 0x3, 
    0x2, 0x2, 0x2, 0xe8, 0xe9, 0x7, 0x27, 0x2, 0x2, 0xe9, 0x29, 0x3, 0x2, 
    0x2, 0x2, 0xea, 0xef, 0x5, 0x14, 0xb, 0x2, 0xeb, 0xec, 0x7, 0x16, 0x2, 
    0x2, 0xec, 0xee, 0x5, 0x14, 0xb, 0x2, 0xed, 0xeb, 0x3, 0x2, 0x2, 0x2, 
    0xee, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xef, 0xed, 0x3, 0x2, 0x2, 0x2, 0xef, 
    0xf0, 0x3, 0x2, 0x2, 0x2, 0xf0, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xef, 
    0x3, 0x2, 0x2, 0x2, 0xf2, 0xf7, 0x5, 0xe, 0x8, 0x2, 0xf3, 0xf4, 0x7, 
    0x16, 0x2, 0x2, 0xf4, 0xf6, 0x5, 0xe, 0x8, 0x2, 0xf5, 0xf3, 0x3, 0x2, 
    0x2, 0x2, 0xf6, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf5, 0x3, 0x2, 0x2, 
    0x2, 0xf7, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf8, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0xf9, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfb, 0x5, 0x16, 0xc, 0x2, 0xfb, 
    0xfc, 0x7, 0x2d, 0x2, 0x2, 0xfc, 0xfe, 0x7, 0x13, 0x2, 0x2, 0xfd, 0xff, 
    0x5, 0x2a, 0x16, 0x2, 0xfe, 0xfd, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x3, 
    0x2, 0x2, 0x2, 0xff, 0x100, 0x3, 0x2, 0x2, 0x2, 0x100, 0x101, 0x7, 0x14, 
    0x2, 0x2, 0x101, 0x102, 0x5, 0x28, 0x15, 0x2, 0x102, 0x2f, 0x3, 0x2, 
    0x2, 0x2, 0x103, 0x104, 0x7, 0x2d, 0x2, 0x2, 0x104, 0x106, 0x7, 0x13, 
    0x2, 0x2, 0x105, 0x107, 0x5, 0x2c, 0x17, 0x2, 0x106, 0x105, 0x3, 0x2, 
    0x2, 0x2, 0x106, 0x107, 0x3, 0x2, 0x2, 0x2, 0x107, 0x108, 0x3, 0x2, 
    0x2, 0x2, 0x108, 0x109, 0x7, 0x14, 0x2, 0x2, 0x109, 0x31, 0x3, 0x2, 
    0x2, 0x2, 0x10a, 0x10c, 0x7, 0x28, 0x2, 0x2, 0x10b, 0x10d, 0x5, 0xe, 
    0x8, 0x2, 0x10c, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10d, 0x3, 0x2, 
    0x2, 0x2, 0x10d, 0x33, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10f, 0x7, 0x1e, 
    0x2, 0x2, 0x10f, 0x110, 0x7, 0x2d, 0x2, 0x2, 0x110, 0x111, 0x7, 0x26, 
    0x2, 0x2, 0x111, 0x112, 0x5, 0x2a, 0x16, 0x2, 0x112, 0x113, 0x7, 0x27, 
    0x2, 0x2, 0x113, 0x35, 0x3, 0x2, 0x2, 0x2, 0x114, 0x115, 0x7, 0x29, 
    0x2, 0x2, 0x115, 0x116, 0x7, 0x2a, 0x2, 0x2, 0x116, 0x11b, 0x7, 0xe, 
    0x2, 0x2, 0x117, 0x118, 0x7, 0x2d, 0x2, 0x2, 0x118, 0x11a, 0x7, 0x9, 
    0x2, 0x2, 0x119, 0x117, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11d, 0x3, 0x2, 
    0x2, 0x2, 0x11b, 0x119, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11c, 0x3, 0x2, 
    0x2, 0x2, 0x11c, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11b, 0x3, 0x2, 
    0x2, 0x2, 0x11e, 0x11f, 0x7, 0x2d, 0x2, 0x2, 0x11f, 0x120, 0x7, 0x2b, 
    0x2, 0x2, 0x120, 0x121, 0x7, 0xf, 0x2, 0x2, 0x121, 0x37, 0x3, 0x2, 0x2, 
    0x2, 0x122, 0x12e, 0x7, 0x2d, 0x2, 0x2, 0x123, 0x126, 0x7, 0x1c, 0x2, 
    0x2, 0x124, 0x127, 0x5, 0xc, 0x7, 0x2, 0x125, 0x127, 0x5, 0x1e, 0x10, 
    0x2, 0x126, 0x124, 0x3, 0x2, 0x2, 0x2, 0x126, 0x125, 0x3, 0x2, 0x2, 
    0x2, 0x127, 0x128, 0x3, 0x2, 0x2, 0x2, 0x128, 0x129, 0x7, 0x1d, 0x2, 
    0x2, 0x129, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12b, 0x7, 0x2c, 0x2, 
    0x2, 0x12b, 0x12d, 0x7, 0x2d, 0x2, 0x2, 0x12c, 0x123, 0x3, 0x2, 0x2, 
    0x2, 0x12c, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x130, 0x3, 0x2, 0x2, 
    0x2, 0x12e, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12f, 0x3, 0x2, 0x2, 
    0x2, 0x12f, 0x39, 0x3, 0x2, 0x2, 0x2, 0x130, 0x12e, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x3d, 0x46, 0x4b, 0x55, 0x60, 0x68, 0x6f, 0x7a, 0x83, 0x88, 0x8c, 
    0x92, 0x97, 0x9c, 0x9f, 0xb0, 0xb5, 0xbc, 0xc7, 0xdf, 0xe5, 0xef, 0xf7, 
    0xfe, 0x106, 0x10c, 0x11b, 0x126, 0x12c, 0x12e, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

minicParser::Initializer minicParser::_init;
