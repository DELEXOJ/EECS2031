#include <stdio.h>


float calIntFloat(int, char,float);
float calIntInt (int, char,int);
float calFloatFloat (float, char,float);

main(){

 int op1; float op2;  char operator;
 float resu, resu2, resu3;

 float a = 9/2;
 float b = 9*1.0/2;  // force 9 to be converted before /
 float c = 9/2*1.0;  // force 2 to be converted before /, but not working
 float c2 = 9/(2*1.0); // force 2 to be converted before /
 float d = (float)9/2;  // cast 9 before /
 float e =  9/(float)2; // cast 2 before /
 float f = (float) (9/2); // cast after /, not working
 printf("9/2=%f  9*1.0/2=%f  9/2*1.0=%f   9/(2*1.0)=%f\n\n", a, b, c, c2);
 printf("(float)9/2=%f  9/(float)2=%f  (float)(9/2)=%f\n\n", d, e, f);


  // conversion in arithemetic
 printf("3.0*9/2/4=%f  9/2*3.0/4=%f  9*3/2*3.0/4=%f\n", 3.0*9/2/4, 9/2*3.0/4, 9/2*3.0/4);
 
 // conversion in assignment
 float f2  = 3.96;
 float f3 = 3.03;
 int i = f2; int j = f3;
 printf("i: %d  j: %d\n", i, j);

 // conversion across function call
 while(1){
   printf("Enter operand1 operator operand2 separated by blanks> " );
   scanf( "%d %c %f",  &op1, &operator, &op2); // assign value to a b
  
   if (op1 == -1 && op2==-1) 
      break;
   resu = calIntFloat(op1, operator,op2);
   resu2 = calIntInt(op1,operator, op2); 
   resu3 = calFloatFloat(op1,operator, op2);

   printf("Your input '%d %c %f' result in\n%f (fun_IF)\n%f (fun_II)\n%f (fun_FF)\n\n",op1, operator, op2, resu,resu2, resu3);

 } 


}
 
float calIntFloat(int op1, char operator, float op2)
{
   float resu; 
   if(operator == '+')
     resu = op1 + op2;
   else if (operator == '-')
     resu = op1 - op2;
   else if (operator == '*')
     resu = op1 * op2;
   else resu = op1 / op2;

   return resu;
}

float calIntInt(int op1, char operator, int op2)
{  
   float resu;
   if(operator == '+')
     resu = op1 + op2;
   else if (operator == '-')
     resu = op1 - op2;
   else if (operator == '*')
     resu = op1 * op2;
   else resu = op1 / op2;

   return resu;
}

float calFloatFloat(float op1, char operator, float op2)
{
   float resu;
   if(operator == '+')
   resu = op1 + op2;
   else if (operator == '-')
     resu = op1 - op2;
   else if (operator == '*')
     resu = op1 * op2;
   else resu = op1 / op2;

   return resu;
}

/*
conversion happens in 1) arithmetic expression, 2)assignment,  3)function call, and 4)function return.
for 12 + 22.3024
In calII(), the 2nd actual argument is converted from float to int (case 3). so 12+22=34, then the int result is converted to float 34.000000 (case 2 or 4)
In calIF(), no conversion in argument, then in arithmetic expression 12+22.302400, 12 is promoted to 12.000000 (case 1). so 12.000000+22.302400 
In calFF(), in function call, 12 is converted to float (case 3), so 12.00000+22.3024.

Note that for calIF calFF the result should be 34.302400 but the output is off by a small value, becoming 34.302399, due to the nature that real number is represented.
This is not related to our study here.  

*/