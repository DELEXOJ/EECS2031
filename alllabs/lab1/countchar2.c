#include <stdio.h> // define EOF

main(){
 int c;
 int count = 0;
 int countA = 0;
 c = getchar();
 while(c != EOF) /* no end of file*/
 { 
   count++; //include spaces and '\n'
   if (c == 'a') countA++;
   c = getchar(); /* read next */
 }
 printf("# of chars: %d\n",count);
 printf("# of char 'a': %d\n",countA);
}
