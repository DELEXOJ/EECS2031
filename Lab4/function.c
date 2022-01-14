#include <stdio.h>

// define global variables and a function
double sum,resu,result;
int count;

void r_avg (void)
{
result+=sum;
    resu = result/count ;
    printf("running average is %.0f / %d = %.3f\n",result,count,resu);
}
