/* Passing an array to a function. */

#include <stdio.h>

#define MAX 20
 

int largest(int * x);
void display(int *arr);

 main(int argc, char *argv[])
 {
     int array[MAX], count;

     /* Input MAX values from the keyboard. */
     int i;  count=0;
     
     while ( scanf("%d", &i) != EOF){
        *(array + count) = i;
        count++;
     }
     *(array+count) = -100; // a sentinel token, any negative number 

      /* Call the function and display the return value. */
      printf("inputs: ");
      display(array);

     printf("\nLargest value: %d\n", largest(array));
     
     return 0;
 }
 
 /* Display an int array, which is terminated by a negative number */
 void display(int *arr)
 {
   int i=0;
   while ( * (arr+i) >= 0){
      printf("%d ", *(arr+i) ); 
      i++;
   } 
 }

 /* Function largest() returns the largest value */
 /* in an integer array , which is terminated by a negative number */
 int largest(int * arr)
 {
     int biggest = *arr; // first
     int i=1;
     while( *(arr+i) >= 0){
        int a = * (arr+i);
        if(a > biggest)
           biggest = a;
        i++;
     } 
     return biggest;
 }
