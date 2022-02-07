/************************************
****************************************/

#include <stdio.h>


float fun_IF(int op1, char operator, float op2);
float fun_II(int op1, char operator, int op2);
float fun_FF(float op1, char operator, float op2);

float operation;

int main(){

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
 printf("3.0*9/2/4=%f  9/2*3.0/4=%f  9*3/2*3.0/4=%f\n\n", 3.0*9/2/4, 9/2*3.0/4, 9/2*3.0/4);
 
 // conversion in assignment
 float f2  = 3.96;
 float f3 = 3.03;
 int i = f2; int j = f3;
 printf("i: %d  j: %d\n", i, j);
 int x;
 float z;
 char y;

 //---------------------------------------
// .....
  printf("Enter operand_1 operator operand_2 separated by blanks> ");
  scanf("%d %c %f", &x, &y, &z);

  while(operation>=1){
  printf("Your input '%d %c %f ' result in \n ",x,y,z);
  printf("%f (fun_IF)\n ",fun_IF(x,y,z));
  printf("%f (fun_II)\n ",fun_II(x,y,z));
  printf("%f (fun_FF)\n",fun_FF(x,y,z));

  /* 
    fun_IF and fun_FF is the same output because in fun_FF the int vaule is converted to float before the calculation.
    while in fun_II the convertion to float is done after the calculation.
  */

   printf("Enter operand_1 operator operand_2 separated by blanks> ");
  scanf("%d %c %f", &x, &y, &z);

  }
}
 
float fun_IF(int op1, char operator, float op2)
{
     operation=0;

    if (operator=='+')
    {
    operation=op1+op2;    
    }
    else if (operator=='-'){
         operation=op1-op2;
    }
    else if (operator=='/'){
        operation=op1/op2;
    }
    else if (operator=='*'){
        operation=op1*op2;
    }
    return operation;
}

float fun_II(int op1, char operator, int op2)
{  
     operation=0;

    if (operator=='+')
    {
    operation=op1+op2;    
    }
    else if (operator=='-'){
         operation=op1-op2;
    }
    else if (operator=='/'){
        operation=op1/op2;
    }
    else if (operator=='*'){
        operation=op1*op2;
    }
    return operation;
    
}

float fun_FF(float op1, char operator, float op2)
{
  operation=0;

    if (operator=='+')
    {
    operation=op1+op2;    
    }
    else if (operator=='-'){
         operation=op1-op2;
    }
    else if (operator=='/'){
        operation=op1/op2;
    }
    else if (operator=='*'){
        operation=op1*op2;
    }
    return operation;
   
}


 
