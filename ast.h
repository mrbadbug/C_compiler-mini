#ifndef AST_H
#define AST_H

typedef enum {
    NODE_NUM,
    NODE_VAR,
    NODE_BINOP,
    NODE_ASSIGN,
    NODE_PRINT
} NodeType;

typedef struct ASTNode {
    NodeType type;
    int value;
    char* name;
    char op;
    struct ASTNode* left;
    struct ASTNode* right;
} ASTNode;

ASTNode* make_number(int v);
ASTNode* make_var(char* name);
ASTNode* make_binop(char op, ASTNode* l, ASTNode* r);
ASTNode* make_assign(char* name, ASTNode* expr);
ASTNode* make_print(ASTNode* expr);

void execute(ASTNode* n);

#endif
