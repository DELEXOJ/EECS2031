/***************************************
* EECS2031ON – Lab1 *
* Author: Ojo, Ayobami *
* Email: ayobami1@my.yorku.ca *
* eecs_username: ayobami1 *
* York Student #: 215281421
****************************************/

#include <stdio.h>

 int main()
{
    int m, d, y;
 printf("Enter month, day and year separated by spaces:");
scanf("%d %d %d" ,&m, &d, &y);
  printf("The input '%d %d %d' is reformatted as %d/%d/%d and %d-%d-%d.",m,d,y,y,m,d,y,m,d);
}
