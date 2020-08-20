#include "stringPoolStructure.h"

Tabler *sp;

void initStringPool(){
    sp = malloc(sizeof(Tabler));
    int i;
    for(i = 0; i < TOTR; i++)
        sp->entry[i] = NULL;
}

int hashr(char* id)
{
    int h=0;
    for(int i=0; id[i] != '\0'; i++)
        h = ((h << SHIFTR) + id[i]) % TOTR;
    return h;
}

char* addString(char *e){
    int pos = hashr(e);

    if(sp->entry[pos] == NULL) {
        Entryr *toadd = malloc(sizeof(Entryr));
        toadd->key = addToHeap(e);
        toadd->next = NULL;
        sp->entry[pos] = toadd;
        return toadd->key;
    }

        //collisione
    else
    {
        Entryr *temp = sp->entry[pos];
        while(temp)
        {
            if (strcmp(temp->key,e)==0) {
                printf("Esiste nel heap uguale");
                return temp->key;
            }
            if(temp->next == NULL) {
               break;
            }
            temp = temp->next;
        }
        Entryr *nuovoNodo = malloc(sizeof(Entryr));
        nuovoNodo->key = addToHeap(e);
        nuovoNodo->next = NULL;
        temp->next = nuovoNodo;
        return nuovoNodo->key;
    }
}
