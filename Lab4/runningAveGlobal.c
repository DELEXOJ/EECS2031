#include <stdio.h>

void r_avg (void);
extern double sum;
// extern double ;
extern int count; 


int main(int argc, char *argv[])
{
    int input;

    printf("Enter number (-1 to quit): ");
    scanf("%d", &input);
	
    while(input != -1){	
      sum=input;
      count++;
      r_avg();

      // read again
	printf("Enter number (-1 to quit): ");
    scanf("%d", &input);
     }
	 
     return 0;
}
