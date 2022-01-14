#include <stdio.h>

/* count characters, excluding new line char */

main(){
 char c; int cC, lC;
 cC=lC=0;

 c = getchar();
 while(c != EOF)
 {
   if (c != '\n') // char can be compared directly  
      cC ++;

   c= getchar(); // read again
 }
 
 printf("# of chars: %d\n", cC);

}
