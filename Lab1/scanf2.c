#include <stdio.h>


int sum (int i, int j)
{
  return i+j;           
}


int main()
{
  int a, b;
  printf("Please enter two integers separated by a <><><>: \n" );
 
  scanf( "%d<><><>%d",  &a,&b);     /* assign value to a b  */
  printf("Entered %d and %d. Sum is %d", a, b, sum(a,b));
}
