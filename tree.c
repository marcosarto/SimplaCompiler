#include "def.h"

char* tabtypes[] =
        {
                "T_INTEGER",
                "T_REAL",
                "T_STRING",
                "T_BOOLEAN",
                "T_VOID",
                "T_WRITE",
                "T_WRITELN",
                "T_AND",
                "T_OR",
                "T_EQU",
                "T_NEQ",
                "T_GRT",
                "T_GEQ",
                "T_LSS",
                "T_LEQ",
                "T_PLUS",
                "T_MINUS",
                "T_STAR",
                "T_DIV",
                "T_NOT",
                "T_ID",
                "T_BREAK",
                "T_INTCONST",
                "T_STRCONST",
                "T_BOOLCONST",
                "T_REALCONST",
                "T_NONTERMINAL"
        };

char* tabnonterm[] =
        {
                "PROGRAM",
                "VAR_DECL",
                "FUNC_DECL",
                "OPT_PARAM_LIST",
                "PARAM_DECL",
                "ASSIGN_STAT",
                "IF_STAT",
                "WHILE_STAT",
                "FOR_STAT",
                "RETURN_STAT",
                "READ_STAT",
                "WRITE_STAT"
        };

void treeprint(Pnode root, int indent)
{
    int i;

    for(i=0; i<indent; i++)
        printf("    ");
    printf("%s", (root->type == T_NONTERMINAL ? tabnonterm[root->value.ival] : tabtypes[root->type]));
    if(root->type == T_ID || root->type == T_STRCONST)
        printf(" (%s)", root->value.sval);
    else if(root->type == T_INTCONST)
        printf(" (%d)", root->value.ival);
    else if(root->type == T_BOOLCONST)
        printf(" (%s)", (root->value.ival == TRUE ? "true" : "false"));
    printf("\n");
    if(root->c1!=NULL)
        treeprint(root->c1,indent+1);
    if(root->c2!=NULL)
        treeprint(root->c2,indent+1);
    if(root->b!=NULL)
        treeprint(root->b,indent+1);
}
