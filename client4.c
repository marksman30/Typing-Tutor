#include "headers1.h"


list* head=NULL;






int high_scores()
{   printf("\033[1;31m");

    int score,i=0;char name[25],buffer[100];

    FILE *fp=fopen("highscore.txt","r");
    
    fgets(buffer,sizeof(buffer),fp);
    
    while(fscanf(fp,"%s\t\t\t%d\n",name,&score)!=EOF && i<11)
    {
        
        insert(score,name);
        ++i;
    }
    display();
    delete();
    fclose(fp);
    printf("\033[1;33m");

    
}

void insert(int element,char str[])
{
    list *temp=(list*)malloc(sizeof(list));
    strcpy(temp->info.name,str);
    temp->info.p=element;
    temp->node=NULL;
    if(head==NULL || (head->info.p<element))
    {
        temp->node=head;
        head=temp;
    }
    else
    {
        list *present,*previous;
        present=head;
        previous=NULL;
        while(present!=NULL && present->info.p>=element)
        {
            previous=present;
            present=present->node;

        }
        temp->node=previous->node;
        previous->node=temp;

    }
   
}

void insert1(int element,char str[])
{
    list *temp=(list*)malloc(sizeof(list));
    strcpy(temp->info.name,str);
    temp->info.p=element;
    temp->node=NULL;
    if(head==NULL || (head->info.p>element))
    {
        temp->node=head;
        head=temp;
    }
    else
    {
        list *present,*previous;
        present=head;
        previous=NULL;
        while(present!=NULL && present->info.p<=element)
        {
            previous=present;
            present=present->node;

        }
        temp->node=previous->node;
        previous->node=temp;

    }
   
}



void delete()
{
   list *present;
   present=head;
   while(present!=NULL)
   {
       head=present->node;
       free(present);
       present=head;
   }
   

}

void display()
{
    list *disp;
    disp=head;
    //printf("%-10s\t%-10s\n","Name","Score");  //setting up table
    for(int i=0;i<21;++i)
    {
        printf("-");
    }
    printf("\n");
    printf("Name");
    for(int i=0;i<12;++i)
    {
        printf("-");
    }
    printf("Score\n");
    for(int i=0;i<21;++i)
    {
        printf("-");
    }
    printf("\n");
    while(disp!=NULL)
    {
        printf("%-10s\t%-10d\n",disp->info.name,disp->info.p);
        disp=disp->node;
        
    }
    printf("\n\n\n");

}


int add_score(int wpm)
{
    printf("\033[1;31m");
    int score,i=0,high_score=0;char name[25],buffer[100];

    FILE *fp=fopen("highscore.txt","r");
    
    fgets(buffer,sizeof(buffer),fp);//Just to move to the next line
    
    while(fscanf(fp,"%s\t\t\t%d\n",name,&score)!=EOF && i<11)
    {
        
        insert1(score,name);
        ++i;
    }

    fclose(fp);
    list *present=head;
    if(i<5)

    {
        list *temp1=(list*)malloc(sizeof(list));
        temp1->node=head;
        head=temp1;
        int b=1;
        while(b)
        {
            printf("Enter username: ");
            gets(name);
            if(strlen(name)>20)
            {

                printf("Do not exceed 20 characters.\n");
            }
            else
            {
                b=0;
            }
                
        }
        strcpy(temp1->info.name,name);
        temp1->info.p=wpm;
        high_score=1;
        temp1=NULL;

    }
    else
    {
        while(present!=NULL)
        {
            if(wpm>present->info.p)
            {
                int a=1;
                while(a)
                {
                    printf("Enter username: ");
                    gets(name);
                    if(strlen(name)>20)
                    {

                        printf("Do not exceed 20 characters.\n");
                    }
                    else
                    {
                        a=0;
                    }
                
                }
                    strcpy(present->info.name,name);
                    present->info.p=wpm;
                    high_score=1;


                    break;

                }
                present=present->node;
            }
    }

    present=head;
    if(high_score==1)
    {
        FILE* fp1=fopen("highscore.txt","w");
        fprintf(fp1,"Name\t\t\tSpeed\n");
        while(present!=NULL)
        {
            fprintf(fp1,"%s\t\t\t%d\n",present->info.name,present->info.p);
            present=present->node;
        }
        
        fclose(fp1);

    }
    present=NULL;
    delete();

}

   
