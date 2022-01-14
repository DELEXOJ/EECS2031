#include<stdio.h>

/*copying input to output with converting lowercase to upper-case letters 
*/
main(){
  int c;
  c= getchar();
  while (c != EOF) 
  {
   if (c>='a' && c<='z')
     c = c - ('a'- 'A');  /* c - ('b'-'B') */ 
   putchar(c);            /* c - ('c'-'C') */ 
                         /* don't use c-32 */
   c=getchar(); // read again  
  }
  return 0;
}
