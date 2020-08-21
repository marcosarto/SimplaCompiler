#include "stringHeap.h"

char heap[STRING_HEAP];
char *h = heap;

char *addToHeap(char *toAdd){
    int i;
    char *pointerToStringStartingPoint;
    pointerToStringStartingPoint = h;

    for(i=0;i<=strlen(toAdd);i++){
        strcpy(h,&toAdd[i]);
        h++;
    }

    return pointerToStringStartingPoint;
}

void printHeap(){
    char* toWrite = malloc(sizeof(char)*200);
    writeToFile("CONTENUTO HEAP\n");
    for(int i=0;i<STRING_HEAP;i++){
        if(heap[i]=='\0'){
            if(i+1<STRING_HEAP&&heap[i+1]=='\0') {
                break;
            } else
                writeToFile("|");
        }
        else {
            sprintf(toWrite, "%c", heap[i]);
            writeToFile(toWrite);
        }
    }
    writeToFile("\n");
}
