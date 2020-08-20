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

