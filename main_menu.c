#include "headers1.h"          //mingw32-make -f main.mk

int main()
{
int play=0,quit=1/* display quit option when quit set to 1*/;

printf("\033[1;33m");
play_music();
play=1;
printf("=====WELCOME TO TYPING TUTOR=====\n");
for(int i=0;i<5;i++)
{
    
    sleep(1.0);
printf("\t\t***\n");

}
printf("\n\n");
fflush(stdin);

int m_loop=0;
do
{
    if(play==0)
    {
        play_music();
        play=1;
    }
            
            int option=display_opt();
            int loop=0;
            switch(option)
{
            case 1:
            do
            {

                    loop=normal();
                    play=0;
                    quit=0;


            }while(loop); 
                break;

            case 2:
                story();
                play=0;
                break;

            case 3:
                high_scores();
                play=1;
                quit=0;
                break;

            case 4:
                instructions();
                play=1;

                quit=0;
                break;

            case 5:
                
                printf("NAME:ALAN S PAUL\t\n");
                play=1;
                quit=0;
                printf("\n\n");
                break;

            case 6:
                quit=1;
                play=1;

            default:
                printf("Invalid input\n");


            break;

            }
if(quit)
{
    printf("Do you want to quit from the game?\n");
    printf("enter 1 for yes and 0 for no: ");
    scanf("%d",&m_loop);
    if(m_loop==0)
    {m_loop=1;}
    else
    {m_loop=0;}
}
else
{
    m_loop=1;
}
quit=1;
}while(m_loop);
PlaySound(NULL,NULL,SND_ASYNC);

printf("\033[0;37m");
return 0;
}

int play_music()
{
 PlaySound("fire-em.wav",NULL,SND_ASYNC | SND_LOOP | SND_FILENAME);
  return 0;
}//gcc line_output.c -o a.exe -lwinmm


int display_opt(void)
{
int opt;    
printf("Select Options\n");
printf("1:-Typing Test\n");
printf("2:-Story Mode\n");
printf("3:-Highscores\n");
printf("4:-Instructions\n");
printf("5:-About Us\n");
printf("6:-Quit\n");
scanf("%d",&opt);
return opt;

}



