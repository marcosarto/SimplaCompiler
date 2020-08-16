//
// Created by marco on 16/08/2020.
//
#include "interprete.h"
runCode(Pnode root){
    if (root->c1 != NULL)
        varDeclList(n->c1);

    if (root->c2 != NULL)
        funDeclList(n->c2);

    body(root->b, getGlobale());
}



