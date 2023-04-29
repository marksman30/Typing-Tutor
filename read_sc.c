#include <stdio.h>


typedef struct hsc
{
    char name[15];
    int score;
}hsc;

int main()
{
    FILE *fp=fopen("highscore.txt","r");
    int z=3;char buffer[100];
    hsc h[3]={{"fafd",23},{"et4",3},{"dfs",6}};
    int i=0;
    fgets(buffer,sizeof(buffer),fp);
  while(fscanf(fp,"%s\t\t\t%d\n",h[i].name,&h[i].score)!=EOF)
    {
        ++i;
    }
    hsc *ph[z];
    for(int j=0;j<z;++j)
    {
        ph[j]=&h[j];
    }

    hsc *temp;

    for(int i=0;i<z-1;++i)
    {
        for(int j=1;j<z-i;++j)
        {
            if(ph[j]->score<ph[j-1]->score)
            {
                temp=ph[j];
                ph[j]=ph[j-1];
                ph[j-1]=temp;
            }
        }
    }

    for(int i=0;i<z;++i)
    {
        printf("%s\t",ph[i]->name);
        
    }
    fclose(fp);
}
