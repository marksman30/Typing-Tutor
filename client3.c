#include "headers1.h"
villain* vil=NULL;
music *mus=NULL;
hero mystic={.name="Mystic Man",.HP=3};

void story()
{
    PlaySound(NULL,NULL,SND_ASYNC);

    mystic.HP=3;
    
    
    
    init_vill();
    init_music();
    int death=0;
    
   
    FILE* fp=fopen("Villain_story1.txt","r");

    char a,temp[500];
    printf("Enter any key to start\n");
    
   


    while(fgets(temp,sizeof(temp),fp)!=NULL)
    {
        printf("\033[1;35m");
        getch();

        int skip=0;

        for(int i=0;temp[i]!='\0';++i)
        {

            putchar(temp[i]);

            if(temp[i]=='*')  // start of combat
            {
                printf("\b");
                
                death=combat();
                
            }

            if(death==1)
            {
                break;
            }

            if(temp[i]=='%') //Access music file connected to head and play
            {
                printf("\b");
                PlaySound(NULL,NULL,SND_ASYNC);

                PlaySound(mus->title,NULL,SND_ASYNC | SND_LOOP | SND_FILENAME);

            }
            if(temp[i]=='~')                            // %:start of soundtrack and ~:end of soundtrack
            {
                printf("\b");
                PlaySound(NULL,NULL,SND_ASYNC);
                
                deque();//Deque music from the given list
                

            }

            if(kbhit())
            {
                skip=1;
                FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); //Clears the current input buffer
            }

            if(skip==0)
            {
                Sleep(10);
            }
        }



        putchar('\n');
        if(death==1)
        {
            printf(" \033[0;37m");
            char go[]="\nGAME OVER\n";
            for(int j=0;j<strlen(go);++j)
            {
                putchar(go[j]);
                Sleep(10);
            }
            sleep(2);

            break;
            
        }

    }
    fclose(fp);
    printf(" \033[1;33m");
}


void init_vill()
{ // using linked list to queue villains
    vil=(villain*)malloc(sizeof(villain));
    villain *present=NULL;
    present = vil;
    strcpy(present->name,"Esol1");present->HP=1;present->boss=0;strcpy(present->dialouge_file,"sol1.txt");present->time_s=45;
    present->node=(villain*)malloc(sizeof(villain));strcpy(present->battle_file,"solt.txt");
    present=present->node;
    strcpy(present->name,"Esol2");present->HP=1;present->boss=0;strcpy(present->dialouge_file,"sol2.txt");present->time_s=45;
    present->node=(villain*)malloc(sizeof(villain));strcpy(present->battle_file,"solt.txt");
    present=present->node;
    strcpy(present->name,"Evillain");present->HP=3;present->boss=1;strcpy(present->dialouge_file,"Evil.txt");present->time_s=40;
    present->node=NULL;strcpy(present->battle_file,"solt.txt");
    

    
}

void init_music()
{
    music *present=NULL;
    int titles=2;
    char a[][40]={"Narnia.wav","Smash.wav","Narnia.wav","Smash.wav","Narnia.wav","Smash.wav","ff4.wav","ff4.wav","ff4boss.wav","Smash.wav"};
    int rows=(sizeof(a)/sizeof(a[0]));
    for(int i=0;i<rows;++i)
    {
        if(mus==NULL)
        {
            mus=(music*)malloc(sizeof(music));
            present=mus;
            
            strcpy(present->title,*(a+i));
            present->node=NULL;
        }
        else
        {
            present->node=(music*)malloc(sizeof(music));
            present=present->node;
            strcpy(present->title,*(a+i));
            present->node=NULL;

        }
    }


    
   
}


int time_diff(clock_t tf,clock_t ti)
{
    clock_t t;
    
    t=tf-ti;
    double time_diff = ((double)t)/CLOCKS_PER_SEC;  //time difference in seconds in double format
    int int_time=(int)time_diff;    //time difference in integer format
    return int_time;


}



int battle(int time_limit,char *text_file,int final)
{
char entry;
FILE *fp=NULL;
if(final==1)
{
    
    fp=fopen("final.txt","r");
    
    
    time_limit=50;
    mystic.HP=1;
}
else
{
    fp=fopen(text_file,"r");
}



  char *str=get_text(fp);
  
  fclose(fp);
 
  printf("\033[1;37m");
  
  printf("%s\r",str);
  int i=0;
  clock_t t1,t2;//Initializing time variables
  t1=clock();
  
  
  t2=clock();
  
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
  printf("\033[1;35m");//w
  if(i==strlen(str))
  {
      
      printf("\n%s charged first\n",mystic.name);
      sleep(1.0);
      return 0;
  }
  else
  {
      printf("\n%s charged first\n",vil->name);
      sleep(1.0);
      return 1;
  }
}





int combat()    
{
    int final=0;
    
    villain* present;
    music* present1;
    PlaySound(mus->title,NULL,SND_ASYNC | SND_LOOP | SND_FILENAME);

    
    
    FILE *fpx=fopen(vil->dialouge_file,"r");
    
    char a,temp[500],*loss;
    


    while(fgets(temp,sizeof(temp),fpx)!=NULL)
    {

        

        int skip=0;

        for(int i=0;temp[i]!='\0';++i)
        {
            printf("\033[1;36m");
            putchar(temp[i]);
            

            if(temp[i]=='*' || temp[i]=='^')
            {
                if(temp[i]=='^')
                {
                    final=1;
                }
                printf("\bREADY.....");
                sleep(0.5);
                printf("GO\n");
                while(battle(vil->time_s,vil->battle_file,final) )    //Battle begins       // battle(time_limit)       
                {                                       // Incase mystic man lost in current turn the while loop will be entered
                    mystic.HP=mystic.HP-1;
                    printf("\nlives left %d\n",mystic.HP);

                    if(mystic.HP==0)
                    {
                        free(mus);
                        free(vil);// free both music list and villain list
                        PlaySound(NULL,NULL,SND_ASYNC);
                        return 1; //Mystic man has died
                    }

                    FILE *fpl=fopen("loss.txt","r");

                    loss=get_text(fpl);
                    fclose(fpl);
                    printf("%s\n",loss);
                    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
                    getch();
                     printf("\bREADY.....");
                     sleep(0.5);
                    printf("GO\n");



                }
            }

            if(kbhit())
            {
                skip=1;
                FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
            }

            if(skip==0)
            {
                Sleep(10);
            }
        }


        putchar('\n');
        getch();

    }
    present=vil;
    vil=vil->node;
    fclose(fpx);
    free(present);

    present1=mus;
    mus=mus->node;
    free(present1);
    PlaySound(NULL,NULL,SND_ASYNC);
    return 0; //Mystic man is still alive

    
  



}

void deque()
{
    music *present=NULL;
    present=mus;
    mus=mus->node;
    free(present);
    present=NULL;
    
}