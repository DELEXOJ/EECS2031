/*****************
****************************************/

#include <stdio.h>
#define N 10
int main () {
int c, i,count,x;
int digit[N];

 for (i=0; i< N; i++)
 digit[i]=0;
while ((c= getchar())!= EOF) {
if (c>='0' && c<='9')

++digit[c-'0'];
 
}    
    
for (i=0; i< N; i++)
    printf("%d: %d \n", i, digit[i]);
    printf("\n");

}
