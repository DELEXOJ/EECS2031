/***************************************
* EECS2031ON – Lab2 *
* Author: OJO, AYOBAMI *
* Email:ayobami1@my.yorku.ca *
* eecs_username: ayobami1 *
* York Student #: 215281421
****************************************/

#include <stdio.h>
#include<string.h>

#define SIZE 10

int main () {

  int k[SIZE]={0};
  int i=0;
  for (i=0; i< SIZE; i++)  
    printf("k[%d]: %d\n", i, k[i]);

  char msg[]="Hello world";
  printf("\nmsg: %s\n", msg);
  printf("memory size of msg: %ld (bytes)\n", sizeof(msg));
  printf("strlen of msg: %ld\n", strlen(msg));
  /* your code here to print element */
  for (i = 0; i < sizeof(msg); i++)
  {
      /* code */
      printf("msg[%d]\t%d\t%c\n",i,msg[i],msg[i]);
  }
  

  msg[3] = 'x';
  printf("\nmsg: %s\n", msg);
  printf("memory size of msg: %ld (bytes)\n", sizeof (msg));
  printf("strlen of msg: %ld\n", strlen(msg));

  /**********************************/
  char msg2[2*SIZE] = "Hello world";
  printf("\nmsg2: %s\n", msg2); 
  printf("memory size of msg2: %ld (bytes)\n", sizeof(msg2));
  printf("strlen of msg2: %ld\n", strlen(msg2));
  
  /* your code here to print element */
  for (i = 0; i < sizeof(msg2); i++)
  {
      /* code */
     printf("msg2[%d]\t%d\t%c\n",i,msg2[i],msg2[i]);
  }
 
  msg2[3] = '\0';
  printf("\nmsg2: %s\n", msg2); // stop at first '\0'
  printf("memory size of msg2: %ld (bytes)\n", sizeof(msg2));
  printf("strlen of msg2: %ld\n", strlen(msg2));  // stop at first '\0'
  
  // but can still access individul elements, including those after first '\0'
  printf("%c %c %c %c %c %c\n", msg2[0], msg2[1], msg2[4], msg2[6], msg2[8], msg2[10]);

  /**********************************/   
  char msg3[2*SIZE];
  printf("\nEnter a string: ");
  scanf("%s",msg3);
  printf("msg3: %s\n",msg3);
  printf("memory size of msg3: %ld (bytes)\n", sizeof(msg3));
  printf("strlen of msg3: %ld\n", strlen(msg3));
 for (i = 0; i < sizeof(msg3); i++)
  {
      /* code */
     printf("msg3[%d]\t%d\t%c\n",i,msg3[i],msg3[i]);
  }

  return 0;
}
