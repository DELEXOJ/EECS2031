/***************************************

****************************************/


#include <stdio.h>

float sum (float,float);
void greet(int);
float main()
{  
    int i;
    int count=0;
   int a = 2031;
   greet(a);
    float x, y;
    printf("Enter the number of interactions:");
    scanf("%d" ,&i);
while (count!=i) {
 printf("Enter two float number separated by ##:");
scanf("%f##%f" ,&x, &y);
  printf("%f + %f = %f\n", x, y, sum(x,y));
count++;
}

}

/* function definition */
float sum (float i, float j){
   return i+j;             
}
void greet(int i){
   printf("Hello %d!\n", i);
}
