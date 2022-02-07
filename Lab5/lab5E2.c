/* Passing an array to a function. */

#include <stdio.h>
#include <string.h>

/***************************************
 * EECS203
 ****************************************/

#define MAX_INPUT 20
#define SIZE ((int)(sizeof(arr) / sizeof(arr[0])))
// more headers and declarations as needed

void display(int *arr,int);
int largest(int *arr,int);

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
  /* Call the function and display the return value. */
  printf("Inputs: ");
  display(array,count);

  printf("\nLargest value: %d\n", largest(array,count));

  return 0;
}

/* display a int array */

void display(int *arr,int a) {
  int i;
  while (i< a) {
    printf("%d ", *(arr + i));
    i++;
  }
  printf("\n");
}

/* Function largest() returns the largest value */
/* in an integer array */

int largest(int *arr,int a) {
  int i = 1;
  int max = *arr;
  while (i<a) {
    if (*(arr + i) > max) {
      max = *(arr + i);
    }
    i++;
  }
  return max;
}
