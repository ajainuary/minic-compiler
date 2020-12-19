#include <iostream>

// #include "PostfixVisitor.h"
#include "CodeGen.h"
#include "antlr4-runtime.h"
#include "minicBuildASTVisitor.h"
#include "minicLexer.cpp"
#include "minicParser.cpp"

//#include "ast.h"

using namespace std;
using namespace antlr4;

int main(int argc, const char *argv[]) {
  std::ifstream stream;

  // cout << "Processing input file " << argv[1] << endl;
  stream.open(argv[1]);

  ANTLRInputStream input(stream);

  minicLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  minicParser parser(&tokens);

  minicParser::ProgContext *ctx = parser.prog();
  // cerr << "Parsed, building AST now..." << endl;
  minicBuildASTVisitor *visitor = new minicBuildASTVisitor();

  ASTProgNode *program_root = visitor->visitProg(ctx);

  CodegenVisitor *generator = new CodegenVisitor(program_root);
  generator->codeGen();

  return 0;
}
