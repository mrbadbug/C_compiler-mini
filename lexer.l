%option noyywrap

%{
#include "parser.tab.h"
#include <stdlib.h>
#include <string.h>
%}

%%

[0-9]+              { yylval.num = atoi(yytext); return NUMBER; }

[a-zA-Z_][a-zA-Z0-9_]* {
                        if (strcmp(yytext, "print") == 0)
                            return PRINT;
                        yylval.id = strdup(yytext);
                        return IDENT;
                      }

"+"                 return PLUS;
"-"                 return MINUS;
"*"                 return STAR;
"/"                 return SLASH;
"="                 return EQUAL;
"("                 return LPAREN;
")"                 return RPAREN;
";"                 return SEMICOLON;
\n                  return NEWLINE;

[ \t\r]+            ;
"#".*               ;

.                   { printf("Invalid character: %s\n", yytext); }

%%
