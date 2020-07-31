#include "semantica.h"
#include "table.h"

void evalType(Pnode n) {
    switch (n->type) {
        case T_NONTERMINAL:
            switch (n->value.ival) {
                case NPROGRAM:
                    if(n->c1!=NULL)
                        varDeclList(n->c1);

                    if(n->c2!=NULL)
                        funDeclList(n->c2);

                    break;
            }
    }
}

void varDeclList(Pnode n) {
    varDeclListInterno(n,getGlobale());
}
//Una specie di overload per differenziare le tabelle,
//era stata scelta una modalita' implementativa che ora non e'
//bellissima da gestiere, cambiare volendo
void varDeclListInterno(Pnode n,Table *table){
    HashType tipo;

    tipo = getHashTypeN(n->c2,0);

    Pnode temp = n->c1;
    while (temp) {
        Entry *entry = malloc(sizeof(Entry));
        entry->key = temp->value.sval;
        entry->tipo = tipo;
        entry->next = NULL;
        if (!insertInto(entry,table))
            printf("ERRSEMANTICO L'identificatore %s e' gia' dichiarato precedentemente\n", temp->value.sval);
        temp = temp->b;
    }

    if (n->b != NULL) varDeclList(n->b);
}

void funDeclList(Pnode n){
    //Creo l'entry nella tabella principale per le funzione con i loro parametri
    char *nomeF;
    Table *table;
    do {
        Entry *entry = malloc(sizeof(Entry));
        nomeF = entry->key = n->c2->value.sval;
        HashType tipo = getHashTypeN(n->c2->b, 1);
        entry->tipo = tipo;
        entry->classe = FUN;
        entry->ambiente = creaAmbiente();
        table = entry->ambiente; //tabella locale
        Pnode temp = n->c2->c2;
        if (temp != NULL) {
            temp = temp->c1;
            int i = 0;
            while (temp != NULL) {
                Entry *entryt = malloc(sizeof(Entry));
                entryt->key = temp->c1->value.sval;
                entryt->classe = PAR;
                HashType tipot = getHashTypeN(temp->c2, 0);
                entryt->tipo = tipot;
                entryt->next = NULL;
                insertInto(entryt, entry->ambiente);
                entry->dformali[i] = entryt;
                temp = temp->b;
                i++;
            }

            entry->nformali = i;
        } else
            entry->nformali = 0;

        entry->next = NULL;
        insert(entry);

        //Gestisco le variabili dichiarate all'interno della tabella della funzione
        varDeclListInterno(n->c1, table);
        printf("TABELLA INTERNA DI %s\n", nomeF);
        print(table);
        n = n->b;
    }while(n!=NULL);

    //TODO BODY IN N->C2->C1 PER OGNUNA

}

HashType getHashTypeN(Pnode n,int ancheFunzioni){ //aggiunto n per conflitto, risolvi nome dopo
    HashType tipo = -1; //Cosa fare se qui errore? forse chiudo tutto, da chiedere
    switch (n->type) {
        case T_INTEGER:
            tipo = INTE;
            break;
        case T_REAL:
            tipo = REALE;
            break;
        case T_STRING:
            tipo = STRINGE;
            break;
        case T_BOOLEAN:
            tipo = BOOLE;
            break;
        case T_VOID:
            if(ancheFunzioni)
                tipo = VOIDE;
            else
                printf("ERRSEMANTICO Tipo di varList non consentito");
            break;
        default:
            if(ancheFunzioni)
                printf("ERRSEMANTICO Tipo di funList non consentito");
            else
                printf("ERRSEMANTICO Tipo di varList non consentito");
            break;
    }
    return tipo;
}
