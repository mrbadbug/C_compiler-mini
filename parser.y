%code requires {
    #include "ast.h"
}

%{
#include <stdio.h>

int yylex(void);
void yyerror(const char *s);
%}

%union {
    int num;
    char* id;
    ASTNode* node;
}

%token <num> NUMBER
%token <id> IDENT
%token PRINT
%token PLUS MINUS STAR SLASH EQUAL
%token LPAREN RPAREN
%token NEWLINE SEMICOLON

%type <node> stmt expr term factor

%%

program:
      | program stmt
      ;

stmt:
      IDENT EQUAL expr NEWLINE
        { execute(make_assign($1, $3)); }
    | PRINT LPAREN expr RPAREN NEWLINE
        { execute(make_print($3)); }
    ;

expr:
      expr PLUS term   { $$ = make_binop('+', $1, $3); }
    | expr MINUS term  { $$ = make_binop('-', $1, $3); }
    | term             { $$ = $1; }
    ;

term:
      term STAR factor { $$ = make_binop('*', $1, $3); }
    | term SLASH factor{ $$ = make_binop('/', $1, $3); }
    | factor           { $$ = $1; }
    ;

factor:
      NUMBER             { $$ = make_number($1); }
    | IDENT              { $$ = make_var($1); }
    | LPAREN expr RPAREN { $$ = $2; }
    | MINUS factor       { $$ = make_binop('-', make_number(0), $2); }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
}

