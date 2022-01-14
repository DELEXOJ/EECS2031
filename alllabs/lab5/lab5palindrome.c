#include <stdio.h>
#include <string.h>


int isPalindrome (char *);
int isPalindrome2 (char *);
int isPalindrome3 (char *);

int isPalindromeRec(char *);
int isPalindrome_helper(char*, int);

void printReverse (char *);

int main ()
{   
   int result;  char c;
   char arr[40];
  
   fgets(arr,40,stdin);
   while ( strcmp(arr, "quit\n"))
   {
      arr[strlen(arr)-1] = '\0'; // remove the trailing \n

      // print backward
      printReverse(arr);
   
      result = isPalindromeRec (arr);
      if (result==1) 
         printf ("\nIs a palindrome.\n\n");
      else 
         printf ("\nNot a palindrome.\n\n");
 
      fgets(arr,40,stdin);
    }
    
    return 0;
}


void printReverse(char * str){
  int i;
  for (i= strlen(str)-1; i >=0 ; i--)
     putchar(*(str+i)); 
    // or printf("%c", *(str+i) );
}


int isPalindrome (char * str)
{
    int i;
    int length = strlen(str);
    if (length<1) return 1; // no more chars to compare, its palindrome

   
    for (i=0; i<length/2; i++)
    {
      char a =  *(str+i) ;
      char b =  *(str + length-1-i)  ;

      if (a != b)
         return 0;
    }
	 
    return 1;
}

int isPalindrome2 (char *str)
{
    int length = strlen(str);
    int i=0; int j = length-1;
    while ( i < j)
    {
       if (*(str+i) != *(str+j)) 
          return 0;
       i++;
       j--;
    }
    return 1;
 }

int isPalindrome3 (char * str){   /* another pointer verison, which I like  */
    int len = strlen(str);
    char * end = str + len -1;   /* create a local pointer, which point to the end of the input */
    int i;
    while( str < end)
    {
        if ( * str != * end  ) 
           return 0;
        str ++;    /* move str to the right */
        end --;    /* move end to the left  */
     }
     return 1;
}


// recursive solution
int isPalindromeRec (char * str) {
     int leng = strlen(str);
     return isPalindrome_helper(str, leng);
}

int isPalindrome_helper(char * str, int leng){

    if (leng == 0)
        return 1;
    else if (leng == 1)
        return 1;
    else{
        if(str[0] != str[leng-1]){
            return 0;
        }
        else{ // depends on the substring
            return isPalindrome_helper(str+1, leng-2);
        }
    }// end else if 
} // end isPalinrome // assume the \n was already removed manually 
