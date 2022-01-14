#include <stdio.h>
#include <stdlib.h>
/***************************************
 * EECS2031ON – Lab6 *
 * Author: OJO, AYOBAMI*
 * Email: ayobami1@my.yorku.ca *
 * eecs_num: ayobami1*
 * Yorku #: 215281421
 ****************************************/

void insertBegining(int);

struct node { 
   int data;
   struct node * next;
};

struct node * head; 

int main()
{
   head = NULL;

   insertBegining(100);
   insertBegining(200);
   insertBegining(300);
   insertBegining(400);   
   insertBegining(500);

   int i; 
   struct node * cur;
   for(cur= head; cur != NULL; cur= cur->next)
     printf("%d ", cur->data);
   printf("\n");  
}   

void insertBegining(int dat){
   struct node newNode;
  // newNode=malloc(sizeof(struct node));
   newNode.data = dat;

   newNode.next = head;
   
   head = &newNode;

}
