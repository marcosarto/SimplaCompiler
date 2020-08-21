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
                //printf("Esiste nel heap uguale\n");
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

char* addStringLiteral(char *e){
    //Rimuovo le ""
    if(e[0]=='"')
        e++;
    if(e[strlen(e)-1]=='"')
        e[strlen(e)-1] = '\0';
    return addString(e);
}

void printStringPoolStructure()
{
    char* toWrite = malloc(sizeof(char)*200);
    int i;
    writeToFile("Hashmap delle stringhe presenti\n");

    for(i = 0; i < TOTR; i++)
    {
        Entryr *temp = sp->entry[i];
        if(temp)
        {
            sprintf(toWrite,"chain[%d]-->", i);
            writeToFile(toWrite);
            while (temp)
            {
                sprintf(toWrite,"%s -->", temp->key);
                writeToFile(toWrite);
                temp = temp->next;
            }
            writeToFile("NULL\n");
        }
    }
    writeToFile("\n");
    printHeap();
}