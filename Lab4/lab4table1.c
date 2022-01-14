#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

 
#define ROWS 20
#define COLUMNS 30

int main(int argc, char *argv[])
{
    char inputs_table [ROWS][COLUMNS];
    char name[10]; char ageS[10]; char rateS[10];
   // ...
   int p,q;
		p=0;q=0;
    printf("Enter name, age and rate: ");
    scanf("%s %s  %s", name, ageS, rateS); 
       
    while (strcmp(name, "xxx"))        
    {  
	  
//	.....
int i,j;
i=0;j=0;
sprintf(inputs_table[q], "%s %s %s", name, ageS,rateS);
 q++;

for(i=0;name[i]!='\0';i++){
    if (isalpha(name[i]) != 0){
        if(islower(name[i])!= 0){
           name[i]=name[i]-('a'-'A');
         }else{
    name[i]=name[i];
    }
    }   
}
int res=0;
float res2=0;
   res=atoi(ageS);
   res2=atof(rateS);
 
   sprintf(inputs_table[q], "%s %d %.2f", name, (res+10),(res2*1.50));
   q++;
       /* read again using scanf(%s %s %s) */ 
             printf("Enter name, age and rate: ");
    scanf("%s %s  %s", name, ageS, rateS); 
    }
    
     printf("\nRecords generated in %s on %s %s\n", __FILE__, __DATE__, __TIME__); 
    
    /* now display the input_table row by row */      
	//......
	// ......
    int x,y;
  for(x=0; x<q; x++)
          printf("row[%d]: %s\n",x,inputs_table[x]);
     return 0;
}
