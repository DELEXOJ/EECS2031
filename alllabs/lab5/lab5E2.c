/* Passing an array to a function. */

#include <stdio.h>

#define MAX 20
 

int largest(int * x, int);
void display(int *arr, int);

 main(int argc, char *argv[])
 {
     int array[MAX], count;

     /* Input MAX values from the keyboard. */
     int i;  count=0;
     
     while ( scanf("%d", &i) != EOF){
        *(array + count) = i;
        count++;
     }

      /* Call the function and display the return value. */
      printf("Inputs: ");
      display(array, count);

  
     printf("\nLargest value: %d\n", largest(array, count));
     
     return 0;
 }
 

 void display(int *arr, int len)
 {
   int i=0;
   while ( i < len){
      printf("%d ", *(arr+i) ); 
       i++;
   } 
 }

 /* Function largest() returns the largest value */
 /* in an integer array */
 int largest(int * arr, int len)
 {
     int biggest = *arr; // first
     int i=1;
     while( i < len){
        int a = * (arr+i);
        if(a > biggest)
           biggest = a;
        i++;
     } 
     return biggest;
 }
