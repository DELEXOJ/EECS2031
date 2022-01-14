#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printArr(int *, int);

int  main()
{ 
  char *p;
  int n, i;  int *my_array;
  printf("# of elements in int array: ");

  scanf("%d", &n);
  my_array = calloc (n, sizeof(int));
 /* or  my_array = (int*)malloc (n* sizeof (int)); */ 
   
  if (my_array == NULL){
    printf("memory allocation failed. Bye\n"); 
    exit(0);
  }


  *my_array = -10;
  for(i =1; i<n; i++)
    *(my_array+i) = i*100;

  printArr(my_array, n);
  
  p = malloc(6* sizeof(char));
  strcpy(p, "hello");
  printf("\n%s %d\n", p, strlen(p));
  *(p+2) = 'X';
  printf("%s\n", p); 
  return 0;
}

/* print first n elements in int array arr */
void printArr(int * arr, int n){
  int i;
  for(i=0;i<n ;i++) 
   printf("[%d]: %d\n", i, *(arr+i));
}
