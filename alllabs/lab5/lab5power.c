#include <stdio.h>
#include <math.h>

double my_pow(double, double);

int main(int argc, char *argv[])
{
	
   double base; int power;  
   printf("enter base and power: ");
   scanf("%lf %d", &base, &power);

   while (base != -100){
        double res = pow(base, power);
        double res2 = my_pow(base, power);
        printf("pow:    %.4f\n", res);
        printf("my_pow: %.4f\n", res2);


        printf("enter base and power: ");
        scanf("%lf %d", &base, &power);
    }
	
    return 0;
}

// recursive solution
double my_pow(double base, double p)
{
    if (p==0) return 1; // base case
    else if (p < 0)
      return 1/my_pow(base, -p);  // another slu:  return 1/base * my_pow(base, p+1); 
    
    else return base * my_pow(base, p-1);
}
