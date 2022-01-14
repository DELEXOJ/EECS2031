#include <stdio.h>

#include <stdlib.h> 
#include <string.h> /* for strlen() */

#define SIZE 10
 
int my_atoiHex (char c[]);  /* function declaration */
int length(char []);
double my_pow(int base, int exp);
   
int main(){
 int a,b;
 char arr  [SIZE];
 char argu [SIZE];

 printf("Enter a word of postive number or 'quit': " );
 scanf("%s", arr);
 while(strcmp(arr,"quit"))
 {
   printf("%s\n", arr);
   int i;

   a = atoi(arr);
   printf("atoi:    %d (%#o, %#X)\t%d\t%d\n", a,a,a, a*2, a*a);
  
   a= my_atoiHex(arr);
   printf("my_atoi: %d (%#o, %#X)\t%d\t%d\n", a,a,a, a*2, a*a);

   /* read again */
   printf("\nEnter a word of postive number or 'quit': " );
   scanf("%s", arr);
 }

 return 0;

}

/* convert an array of digit characters into a decimal int */

/* the textbook scans from left to right.
 Here I scan from right to left. This is a little harder but more straightforward */


// this get bouns marks Decimal  + Octal + Hex
int my_atoiHex (char c[]){

  int current_value=0;
  int len = length(c);


  int pos = len-1;   /* scan from right to left */
  int pw = 0;  // power of 10
  // if (c[0] != '0'){
  //  while (pos >=0)
  //  {
  //    int v = c[pos] -'0';

  //    current_value += v * my_pow(10, pw);

  //    pos --;   /* go left further */
  //    pw++;
  //  }
  // }
  // else 
  if (c[0]=='0' && (c[1]=='X' || c[1]=='x')){ // Hex
     while (pos >1)
     {
      int v;
      if (c[pos] >='0' && c[pos] <='9')
        v = c[pos] -'0';
      else if (c[pos]>='A' && c[pos]<='F') v= c[pos] - 'A' + 10;
      else if (c[pos]>='a' && c[pos]<='f') v= c[pos] - 'a' + 10;
     
      current_value += v * my_pow(16, pw);

      pos --;   /* go left further */
      pw++;
    }


  }else{
 while (pos >=0)
  //  {
  //    int v = c[pos] -'0';

  //    current_value += v * my_pow(10, pw);

  //    pos --;   /* go left further */
  //    pw++;
  //  }
  }

  return current_value;
}

  
// an iterative solution. Assume p is >= 0
double my_pow(int base, int p){
     
  if (p ==0)
    return 1;
  int i;
  double res = base;
  for(i = 1; i< p; i++){
    res *= base;
  }
  return res;
}

int length(char arr[]){
  int i=0;
  while (arr[i]!= '\0')
    i++;
  return i;
}
  

