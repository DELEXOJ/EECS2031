/******************
****************************************/

#include <stdio.h>

float sum (float,float);
void greet(int);
int main()
{  
   int a = 2031;
   greet(a);
   float x =2.2, y=3.3;
   float su= sum(x,y);
   printf( "%f + %f = %f\n", x,y, su);

   return 0;

}

/* function definition */
float sum (float i, float j){
   return i+j;             
}

void greet(int i){
   printf("Hello %d!\n", i);
}
