/* this version do count++ and sum+=input in main. 
 input is a local variable

*/

#include <stdio.h>
 

/* these are defined in function.c */ 
void r_avg(void);
extern int count;  
extern int sum;


int main(int argc, char *argv[])
{
    int input;

    printf("Enter number (-1 to quit): ");
    scanf("%d", &input);
	
    while(input != -1){	
      count ++;
      sum += input;
      r_avg();


      // read again
      printf("\Enter number (-1 to quit): ");
      scanf("%d", &input);
	
     }
	 
     return 0;
}
