#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define ROWS 20
#define COLUMNS 30

int main(int argc, char *argv[])
{
     char input_table[ROWS][COLUMNS];
     int current_row=0;
     
    char name[10]; char ageS[10]; char rateS[10];
int i;
i=0;
     printf("Enter name, age and rate: ");
     fgets(input_table[current_row], 30, stdin);   // read into table directly. add a \n.  Don't change this line
	 
         sscanf(input_table[current_row], "%s %s %s", name, ageS,rateS);

     while(strcmp(name, "xxx"))        
     {    
	 /* may need to 'tokenize' the current input */	    
	
   
     for(i=0;name[i]!='\0';i++){
    if (isalpha(name[i]) != 0){
        if(islower(name[i])!= 0){
           name[i]=toupper(name[i]);
         }else{
    name[i]=name[i];
    }
    }   
}

int res=0;
float res2=0;
   res=atoi(ageS);
   res2=atof(rateS);
    res=res+10;
    res2=res2*1.50;
current_row++;
sprintf(input_table[current_row], "%s %d %.2f", name,res,res2);
current_row++;
       printf("Enter name, age and rate: ");
     fgets(input_table[current_row], 30, stdin); 

  sscanf(input_table[current_row], "%s %s %s", name, ageS,rateS);
     }

     printf("\nRecords generated in %s on %s %s\n", __FILE__, __DATE__, __TIME__);
     /* now display the input_table row by row */
	   int x;
  for(x=0; x<current_row; x++)
          printf("row[%d]: %s\n",x,input_table[x]);

     return 0;
}
