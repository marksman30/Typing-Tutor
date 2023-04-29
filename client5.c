#include "headers1.h"
int instructions()
{
    FILE* fp=fopen("instructions.txt","r");
    char buffer[400];
    while(fgets(buffer,sizeof(buffer),fp)!=NULL)
    {
        fputs(buffer,stdout);
    }
    fclose(fp);
    return 0;
}