#include <stdlib.h>
#include <string.h>

#include "table.h"


Table table;

int hash(char* id)
{
    int h=0;
    for(int i=0; id[i] != '\0'; i++)
        h = ((h << SHIFT) + id[i]) % TOT;
    return h;
}

void insert(Entry *entry)
{
        int pos = hash(entry->key);

        if(table.entry[pos]==NULL)
            table.entry[pos] = entry;

        //collisione
        else
        {
            int controlloEsistenza = 0;
            Entry *temp = table.entry[pos];
            while(temp)
            {
                if (strcmp(temp->key,entry->key)==0)
                    controlloEsistenza = 1;
                if(temp->next == NULL)
                    break;
                temp = temp->next;
            }
            if(controlloEsistenza)
                printf("L'identificatore %s esiste gia' \n",entry->key);
            else
                temp->next = entry;
        }
}

void print()
{
    int i;
    for(i = 0; i < TOT; i++)
    {
        Entry *temp = table.entry[i];
        if(temp)
        {
            printf("chain[%d]-->", i);
            while (temp)
            {
                printf("%s -->", temp->key);
                temp = temp->next;
            }
            printf("NULL\n");
        }
    }
}

void initTable()
{
    table.count = 0;
    table.capacity = 0;
    int i;
    for(i = 0; i < TOT; i++)
        table.entry[i] = NULL;
}
