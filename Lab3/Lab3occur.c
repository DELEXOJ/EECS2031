/***************************************
* EECS2031ON – Lab3 *
* Author: Ojo, Ayobami *
* Email: ayobami1@my.yorku.ca *
* eecs_username: ayobami1 *
* york_num: 215281421 *
****************************************/

#include <stdio.h>

#define MAX_SIZE 20


int length(char arr[]);
int indexOf(char arr[], char c);
int occurrence(char arr[], char c);
int isQuit (char arr[]);

int main() {

   char word[MAX_SIZE];
   char c;

   char helloArr[]  = "helloWorld";
   printf("\"%s\" contains %d characters, but the size is %ld (bytes)\n", helloArr, length(helloArr), sizeof(helloArr));
   helloArr[5] = '\0'; helloArr[3]='X'; helloArr[7] ='Y';
   printf("\"%s\" contains %d characters, but the size is %ld (bytes)\n\n", helloArr, length(helloArr), sizeof(helloArr));


   /********** Fill in your code here. **********/
   printf("Enter a word and a character separated by blank: ");
   scanf("%s %c", word, &c);

   while (isQuit(word)==0) 
   {  
printf("Input word is \"%s\". Contains %d characters\n",word,length(word));
printf("'%c' appears %d times in the word\n",c,occurrence(word,c));
printf("Index of '%c' in the word is %d\n",c,indexOf(word,c));
printf("Enter a word and a character separated by blank: ");
   scanf("%s %c", word, &c);
   }
}

int length(char arr[])
{
    int len =0;
    int i;
    for(i=0; arr[i]!='\0'; i++){
        len++;
    }
return len;
}

int indexOf(char arr[], char c)
{
   int i;
      for( i=0; arr[i]!='\0'; i++){
         while(arr[i]==c)
          {
             return i;
          }
        }
        return -1;
}

int occurrence(char arr[], char c)
{
int timesAppered = 0;
int i;
      for(i=0; arr[i]!='\0'; i++){
       if (arr[i]==c)
       {
        timesAppered++;   
       }
       
    }
 return timesAppered;
}

int isQuit (char arr[])
{
 int i;
 if (arr[0]=='q' && arr[1]=='u' && arr[2]=='i' && arr[3]=='t')
    return 1; 
 else 
    return 0;
}