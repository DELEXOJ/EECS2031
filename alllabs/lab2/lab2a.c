#include <stdio.h>

int isDigits(char);

int main(){
 int a, b;
 char c;

 printf("Enter an integer and a character separated by blank: " );
 scanf( "%d %c",  &a,&c);

 while (a != -10000 ){
   if (isDigits(c)){
      int sum = a + (c-'0');  // don't use c-48
      printf("Character '%c' represents a digit. Sum of %d and %c is %d\n", c, a,c, sum);
   }
   else printf("Character \'%c\' does not represent a digit\n",c);

   printf("\nEnter an integer and a character separated by blank: " );
   scanf("%d %c", &a,&c);

 }
 return 0;
 

}

int isDigits (char c){
  if (c >= '0' && c <= '9')   // don't use c >= 48 && c <= 56
   return 1;
  else return 0;
}    
 