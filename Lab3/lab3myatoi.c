/******************
****************************************/

#include <stdio.h>
#include <stdlib.h>  // for atoi

#define SIZE 10
 int length(char arr[]);
int my_atoi (char c[],int base);
int isQuit (char arr[]);
int len,lastnum,test;


int main(){
  int a,b,baseNum;
  char arr [SIZE];

  printf("Enter a word of positive number and base, or 'quit': " );
  scanf("%s %d", arr,&baseNum);
  while(isQuit(arr)==0)
  {
      length(arr);
    printf("%s\n", arr);
    // a = atoi(arr);
    // printf("atoi:    %d (%#o, %#X)\t%d\t%d\n", a,a,a, a*2, a*a);
    b = my_atoi(arr,baseNum);
    printf("my_atoi: %d (%#o, %#X)\t%d\t%d\n", b,b,b, b*2, b*b);
     printf("Enter a word of positive number and base, or 'quit':" );
  scanf("%s %d", arr,&baseNum);
  }

  return 0;

}

/* convert an array of digit characters into a decimal int */

/* textbook did scan from left to right.
 Here you should scan from right to left. This is a little complicated 
 but more straightforward (IMHO) */

int my_atoi (char c[],int base)
{
int i,n,ho,remain,newNum;
n=0;
ho=1;
lastnum=0;
newNum=0;
length(c);

test=0;

/*lastnum=c[len-1];
  lastnum=lastnum*10+c[len-1]-'0';
len--;
while (len!=-1)
{
  ho=ho*10+c[i]-'0';
  len--;
  i++;
}
return ho;
test=test+lastnum;*/
for(i=len-1;i>=0;i--){
    n=n*10+c[i]-'0';
}

 while (len != 0) {
        remain = n % 10;
       test=len-1;
       ho=1;
      while(test!=0){
          ho*=base;
          test--;
      }
        lastnum=lastnum+(ho*remain);
        newNum = newNum * 10 + remain;
        n /= 10;
        len--;
        
    }
   
return lastnum;

}
int length(char arr[])
{
     len =0;
     int i;
    for(i=0; arr[i]!='\0'; i++){
        len++;
    }
return len;
}

int isQuit (char arr[])
{
 int i;
 if (arr[0]=='q' && arr[1]=='u' && arr[2]=='i' && arr[3]=='t')
    return 1; 
 else 
    return 0;
}
