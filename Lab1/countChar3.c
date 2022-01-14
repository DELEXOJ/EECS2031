/***************************************
* EECS2031ON – Lab1 *
* Author: Ojo, Ayobami *
* Email: ayobami1@my.yorku.ca *
* eecs_username: ayobami1 *
* York Student #: 215281421
****************************************/


#include <stdio.h> // define EOF

int main(){
  int c;
  int count = 0;
 
  c = getchar();
  while(c != EOF) /* no end of file*/
  { 
      if (c !='\n')
      {
          count++;
      }
     //include spaces and '\n'

    c = getchar(); /* read next */
  }
  printf("# of chars: %d\n",count);

}
