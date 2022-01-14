#include <stdio.h>

/* count characters excluding new line characters
   also count number of lines */

main(){
 int c, cC, lC;
 cC=lC=0;

 c = getchar();
 while(c != EOF)
 {
   if (c == '\n')  // a new line
     lC ++;
   else 
     cC++;
  
   c= getchar(); // read again
 }
 
 printf("# of chars: %d\n# of lines: %d\n", cC, lC);

}
