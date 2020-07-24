#ifndef PROVATECNOLOGIE_DEF_H
#define PROVATECNOLOGIE_DEF_H

#endif //PROVATECNOLOGIE_DEF_H

#include <stdio.h>
#include <stdlib.h>
typedef enum
{
    NPROGRAM,
    NVAR_DECL_LIST,
    NFUNC_DECL_LIST,
    NSTAT_LIST,
    NVAR_DECL,
    NID_LIST,
    NFUNC_DECL,
    NOPTPARAM_LIST,
    NPARAM_DECL,
    NASSIGN_STAT,
    NIF_STAT,
    NWHILE_STAT,
    NFOR_STAT,
    NRETURN_STAT,
    NREAD_STAT,
    NWRITE_STAT,
    NFUNC_CALL,
    NEXPR,
    NEXPR_LIST,
    NLOGIC_EXPR,
    NREL_EXPR,
    NMATH_EXPR,
    NNEG_EXPR,
    NCOND_EXPR,
    NCASTING
} Nonterminal;

typedef enum
{
    T_INTEGER,
    T_REAL,
    T_STRING,
    T_BOOLEAN,
    T_VOID,
    T_WRITE,
    T_WRITELN,
    T_AND,
    T_OR,
    T_EQUALS,
    T_NOT_EQUALS,
    T_GREATER,
    T_GREATER_EQ,
    T_LESS,
    T_LESS_EQ,
    T_PLUS,
    T_MINUS,
    T_STAR,
    T_SLASH,
    T_NOT,
    T_INTCONST,
    T_REALCONST,
    T_STRCONST,
    T_BOOLCONST,
} Typenode;

typedef union
{
    int ival;
    float rval;
    char *sval;
    enum {FALSE, TRUE} bval;
} Value;

typedef struct snode
{
    Typenode type;
    Value value;
    struct snode *c1, *c2, *b;
} Node;
typedef Node *Pnode;

char *newstring(char*);
int yylex();
Pnode nontermnode(Nonterminal),
        idnode(),
        keynode(Typenode),
        intconstnode(),
        strconstnode(),
        boolconstnode(),
        newnode(Typenode);
void treeprint(Pnode, int),
        yyerror();