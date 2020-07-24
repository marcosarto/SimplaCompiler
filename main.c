#include <stdio.h>
#include "def.h"

int main() {
    int c = yylex();
    printf("Letto %d",c);
}
