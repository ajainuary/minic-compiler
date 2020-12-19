grammar minic;

prog: program + EOF
    ;
/* Arrow */
arrowExpr : expr #arrowPass
| expr '->' expr #binaryArrow
;
/* Unary + or - */
unaryExpr: OP = ('+'|'-'|'&'|'*'|'!') arrowExpr #unaryOperate
    | arrowExpr     #unaryPass
    ;
/* Group all the multiplications and divisions */
multiplicativeExpr: unaryExpr #multiplicativePass
    | multiplicativeExpr OP = ('*' | '/' | 'mod') unaryExpr #binaryMultiplicative
    ;
/* Group all the additions and subtractions but multiply first */
additiveExpr: multiplicativeExpr #additivePass
| additiveExpr OP = ('+' | '-') multiplicativeExpr #binaryAdditive
;
/* Comparison */
comparisonExpr: additiveExpr OP = ('==' | '<=' | '>=' | '<' | '>' | '!=') additiveExpr #binaryComparison
    | additiveExpr #comparisonPass
;
/* Boolean */
booleanExpr: comparisonExpr OP = ('and' | 'or') comparisonExpr #binaryBoolean
    | comparisonExpr #booleanPass
;
/* Evaluate brackets first then expand the inner expression */
expr: '(' booleanExpr ')' #exprParenthesis
| functionCall #exprCall
| identifier #exprIdentifier
| NUMBER #exprNumber
| LITERAL #exprLiteral
| STRING #exprString
;
/* Assignment */
assign: identifier '=' booleanExpr;
/* Declaration */
declaration: type (identifier|assign) (',' (identifier|assign))*;
type : (PRIMITIVE = ('integer' | 'float' | 'char' | 'bool' | 'void') ('[' booleanExpr? ']')* | 'struct' ID) '*'?;
/* Language Semantics */
statement : booleanExpr ';' #exprStatement
| assign ';' #assignStatement
| declaration ';' #declarationStatement
| returnStatement ';' #retStatement
| structDeclaration ';' #structDeclarationStatement
;
nonControl : declaration #nonControlDeclaration
| assign #nonControlAssign
| structDeclaration #nonControlStructDeclaration
;
/* If - Else */
ifElse : 'if' booleanExpr block ('else' block)?;
ternary : booleanExpr '?' booleanExpr ':' booleanExpr;
control : forStatement | whileStatement | ifElse; 
/* for Loop */
forStatement : 'for' '(' nonControl ';' booleanExpr ';' nonControl ')' block;
whileStatement : 'while' '(' booleanExpr ')' block;
program : block | statement | control | functionDeclaration | functionCall | include ;
block : '{' program* '}';
/* Functions */
paramList : declaration (',' declaration)*;
argList : booleanExpr (',' booleanExpr)*;
functionDeclaration : type ID '(' paramList? ')' block;
functionCall : ID '(' argList? ')';
returnStatement : 'return' booleanExpr?;
/* struct */
structDeclaration : 'struct' ID '{' paramList '}';
/* Compiler Directives */
include: '#' 'include' '<' (ID '/')* ID '.h''>';
/*Tokens*/
identifier: ID ('[' (comparisonExpr|ternary) ']' | '.' ID)*;
ID  : [a-zA-Z][a-zA-Z0-9_]*;
NUMBER : [0-9.]+;
LITERAL : '"' (~('"' | '\\' | '\r' | '\n') | '\\' ('"' | '\\')?)* '"' | '\'' (~('"' | '\\' | '\r' | '\n') | '\\' ('"' | '\\')?)* '\'';
STRING : '"' [a-z][a-zA-Z0-9%]* '"';
COMMENT : '//' ~[\r\n]*->skip; 
NS : [ \t\n]+ -> skip; 