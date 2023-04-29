#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <unistd.h>
#include <windowsx.h>
#include <mmsystem.h>
#include <conio.h>
#include <string.h>

int time_diff(clock_t tf,clock_t ti)
{
    clock_t t;
    
    t=tf-ti;
    double time_diff = ((double)t)/CLOCKS_PER_SEC;  //time difference in seconds in double format
    int int_time=(int)time_diff;    //time difference in integer format
    return int_time;


}

int battle(int time_limit)
{
char entry;


FILE *fp=fopen("text1.txt","r");
  char *str=get_text(fp);
  fclose(fp);
 
  
  
  printf("%s\r",str);
  int i=0;
  clock_t t1,t2;//Initializing time variables
  t1=clock();
  
  
  
  while(i<strlen(str) && (time_limit>(time_diff(t2,t1))))
  {
    entry=getch();
    fflush(stdin);
    if(entry>=' ' )
        {
          if(entry!=str[i])
          {
            printf("\033[1;31m");
            putchar(entry);
            Beep(500,200);
            sleep(0.2);
            
            printf("\b%c\b",str[i]);
            printf("\033[0m");     
          }
          else
          {
            printf("\033[0;32m");putchar(entry);
            i++;  
          }
        }
        else if(entry=='\b' || entry=='\r'){
            Beep(900,200);}
        else{
            break;
            }
        t2=clock();
           
  }
  printf(" \033[0;37m");
  if(i==strlen(str))
  {
      return 1;
  }
  else
  {
      return 0;
  }
}


