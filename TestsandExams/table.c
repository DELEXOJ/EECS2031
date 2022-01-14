/***************************************
 * EECS2031ON – Lab3 *
 * Author: Ojo, Ayobami *
 * Email: ayobami1@my.yorku.ca *
 * eecs_username: ayobami1 *
 * york_num: 215281421 *
 ****************************************/

#include <stdio.h>
// more header files and declarations as needed

#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define ROWs 40
#define COLs 50

 //char input[ROWs][COLs];

int main(int argc, char *argv[])
{
     char table[ROWs][COLs]   ;  /* 2D array to store lines of input */

     int current_row = 0;
     int i;
     char word1[10];
     char word2[10];
     char word11[10];
     char word22[10];
     char letter[10];
     float rate;

     printf("Enter rate~~word1 letter word2: ");
     fgets( table[current_row], 50,stdin );   // use fgets to read in whole line. You can move this line into while loop if you like. 
     
     while (1)        
     {

       printf("Enter rate~~word1 letter word2: ");
       fgets(table[current_row], 30, stdin);
       sscanf(table[current_row], "%f %s %s %s", &rate,word1, letter, word2);

       if (! strcmp("quit\n", table[current_row]))
         break;

       rate *= 1.6;
  
  // strcmp(word1, word22);
       for (i = 0; word1[i] != '\0'; i++) {
         if (word1[i] == letter[i]) {
           word22[i] = '*';
         }
       }

      // if (strchr(word1,letter)!=NULL) {
      // statements
      // }
       for (i = 0; i < strlen(word1); i++) {
         word11[i]=word1[i]+1;
       }
       int flo = floor(rate);
       int cel = ceil(rate);
       sprintf(table[current_row + 1], "%s--%s--%f[%.4d....%d]", word11,word22, rate, flo, cel);
     //  sprintf(table[current_row + 2],"xxx");
       current_row += 3;
     }
     
     /* output number of rows stored   */

     printf("Totally %d rows stored\n", current_row);

     /* output the stored rows of the table */

     for (i = 0; i < current_row; i++) {
       printf("[%d]: %s\n", i, table[i]); 
     }

       return 0;
}

