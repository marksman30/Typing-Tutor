#include "headers1.h"

char* get_text(FILE* fp)
{
int line=0; 
   
static char w[1000];

line=line_select(fp);
rewind(fp); //bringing the ponter to start of the position





    for(int i=1;i<=line;i++)
    {
        if(NULL==fgets(w,sizeof(w),fp))  //If there is no new line return NULL or 0 (Just for debugging)
          {printf("Sorry! EOF\n");
          return NULL;}                  //in every iteration fgets updates the array
        
          
    }
//printf("%s",w);         //prints the value of latest w}
w[strcspn(w, "\n")] = 0; //to remove trailing new line
rewind(fp);
return w;
}






int line_select(FILE* fp)
{

int line=0,line_count=0; 
char chr;



while((chr=getc(fp))!=EOF)
{   

     if (chr == '\n')
        {
            ++line_count;
        }
    


}
//printf("The number of lines in given file is %d\n",line_count);

    srand(time(NULL));
    int randomnumber;
    randomnumber = rand() % (line_count);
    ++randomnumber;
   // printf("%d\n", randomnumber);
    return randomnumber;

}

