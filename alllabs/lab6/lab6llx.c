/***********************************
* CSE2031 - Lab 6
* Filename: lab6LLX.c
* Author: Last name, first name
* Email: Your email address
* cse_num: Your cse number
************************************/

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 50
#define MAX_LEN 30

struct integers
{
  int int1;
  int int2;
};

struct node {  // list 'node' struct
   char data;
   struct node *next;
};


void init( );
void display();
int len();
int search(char);
char get(int);
void insert(char d );
void insertAfter(char key, int index);
void delete0 (char d);
void delete (char d);
void deleteEnh (char d);




struct node * head;   // global variable, the head of the linkedlist

int main()
{
    int i, index; char key;

    struct integers arr[MAX_LEN]; // an array of ten structs

    char buffer[BUFFER_SIZE];
    int value1, value2;
    int count= 0;

    FILE * file;
    file = fopen("data.txt", "r");

    while (fgets(buffer, BUFFER_SIZE, file) != NULL)     // or  while (fscanf(file, "%d %d", &value1, &value2) == 2)
    {
       sscanf(buffer, "%d %d", &value1, &value2);   // tokenize buffer and store into value1 and value2

       arr[count].int1 = value1;
       arr[count].int2 = value2;
       count++;
    }

    fclose(file);

    /* print the array of structures */
    for(i=0; i< count; i++){
        printf("arr[%d]: %d %d\n", i, arr[i].int1, arr[i].int2);
    }

    // now building up the list by reading from the array of structures
    printf("\n");
    init();

    i=0;
    for(; i< count; i++){
        struct integers current = arr[i];
        int value = current.int1 + current.int2; 
char c = value;
        insert(c); //or value directly 
        printf("insert %c: (%d)", value, len());
        display();
    }

    char removeList [] = {'B','S','A','O','R','K','Y','U','L','\0'}; // \0 is the terminating token
    i=0;
    while ( (key=removeList[i]) != '\0'){
        delete(key);
        printf("remove %c: (%d)", key, len()); display();
        i++;
    }

    // insert again
    char addList [] = "YORKULABS"; 
    i=0;
    while ( (key=addList[i]) != '\0'){ 
        insert(key);
        printf("insert %c: (%d)", key, len());
        display();
        i++;
    }

    // insert after
/*    printf("\n");
    key =-4; index =2; insertAfter(key,index);
    printf("insert %d after index %d: (%d)\t", key,index,len()); display();
    key =-6; index = 0; insertAfter(key,index);
    printf("insert %d after index %d: (%d)\t", key,index,len()); display();
    key =-8; index = 6;insertAfter(key,index);
    printf("insert %d after index %d: (%d)\t", key,index,len()); display();
*/
    // search
 /*   printf("\n");
   int searchList [] = {5,50,9,19,0,-4, -10000}; // -10000 is the terminating token
    i=0;
    while ( (key = searchList[i++]) != -10000 ){
		 
        printf("search %3d ....  ", key);
        
        if (search(key))
            printf("found\n");        else
            printf("not found\n");
        //i++;
    }
*/

    int v = get(0);  printf("\nget(0): %c\n", v);
    v = get(3);  printf("get(3): %c\n", v);
    v = get(6);  printf("get(6): %c\n", v);
    v = get(7);  printf("get(7): %c\n", v);
    v = get(8);  printf("get(8): %c\n", v);

    key ='x'; index =2; insertAfter(key,index);
    printf("\ninsert %c after index %d: (%d)\t", key,index,len()); display();
    key ='y'; index = 0; insertAfter(key,index);
    printf("insert %c after index %d: (%d)\t", key,index,len()); display();
    key ='z'; index = 6;insertAfter(key,index);
    printf("insert %c after index %d: (%d)\t", key,index,len()); display();

    v = get(0);  printf("\nget(0): %c\n", v);
    v = get(3);  printf("get(3): %c\n", v);
    v = get(6);  printf("get(6): %c\n", v);
    v = get(7);  printf("get(7): %c\n", v);
    v = get(8);  printf("get(8): %c\n\n", v);


}

/* Initialize the list. */
void init( )
{
    head = NULL;
}



/* Print the content of the list. */
void display()
{
    struct node *current = head;
    while (current != NULL){
       printf( "%3c", current->data );
       current = current -> next;
    }printf( "\n" );

}

