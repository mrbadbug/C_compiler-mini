#include "ast.h"
#include <stdio.h>

int vars[26];

int eval(ASTNode* n) {
    switch (n->type) {
        case NODE_NUM:
            return n->value;

        case NODE_VAR:
            return vars[n->name[0] - 'a'];

        case NODE_BINOP:
            if (n->op == '+') return eval(n->left) + eval(n->right);
            if (n->op == '-') return eval(n->left) - eval(n->right);
            if (n->op == '*') return eval(n->left) * eval(n->right);
            if (n->op == '/') return eval(n->left) / eval(n->right);
    }
    return 0;
}

void execute(ASTNode* n) {
    if (n->type == NODE_ASSIGN) {
        vars[n->name[0] - 'a'] = eval(n->right);
    }
    else if (n->type == NODE_PRINT) {
        printf("%d\n", eval(n->right));
    }
}
