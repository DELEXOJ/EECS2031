#include <stdio.h>
#include <string.h>
#define SIZE 11
/********************
 ****************************************/

void sortParr(char *pArr[], int n);
void printParr(char *pArr[], int n);
void exchangeParr(char *pArr[]);

int main() {

  char * inputs[SIZE] = {"giraffes are high 0", "mosquitos are annoying 1",
  "monkeys are smart 2", "kangaroos are ugly 3"};

  char arr1 [] = "dogs are friendly 4";
  char arr2 [] = "hippos are huge 5";
  char arr3 [] = "cobras are scary 6";
  char arr4 [] = "fox 7";
  char arr5 [] = "elephants are heavy 8";
  char arr6 [] = "hens 9";
  char arr7 [] = "bison 10";

  inputs[4] = arr1;
  inputs[5] = arr2;
  inputs[6] = arr3;
  inputs[7] = arr4;
  inputs[8] = arr5;
  inputs[9] = arr6;
  inputs[10] = arr7;



  printf("sizeof char*: %d, sizeof pointer array: %d\n\n", sizeof(char*), sizeof inputs );

  // display the array by calling printParr

      printParr(inputs,SIZE);
  // swap pointee of first and second element pointers
  char *tmp = inputs[0];
  inputs[0] = inputs[1];
  inputs[1] = tmp;

  // call exchangeParr() to swap some other 'rows';
  exchangeParr(inputs);

  printf("\n== after swapping ==\n");   printf("===========================\n");

  // display the swapped array by calling printParr()
  printParr(inputs, SIZE);

  // call sortParr()
  sortParr(inputs, SIZE);
  printf("===========================\n");//to differntiatite the old printfwith the new one
  // display the sorted array by calling printParr()
  printParr(inputs, SIZE);
}

void exchangeParr(char *pArr[]){
  char *tmp = pArr[2];
  pArr[2] = pArr[3];
  pArr[3] = tmp;
}

void printParr(char *pArr[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("[%d] -*-> %s\n", i,pArr[i]);
  }
}

void sortParr(char *pArr[], int n){
  size_t i, j;
  char* smaller;
  for (i = 0; i < n; i++) {
   smaller= pArr[i];
    for (j = i + 1; j < n; j++) {
      if (strcmp(pArr[i],pArr[j])>0) {
        smaller = pArr[i];
        pArr[i] = pArr[j];
        pArr[j] = smaller;
      }
    }
  }
}
