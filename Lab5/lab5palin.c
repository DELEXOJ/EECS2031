#include <stdio.h>
#include <string.h>

/***************************************
 * EECS2031ON – Lab5 *
 * Author: OJO, AYOBAMI*
 * Email: ayobami1@my.yorku.ca *
 * eecs_num: ayobami1*
 * Yorku #: 215281421
 ****************************************/

#define SIZE 40

//... more headers and declaratiosn as needed
void printReverse(char *str) ;
int isPalindrome(char *str);
int isPalindromeR(char *str);

    int main() {
  int result;
  char c;
  int i;
  int count = 0;
  char arr[SIZE];

  fgets(arr, SIZE, stdin);
  while (strcmp(arr, "quit\n")) {
    // remove the trailing \n
    for (i = 0; i <= strlen(arr); i++) {
      if (arr[i] == '\n') {
        arr[i] = '\0';
      }
    }
    // print backward
   printReverse(arr);

   if (isPalindromeR(arr))
     printf("\nIs a palindrome.\n\n");
   else
     printf("\nNot a palindrome.\n\n");
   // printf("%ld",strlen(arr));
   //   ...
   fgets(arr, SIZE, stdin);
  }
  return 0;
}

// assume the \n was already removed manually
int isPalindrome (char * str)
{
int i=0; int j=strlen(str)-1;
while (i<j){
   if (*(str+i) != *(str+j))
   return 0;
   i++;
   j--;
}
return 1;
}

int isPalindromeR(char * str){
int j=strlen(str)-1; int i=0; 
int len=strlen(str);
// if (*(str+i)==*(str+j))
// {
//  if (i+1==j||i==j){
//      return 1;
//  }
//  isPalindromeR(str);
// }
// else{
//    return 0;
// }

if(len<=1){
   return 1;
}
else if (str[0]!=str[len-1]) {
return 0;
}
else{
  len=len-2;
isPalindromeR(str+1);

}
return 1;
}

// assume the \n was already removed manually
void printReverse(char * str)
{
int i;
int len=strlen(str);
for(i=len-1;i>=0;i--)
{
printf("%c",str[i]);
}
printf("\n");
}

