#include "heap.h"

Value heapA[HEAPDIM];
Value *p = heapA;

Value *addToHeapValue(Value toAdd){
    *p = toAdd;
    p++;
    return (p-1);
}

void printHeapValue(){
    for(Value *i = heapA; i<p ; i++){
        printf("[%d|%f|%d]\n",i->ival,i->rval,i->bval);
    }
}