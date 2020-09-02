#ifndef PROVATECNOLOGIE_DEF_H
#define PROVATECNOLOGIE_DEF_H

#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    NPROGRAM,
    NVAR_DECL,
    NFUNC_DECL,
    NOPT_PARAM_LIST,
    NPARAM_DECL,
    NASSIGN_STAT,
    NIF_STAT,
    NWHILE_STAT,
    NFOR_STAT,
    NRETURN_STAT,
    NREAD_STAT,
    NWRITE_STAT,
    NCOND_EXPR,
    NFUNC_CALL
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
    T_EQU,
    T_NEQ,
    T_GRT,
    T_GEQ,
    T_LSS,
    T_LEQ,
    T_PLUS,
    T_MINUS,
    T_STAR,
    T_DIV,
    T_NOT,
    T_ID,
    T_BREAK,
    T_ADDR,
    T_INTCONST,
    T_STRCONST,
    T_BOOLCONST,
    T_REALCONST,
    T_NONTERMINAL
} Typenode;

typedef enum {FALSE, TRUE} Boolean;

typedef union uvalue
{
    int ival;
    float rval;
    char *sval;
    Boolean bval;
    int mem;
}Value;

typedef struct snode
{
    Typenode type;
    Value value;
    int linen;
    struct snode *c1, *c2, *b;
} Node;
typedef Node *Pnode;

char *newstring(char*);
int yylex();
Pnode nontermnode(Nonterminal),
        idnode(),
        keynode(Typenode),
        realconstnode(),
        intconstnode(),
        strconstnode(),
        boolconstnode(),
        newnode(Typenode);
void treeprint(Pnode, int),
        yyerror();
void errLessicale();

#endif //PROVATECNOLOGIE_DEF_H