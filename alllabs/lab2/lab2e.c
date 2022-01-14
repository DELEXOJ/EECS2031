#include <stdio.h>

#define MAX_SIZE 20


int indexOf(char[], char);
int occurrence(char[], char);
int length(char[]);
int isQuit(char []);
 
main() {

   char word[MAX_SIZE];
   char c;

   char helloArr[]  = "helloWorld";
   printf("\"%s\" contains %d characters, but the size is %d (bytes)\n", helloArr, length(helloArr), sizeof(helloArr));
   helloArr[5] = '\0'; helloArr[3]='X'; helloArr[7] ='Y';
   printf("\"%s\" contains %d characters, but the size is %d (bytes)\n\n", helloArr, length(helloArr), sizeof(helloArr));

   /********** Fill in your code here. **********/
   printf("Enter a word and a character separated by blank: ");
   scanf("%s %c", word, &c);

   while (! isQuit(word))  // != 'quit' does not work   
   {  
     printf("Input word is \"%s\". Contains %d input characters\n", word,length(word)); 
     printf("'%c' appears %d times in the word\n", c, occurrence(word,c));
     printf("Index of '%c' in the word is %d\n\n", c, indexOf(word,c));
   
     // read again
     printf("Enter a word and a character separated by blank: ");
     scanf("%s %c",word, &c); // read again
  }
}

int length(char arr[]){
  int i=0;
  while (arr[i]!= '\0')
    i++;
  return i;
}

int indexOf(char arr[], char c){
 int i;
 for(i=0; arr[i]!= '\0'; i++)
 { 
   if(arr[i] == c)
     return i; // done
 }
 return -1;
 
}

int occurrence(char arr[], char c){
 int count=0; int i=0;
 for(i=0; arr[i]!= '\0'; i++)
 {
   if(arr[i] == c)
     count++; // done
 }
 return count;

}



int isQuit (char arr[]){

 int i;
 if (arr[0]=='q' && arr[1]=='u' && arr[2]=='i' && arr[3]=='t' && arr[4]=='\0')
  return 1; 
 else return 0;
}
