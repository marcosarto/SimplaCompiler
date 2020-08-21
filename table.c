#include <stdlib.h>
#include <string.h>

#include "table.h"

char* tipiToString[] =
        {
                "INTEGER",
                "REAL",
                "STRING",
                "BOOLEAN",
                "VOID"
        };

Table *table;

int hash(char* id)
{
    int h=0;
    for(int i=0; id[i] != '\0'; i++)
        h = ((h << SHIFT) + id[i]) % TOT;
    return h;
}

int insert(Entry *entry)
{
        return insertInto(entry,table);
}

int insertInto(Entry *entry,Table *tableP){
    int pos = hash(entry->key);
    int oid = tableP->count;
    entry->oid = oid;
    tableP->count = oid+1;

    if(tableP->entry[pos] == NULL)
        tableP->entry[pos] = entry;

        //collisione
    else
    {
        int controlloEsistenza = 0;
        Entry *temp = tableP->entry[pos];
        while(temp)
        {
            if (strcmp(temp->key,entry->key)==0)
                controlloEsistenza = 1;
            if(temp->next == NULL)
                break;
            temp = temp->next;
        }
        if(controlloEsistenza)
            return 0;
        else
            temp->next = entry;
        return 1;
    }
}

Entry* lookUp(char *s,Table *tableP){
    int isNull = 0;
    int pos = hash(s);

    //Per ora lascio per chiarezza del codice, questo if puo' essere tolto e anche isNull
    if(tableP->entry[pos]==NULL)
        isNull = 1;
    else{
        Entry *temp = tableP->entry[pos];
        while(temp)
        {
            if (strcmp(temp->key,s)==0)
                return temp;
            if(temp->next == NULL)
                break;
            temp = temp->next;
        }
        isNull = 1;
    }
    //Se sono nello scope di una funzione e non c'e' la variabile controllo il globale
    //In questo modo rispetto lo shadowing (precedenza definizione interna alla funzione)
    if(strcmp(tableP->scope,"Globale")!=0)
        return lookUp(s,getGlobale());
    else
        return NULL;
}

int getOid(char *s,Table *tableP) {
    int pos = hash(s);
    if (tableP->entry[pos] == NULL)
        return -1;
    else {
        Entry *temp = tableP->entry[pos];
        while (temp) {
            if (strcmp(temp->key, s) == 0)
                return temp->oid;
            if (temp->next == NULL)
                break;
            temp = temp->next;
        }
        return -1;
    }
}

void print(Table *tableP)
{
    int i;
    char *toWrite = malloc(sizeof(char)*200);
    sprintf(toWrite,"Tabella interna di %s (ID|TIPO|OID)\n",tableP->scope);
    writeToFile(toWrite);
    for(i = 0; i < TOT; i++)
    {
        Entry *temp = tableP->entry[i];
        if(temp)
        {
            sprintf(toWrite,"chain[%d]-->", i);
            writeToFile(toWrite);
            while (temp)
            {
                sprintf(toWrite,"%s|%s|%d -->", temp->key,tipiToString[(int)temp->tipo],temp->oid);
                writeToFile(toWrite);
                temp = temp->next;
            }
            writeToFile("NULL\n");
        }
    }
    writeToFile("\n\n");
}

void initTable()
{
    table = malloc(sizeof(Table));
    table->scope = newstring("Globale"); //Verra' riscritto solo se e' una funzione, metodo non pulitissimo si puo' rivedere
    table->count = 0;
    int i;
    for(i = 0; i < TOT; i++)
        table->entry[i] = NULL;
}

void assignScopeName(char *nome, Table *tableP){
    tableP->scope = nome;
}

Table* creaAmbiente(){
    Table* tableP = malloc(sizeof(Table));
    tableP->count = 0;
    return tableP;
}

Table* getGlobale(){
    return table;
}
