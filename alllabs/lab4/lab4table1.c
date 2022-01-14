
#include <stdio.h>   // for fgets, sprintf, sscanf
#include <string.h>  // for strlen, strcpy ...
#include <ctype.h>   // for toupper
#include <stdlib.h>  // for atoi

 
#define ROWS 20
#define COLUMNS 30

int main(int argc, char *argv[])
{
	char inputs[ROWS][COLUMNS];
        
	int current_row = 0; int i;
        char name[10]; 
        char ageS[10];
        char rateS[10];
        int age; 
        float rate;
   
	// read in three strings	
        printf("Enter name age and rate: ");
        scanf("%s %s %s", name, ageS, rateS); 
       
        while (strcmp(name,"xxx"))     
        {  
           // form a string and write to current row
           sprintf(inputs[current_row], "%s %s %s", name, ageS,rateS);  /* format and print/write to current row */	   
           	   
           age = atoi(ageS)+10; 
           rate = atof(rateS) *1.5;
 
   
           for(i=0; i< strlen(name); i++){
              name[i] = toupper(name[i]);    // or  name[i] = name[i] - ('a'-'A')
           } 
	   
           sprintf(inputs[current_row + 1], "%s %d %.2f", name,age,rate);  /* format and print/write to next row */

           /* read again */
           printf("Enter name age and rate: ");

           scanf("%s %s %s", name, ageS, rateS );
           
           current_row += 2;
           
       }
       
       printf("\nRecords generated in %s on %s %s\n", __FILE__, __DATE__, __TIME__);
       
       // output the table row by row
       for(i=0; i< current_row; i++)
          printf("row[%d]: %s\n",i,inputs[i]);
      

       return 0;
}
