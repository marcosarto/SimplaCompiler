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

void print(Table *tableP)
{
    int i;
    for(i = 0; i < TOT; i++)
    {
        Entry *temp = tableP->entry[i];
        if(temp)
        {
            printf("chain[%d]-->", i);
            while (temp)
            {
                printf("%s|%s -->", temp->key,tipiToString[(int)temp->tipo]);
                temp = temp->next;
            }
            printf("NULL\n");
        }
    }
}

void initTable()
{
    table = malloc(sizeof(Table));
    table->count = 0;
    table->capacity = 0;
    int i;
    for(i = 0; i < TOT; i++)
        table->entry[i] = NULL;
}

Table* creaAmbiente(){
    Table* tableP = malloc(sizeof(Table));
    return tableP;
}

Table* getGlobale(){
    return table;
}
