#include <stdio.h>

#include <math.h>

/***************************************
 * EECS2031ON – Lab5 *
 * Author: OJO, AYOBAMI*
 * Email: ayobami1@my.yorku.ca *
 * eecs_num: ayobami1*
 * Yorku #: 215281421
 ****************************************/

double my_pow(double base, double power) ;

int main(int argc, char *argv[]) {

  double base;
  int exponent;
  printf("enter base and power: ");
  scanf("%lf %d", &base, &exponent);

  while (base != -1000) {
    double res = pow(base, exponent);
    double res2 = my_pow(base, exponent);
    printf("pow:    %.4f\n", res);
    printf("my_pow: %.4f\n", res2);

    printf("enter base and power: ");
    scanf("%lf %d", &base, &exponent);
  }

  return 0;
}

// this function should be RECURSIVE
// should not use any loop here
double my_pow(double base, double power)
{
  if(power ==0){
       return 1;
  }else{
       return base * pow(base, power-1);
  }
}