/* return the length of the linked list */
int len()
{
    struct node * current = head;
    int count=  0;
    while (current != NULL)
    {
       count++;
       current = current -> next;
    }
    return count;
}


char get(int index){
    struct node * current = head;

    int i = 0;
    while (i < index){
        current = current -> next;
        i++;
    }
       
    return current -> data;


}

int search (char key)
{
    struct node * current = head;

    while (current != NULL ){
       if (current->data == key)
         return 1; // found it!
       
       current = current -> next;
    }
    return 0;
}

/* Insert a new data element with key d into the end of the list. */
void insert(char c )  //  at the end
{
    struct node * newP = malloc (sizeof(struct node));
    newP -> data = c;

    /* special case: list is empty, need to change head  */
    if (head == NULL){/* the list is empty */
        newP -> next = head;   // or newP->next = NULL
        head = newP;
    }
    else{  // general case, insert at the end.
        struct node * current = head;

        /* traverse to the end node */
        while (current -> next != NULL)
        {
            current  = current -> next;
        }
       /* now at the end node */
       newP-> next = current->next;  // or newP->next = NULL
       current-> next = newP;

    }

 }

/* assume the list is not empty */
/* insert a new node with data d after the node of index 'where'*/
void insertAfter(char c, int index)  //  insert in the middle
{
    struct node * newP = malloc (sizeof(struct node));
    newP -> data = c;

    struct node * current = head;

    int i = 0;
    while (i < index){
        current = current -> next;
        i++;
    }

    // now current points to node of 'where'
    /* insert between current  and current->next */
    newP->next = current->next;  // point to the one after current
    current->next = newP;

 }

/* lab version */
/* Remove the node with value d from the list */
/* assume the list is not empty */
/* assume no duplicated keys in the list */
/* assume the node to be deleted is in the list */
/* also do not free the space */
void delete0(char d)
{
   /* special case: to be removed is the first, need to change head  */
   if (head -> data == d){
        head = head -> next;  // head == NULL if empty after deletion
    }

   else  // general case, remove from the middle or the last
    {
        struct node * current = head;
        while ( current -> next-> data != d )
            current  = current  -> next;

        current -> next = current->next->next;  /* by pass the node to be deleted */
    }
}

/* lab version + free space */
/* Remove the node with value d from the list */
/* do not assume the list is not empty. if empty, give error message  */
/* assume no duplicated keys in the list */
/* assume the node to be deleted is in the list */
/* free the space */
void delete(char d)
{
   
   if (len() == 0){

       fprintf(stderr, "empty");  /* send to stderr, using fprintf(stderr, ...)  */
       return; //exit(0);
   }
   /* special case: to be removed is the first, need to change head  */
   if (head -> data == d){
        struct node * tmp = head;
        head = head -> next; 
        free(tmp);
    }

   else  // general case, remove from the middle or the last
    {
        struct node * current = head;
        while ( current -> next-> data != d )
            current  = current  -> next;
        
        struct node * tmp = current -> next;
        current -> next = current->next->next;  /* by pass the node to be deleted */
        free(tmp);
    }
}




/* This enhanced version does not assume the list is non-empty, and do not assume the node to be deleted is in the list, also free 
the space occupied by the deleted node */

/* Remove the node with value d from the list */
/* assume no duplicated keys in the list */
/* assume that the list might be empty. If the list is empty, display an error message and return -1. */
/* the node to be deleted might not in the list. In this case, nothing happens.
/* free the space */

void deleteEnh(char d)
{
   if (len() == 0){

       fprintf(stderr, "empty");  /* send to stderr, using fprintf(stderr, ...)  */
       return; //exit(0);
   }

   /* special case: to be removed is the first  */
   if (head -> data == d)
   {
       struct node * tmp = head;
       head = head -> next;
       free(tmp);
    }
    else{  // general case,
        struct node * current = head;
        
        /* since we don't assume that the node is in the list, need to check current->next !=NULL, as we might end up 
        at the last node (when not found) */
        while ( current -> next != NULL && current -> next-> data != d ) 
            current  = current  -> next;

        // now out of loop, two cases: might at the last node current->next == NULL (not found), 
        // or before the one to be deleted (found) current->next ->data == d
        if (current -> next != NULL){   // current->next->data=d, found, now before it, to delete it
           struct node * tmp = current -> next;
           current -> next = current->next->next;  /* by pass the node to be deleted */
           free (tmp);
        }
        //else  current -> next == NULL, at the last node, not found, do nothing!
    }

}