#include <stdio.h>
#include <time.h>
#include <windows.h>  //Sleep
#include <unistd.h>    //sleep
#include <windowsx.h>  //Beep
#include <mmsystem.h>
#include <conio.h>
#include <string.h>

//character structs
typedef struct hero
{
    char name[20];
    int HP;

}hero;

typedef struct villain
{
    char name[20];
    int HP;
    int time_s;
    int boss;
    char dialouge_file[20];
    char battle_file[20];
    struct villain *node;

}villain;

typedef struct music{
    char title[40];
    struct music *node;
}music;


// client1
int word_count(char *a);
int normal();
//void addTohighscore(int);

// client2 
int line_select(FILE *fp);
char* get_text(FILE *fp);


//client3
int battle(int,char*,int);
void story();
void init_vill();
void init_music();
int combat();
int time_diff(clock_t,clock_t);
void deque();

//client4
int high_scores();
void insert(int,char[]);
void insert1(int,char[]);
void delete();
void display();
int add_score(int);
//priority client4
typedef struct priority
{
    char name[20];
    int p; // priority
}priority;


typedef struct list
{
    priority info;
     struct list *node;


}list;

//client5
int instructions();

//main_menu
int play_music();
int display_opt();
