#include "semantica.h"
#include "table.h"

void evalType(Pnode n) {
    switch (n->type) {
        case T_NONTERMINAL:
            switch (n->value.ival) {
                case NPROGRAM:
                    varDeclList(n->c1);
                    break;
            }
    }
}

void varDeclList(Pnode n) {
    Entry *entry = malloc(sizeof(Entry));
    entry->key = newstring(yytext);
    entry->next = NULL;
    insert(entry);


}