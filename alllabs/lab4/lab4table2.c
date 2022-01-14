/* this version manually add a \n at the end of the modified row, to be 
consistent with the orignal rows where a \n is added by fgets */

// also use while(1) loop

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define ROWS 20
#define COLUMNS 30


int main(int argc, char *argv[])
{
        char inputs[ROWS][COLUMNS];
        
        int current_row = 0; int i;
        char name[10]; 
        int age; 
        float rate;
	 
	
        while(1)        
        { 

           printf("Enter name age and rate: ");
           fgets(inputs[current_row], 30, stdin);   // read dirctly into table row.  an \n is added by fgets

	   // tokenize the string, getting values of name, age and wage
           sscanf(inputs[current_row],"%s %d %f", name, &age, &rate); 

	   if (! strcmp(name, "xxx")) break;
           //or just if inputs[current_row][0]=='x' && inputs[current_row][1]=='x' && inputs[current_row][2]=='x') break;

           age += 10;
           rate *= 1.5;
	   
           // modify name directly
           for(i=0; i< strlen(name); i++){
              name[i] = toupper(name[i]);
           }
	     
           sprintf(inputs[current_row+1], "%s %d %.2f\n", name,age,rate);
           current_row += 2;
		   
           
        }
       
        printf("\nRecords generated in %s on %s %s\n", __FILE__, __DATE__, __TIME__);

        for(i=0; i< current_row; i++){
           printf("row[%d]: %s", i, inputs[i]); // no \n needed
           // or  printf("row[%d]: ", i);  
           // or fputs(inputs[i],stdout);  
        }
       return 0;
}
