#include <stdio.h>

/* function declaration */
 float sum(float, float); 

main()
{
  
   float x, y;
   printf("enter 2 floats separated by ##: ");
   scanf ("%f##%f", &x,&y);
   float su= sum(x,y);
   printf( "%f + %f = %f\n", x,y, su);
}

/* function definition */
float sum (float i, float j){
   return i+j;             
}