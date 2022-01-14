/***************************************
 * EECS2031ON – Lab6 *
 * Author: OJO, AYOBAMI*
 * Email: ayobami1@my.yorku.ca *
 * eecs_num: ayobami1*
 * Yorku #: 215281421
 ****************************************/
// Inputs a list of strings from the keyboard, sorts t
/* and then displays them on the screen. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXLINES 30
#define MAXCOLS 50

void exchange2D(char p[][MAXCOLS], int i, int j);
void sort2D(char p[][MAXCOLS], int n);
void print2D(char p[][MAXCOLS], int n);

main() {
  char inputs[MAXLINES][MAXCOLS];
  printf("sizeof inputs: %d\n\n", sizeof inputs);
  size_t n=0;

  /* Read in the lines from the keyboard, using fgets */
  printf("Enter a string: ");
  fgets(inputs[n], sizeof(inputs), stdin);

  while (strcmp(inputs[n], "xxx\n")) {
   // fputs(inputs[MAXLINES], stdout);
   ++n;
    printf("Enter a string: ");
    fgets(inputs[n], sizeof(inputs), stdin);
  }
  printf("\n");

  //sscanf(input, "%s %d %f", name, &age, &rate);
  // display the array by calling print2D( ..)
  print2D(inputs,  n);

  // swap the first and second row here
  char tmp[MAXCOLS];

strcpy(tmp, inputs[0]);
strcpy(inputs[0], inputs[1]);
strcpy(inputs[1], tmp);
// call exchange2D() to swap some other rows
exchange2D(inputs,2,3);
printf("\n== after swapping ==\n");

// display the swapped array by calling print2D()
print2D(inputs, n);
printf("\n== after sorting ==\n");
// call sort2D to sort
sort2D(inputs, n);
// display the sorted array by calling print2D()
print2D(inputs, n);
return 0;
}

 // do exchange, have to involve data movement 
 void exchange2D(char p[][MAXCOLS], int i, int j)
 {
   char tmp[MAXCOLS];

   strcpy(tmp, p[i]);
   strcpy(p[i], p[j]);
   strcpy(p[j], tmp);
 }

 // do exchange, have to involve data movement
 void sort2D(char p[][MAXCOLS], int n) { 
     size_t i, j;
     char smaller[MAXCOLS];
     for (i = 0; i <n;i++){
        strcpy(smaller, p[i]);
        for (j = i+1; j <n; j++){
            if (strcmp(p[i],p[j])>0){
             strcpy(smaller, p[i]);
             strcpy(p[i],p[j]);
             strcpy(p[j], smaller);
            }
        }
         
     }
      }

 void print2D(char p[][MAXCOLS], int n)
 {
     //int i,j;
     size_t i;
    //  for (i=0; i<MAXLINES; i++) {
    //    for (j=0; j<MAXCOLS;j++){
    //        printf("%c",p[i][j]);
    //    }
    //    printf("\n");
    //  }
    for (i = 0; i < n; i++)
    {
       printf("[%d]:",i);
        puts(p[i]);
    }
 }                        

