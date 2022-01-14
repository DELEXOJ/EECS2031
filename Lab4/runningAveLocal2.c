#include <stdio.h>

void r_avg(int);

static double newInput=0;
static int counter=0;

int main(int argc, char *argv[])
{
	
   int input;  
   printf("Enter number (-1 to quit): ");
   scanf("%d", &input);

   while (input != -1){
        r_avg(input);

        printf("\nEnter number (-1 to quit): ");
        scanf("%d", &input);
    }
	
    return 0;
}

void r_avg(int input)
{
   newInput+=input;
   counter++;
    double resu =newInput/counter;
    printf("running average is %.0f / %d =%.3f",newInput,counter,resu);     
}