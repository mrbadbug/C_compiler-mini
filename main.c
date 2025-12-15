#include <stdio.h>

int yyparse();

int main() {
    printf("Mini C Compiler (Flex + Bison)\n");
    yyparse();
    return 0;
}
