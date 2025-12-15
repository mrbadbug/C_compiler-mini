#include "ast.h"
#include <stdlib.h>

ASTNode* make_number(int v) {
    ASTNode* n = malloc(sizeof(ASTNode));
    n->type = NODE_NUM;
    n->value = v;
    return n;
}

ASTNode* make_var(char* name) {
    ASTNode* n = malloc(sizeof(ASTNode));
    n->type = NODE_VAR;
    n->name = name;
    return n;
}

ASTNode* make_binop(char op, ASTNode* l, ASTNode* r) {
    ASTNode* n = malloc(sizeof(ASTNode));
    n->type = NODE_BINOP;
    n->op = op;
    n->left = l;
    n->right = r;
    return n;
}

ASTNode* make_assign(char* name, ASTNode* expr) {
    ASTNode* n = malloc(sizeof(ASTNode));
    n->type = NODE_ASSIGN;
    n->name = name;
    n->right = expr;
    return n;
}

ASTNode* make_print(ASTNode* expr) {
    ASTNode* n = malloc(sizeof(ASTNode));
    n->type = NODE_PRINT;
    n->right = expr;
    return n;
}
