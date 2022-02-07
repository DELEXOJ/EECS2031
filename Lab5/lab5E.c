/* Passing an array to a function. */

#include <stdio.h>
#include <string.h>

/********************
 ****************************************/

#define MAX_INPUT 20
 #define SIZE ((int)(sizeof(arr)/sizeof(arr[0])))
// more headers and declarations as needed

void display(int *arr);
int largest(int *arr);

    int main(int argc, char *argv[]) {
  int array[MAX_INPUT], count;

  /* Input MAX_INPUT values from the keyboard. */
  int i;
  count = 0;

  while (scanf("%d", &i) != EOF) {
    // store in array[count] without using []
    *(array + count) = i;
    count++;
  }
// printf("arg %d\n", argc);
// for (i = 0; i < argc;i++){
//     printf("argv[%d]: %s\n",i,argv[i]);
// }
  /* Call the function and display the return value. */
  printf("Inputs: ");
  display(array);

   printf("\nLargest value: %d\n", largest(array));

  return 0;
}

 /* display a int array */

 void display(int *arr)
 {
    //  int count=sizeof(arr);
     //int count=(int)(sizeof(arr)/sizeof(arr[0]));
   // int count = *(arr+1)-arr;
    // size_t count=sizeof(arr)/sizeof(arr[0]);
    // printf("%ld", count);
      int i;
      while (*(arr + i) >= 0) {
        printf("%d ", *(arr + i));
        i++;
      }
      printf("\n");
 }


/* Function largest() returns the largest value */
 /* in an integer array */

 int largest(int * arr)
 {
   int i=1;
   int max=*arr;
   while (*(arr + i) >= 0) {
     if (*(arr + i) >max) {
         max = *(arr + i);
     }
     i++;
   }
  return max;
 }

