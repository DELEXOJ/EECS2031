/***************************************
* EECS2031ON – Lab2 *
* A
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
