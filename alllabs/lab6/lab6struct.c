#include <stdio.h>
#include <stdlib.h>

struct ints
{ 
   int data1;
   int data2;
};


int getSum(struct ints);
void processStruc   (struct ints);
void processStruc2 (struct ints *); // correct version

struct ints getSumDiff(int, int);

main()
{
  
  struct ints a = {100,4};
  printf("-------- struct and function -----------------\n");
  // function that take structures as arguments
  printf("elements sum of a: %d\n", getSum(a));

  printf("struct a before process: %d %d\n", a.data1, a.data2);
  processStruc(a);
  printf("struct a after  process: %d %d\n", a.data1, a.data2);  
  processStruc2(&a);
  printf("struct a after  process2: %d %d\n", a.data1, a.data2);

  // functions that return a struct, encapsulating values 
  /**********************************  */
  int num1, num2;
  printf("\nEnter two integers: ");
  scanf("%d %d", &num1, &num2);
  struct ints s =  getSumDiff(num1, num2);
  int sum = s.data1;
  int diff = s.data2;
  printf("sum is: %d, diff is %d\n", sum, diff);
   /********************************** */
  printf("--------- array of structs ----------------\n");
  struct ints structArr[3] = {{1,2}, {3,4}};
  structArr[2].data1 = 5;
  structArr[2].data2 = 6;
  int i;
  for (i=0; i<3 ;i++ )
  {
      printf("arr[%d]: %d %d\n", i, structArr[i].data1, structArr[i].data2);
  }
  /********************************** */
  struct ints *p = malloc(sizeof(struct ints));
  p -> data1 = 777;    // via a, store data1 with value 777
  (*p).data2 = 888;    // via p, store data2 with value 888
  printf("\nTwo member values: %d %d\n", (*p).data1, p->data2 );
  
}   

/* call by value  */
int getSum(struct ints s){

  return s.data1 + s.data2;
 
}

/* call by value  */
void processStruc(struct ints x){

  x.data1 ++;
  x.data2 +=100;
}

/* the correct version */
void processStruc2(struct ints *x){

  x -> data1 ++;
  x -> data2 += 100;
}

struct ints getSumDiff(int a, int b){
  struct ints resu;
  resu.data1 = a+b;
  resu.data2 = a-b;
  return resu;
}