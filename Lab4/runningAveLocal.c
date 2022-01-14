#include <stdio.h>


void r_avg(int, int);

static double re=0;
int main(int argc, char *argv[])
{
	
      int input; int count=0; int sum=0;
      

      printf("Enter number (-1 to quit):  ");
      scanf("%d", &input);

      while(input != -1)
      {
        sum=input;
       count++;
          r_avg(sum, count);
 	     
          /* read again */
	  printf("Enter number (-1 to quit):  ");
      scanf("%d", &input);

       }  
	
       return 0;
}

void r_avg(int sum, int count)
{
    re+=sum;
   double resu = re/count;
   printf("running average is %.0f / %d = %.3f\n",  re, count, resu);   
}