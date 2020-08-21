#include <stdio.h>

FILE * fp;

void initWriteToFile(){
    fp = fopen ("Strutture","w");
}

void writeToFile(char *frase)
{
    fprintf(fp,frase);

}

void closeWriteToFile(){
    fclose (fp);
}


