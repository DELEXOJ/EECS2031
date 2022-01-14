#include <stdio.h>

/* function declaration */
 float sum(float, float); 

main()
{
  
   int n;
   printf("Enter the number of iterations: ");
   scanf("%d", &n);
   int i;
   for (i=0; i<n; i++){
      printf("\nEnter two float numbers separated by ##: ");
      float x, y;
      scanf ("%f##%f", &x,&y);
      float su= sum(x,y);
      printf( "%f + %f = %f (%.2f)\n", x,y, su, su);
   }
}

/* function definition */
float sum (float i, float j){
   return i+j;             
}