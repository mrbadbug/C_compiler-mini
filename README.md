# Mini C Compiler using Flex and Bison

**Description**
 - This project implements a Mini C Compiler supporting basic arithmetic
expressions, variable assignment, and print statements using Flex and Bison.

**Features**
- Integer variables
- Arithmetic operations (+, -, *, /)
- Operator precedence
- print() statement
- Stack-based virtual machine

**Build Instructions**
```bash
flex lexer.l
bison -d parser.y
gcc lex.yy.c parser.tab.c ast.c vm.c main.c -o minic
