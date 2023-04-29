#include "headers1.h"
int normal()
{

  PlaySound(NULL,NULL,SND_ASYNC);
  FILE *fp1=fopen("text1.txt","r");
  
  char entry;
  char *str=get_text(fp1);
  fclose(fp1);
  //char str[1000]; //= "If the world was blind how many people would you impress?";
  
  printf("\033[1;37m");
  printf("%s\r",str);
  int i=0;
  clock_t t;
  t = clock();
  
  while(i<strlen(str)){
    entry=getch();
    fflush(stdin);
    if(entry>=' ' )
        {
          if(entry!=str[i]){
            printf("\033[1;31m");
            putchar(entry);
            Beep(500,200);
            sleep(0.2);
            
            printf("\b%c\b",str[i]);
            printf("\033[0m");     
          }
          else{
            printf("\033[0;32m");putchar(entry);
            i++;  
          }
        }
        else if(entry=='\b' || entry=='\r'){
            Beep(900,200);}
        else{
            break;}
           
  }
    printf(" \033[0;33m");
    t=clock()-t;
    double timetaken = ((double)t)/CLOCKS_PER_SEC;
    printf("\n\nTime taken: %f seconds.\n",timetaken);
    int words=0;
    int count=0;
    words=word_count(str);
    
  float speed=((words)*60)/timetaken;
  printf("Typing speed: %f wpm\n",speed);
  printf("Number of words:%d\n\n",words);

  add_score(speed);

  printf("Do you want to play again?\n");
  printf("Enter 1 for yes 0 for no: ");
  int loop;
  scanf("%d",&loop);
  if(loop==1)
  {
    printf("\033[1;33m");
    return 1;
  }
  else
  {
    printf("\033[1;33m");
    return 0;
  }
  
}



int word_count(char *a)
{
int countc=0,flag=0,cycles=0;

for(int i=0;i<strlen(a);i++)
{
      countc++;
      if(a[i]!=' ')
      {
        if(flag==0)
        {
            flag=1;   //character counting
            cycles++; // word start

        }
        continue;

      }
      if(flag==1) //space encountered
      {
        flag=0;
        cycles++; //word end
      }



}
if(flag==1)
{
  flag=0;
  cycles++;
}


//printf("Number of charecters:%d\nNumber of words:%d",countc,cycles/2);
return (cycles/2); //calculates number of words


}


/*void addTohighscore(int wpm)
{
  printf("\033[1;31m");
  printf("\n");
    char name[200];
    FILE *f = fopen("highscore.txt", "a");
    printf("\n\nEnter username: ");
    
    int a=1;
    while(a){
      gets(name);
        if(strlen(name)>20){

          printf("Do not exceed 20 characters.\n");
          }
        else{
        fprintf(f,"%s\t\t\t%d\n", name,wpm);
        a=0;
        fclose(f);
      }
    }

}*/