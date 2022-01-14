/* Passing an array to a function. */

#include <stdio.h>
#include <string.h>

/***************************************
 * EECS2031ON â€“ Lab5 *
 * Author: OJO, AYOBAMI*
 * Email: ayobami1@my.yorku.ca *
 * eecs_num: ayobami1*
 * Yorku #: 215281421
 ****************************************/

#define MAX_INPUT 20
#define SIZE ((int)(sizeof(arr) / sizeof(arr[0])))
// more headers and declarations as needed

void display(int *arr, int);
void largest(int *arr, int a,int * max);

    int main(int argc, char *argv[]) {
  int array[MAX_INPUT], count;

  /* Input MAX_INPUT values from the keyboard. */
  int i;
  count = 0;
  int max =0;

  while (scanf("%d", &i) != EOF) {
    // store in array[count] without using []
    *(array + count) = i;
    count++;
  }
  /* Call the function and display the return value. */
  printf("Inputs: ");
  display(array, count);

  largest(array, count, &max);
   printf("\nLargest value: %d\n",max );

  return 0;
}

/* display a int array */

void display(int *arr, int a) {
  int i = 0;
  while (i < a) {
    printf("%d ", *(arr + i));
    i++;
  }
  printf("\n");
}

/* Function largest() returns the largest value */
/* in an integer array */

void largest(int *arr, int a,int *max) {
  int i = 1;
   *max = *arr;
  while (i < a) {
    if (*(arr + i) > *max) {
     * max = *(arr + i);
    }
    i++;
  }
  *max=*max;
}
