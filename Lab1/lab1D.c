/***************************************
* EECS2031ON – Lab1 *
* Author: Ojo, Ayobami *
* Email: ayobami1@my.yorku.ca *
* eecs_username: ayobami1 *
* York Student #: 215281421
****************************************/

#include <stdio.h>

float sum (float,float);
void greet(int);
float main()
{  
   int a = 2031;
   greet(a);
    float x, y;
    printf("Enter two float number separated by ##:");
scanf("%f##%f" ,&x, &y);
  printf("%f + %f = %f", x, y, sum(x,y));

}

/* function definition */
float sum (float i, float j){
   return i+j;             
}
void greet(int i){
   printf("Hello %d!\n", i);
}