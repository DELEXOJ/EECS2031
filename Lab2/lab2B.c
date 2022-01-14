/***************************************
* EECS2031ON – Lab2 *
* Author: OJO, AYOBAMI *
* Email:ayobami1@my.yorku.ca *
* eecs_username: ayobami1 *
* York Student #: 215281421
****************************************/

#include <stdio.h>

int main(){

int c; int UpperC;

c = getchar();

while ( c != EOF )
{
if (c >= 'a' && c <= 'z') {
      UpperC = c + ('A' - 'a') ; 
}
else {
     UpperC = c;
}

putchar(UpperC); 
c = getchar(); 
}
}