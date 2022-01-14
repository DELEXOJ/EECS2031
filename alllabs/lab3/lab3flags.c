#include <stdio.h>

#define SIZE 16
void printBinary(short int n );
/*counting digits*/

int main () {
  int c, i, v;
  short flags = 0;
  printf("flags: ");printBinary(flags); printf("\n\n");

  while ((c = getchar()) != EOF){
    if ( c>= '0' && c <= '9' ){
       v = c - '0';  // numerical value
       flags = flags | (1 << v); // turn bit 'v' on
    }//else do nothing 
  }

  printf("\nflags: "); printBinary(flags); printf("\n");
  // output right most 10 bits, bit by bit
  for(i=0; i<=9; i++)  {
    int check = flags & (1 << i);
    if ( check ) 
      printf("%d: %s\n", i, "yes");
    else printf("%d: %s\n", i, "no");
  } 

   // anther way to retrieve the bits
   // output2
  printf("------------------\n");
  for(i=0; i<=9; i++)  {
    if ( (flags >> i) & 1)
      printf("%d: yes\n", i);
    else printf("%d: no\n", i);
  }

 return 1;  
  

 }

void printBinary(short int n ){
   //printf("binary: ");
   int cou = SIZE-1;
   int k[SIZE]={0};

   while (n) {
      if (n & 1)
         k[cou]=1; //printf("1");
      else
         k[cou]=0; //printf("0");

      n >>= 1; 
      cou--;
   }
   int i=0;
   for(; i< SIZE;i++)
   {
      printf("%d", k[i]);
      if ((i+1)%8==0)
      {
         printf(" ");
      }
   }
}