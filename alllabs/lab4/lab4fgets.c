#include <stdio.h>  // for sprintf
#include <ctype.h>  // for toupper
#include <string.h> 
#include <stdlib.h> // for atoi atof
#include <math.h> // for floor ceil

#define SIZE 20
#define SIZE2 40

int main(int argc, char *argv[])
{

    char input[SIZE2];
    char name[SIZE]; int ag; float rate;

    char resu[SIZE2], resu2[SIZE2];
	
    printf("Enter name, age and rate (or \"exit\"): ");
    fgets(input, 40, stdin);

    while (strcmp("exit\n", input))
    {       
        printf("%s", input);
        fputs(input, stdout);

        sscanf(input, "%s %d %f", name, &ag, &rate);
        ag += 10;
        rate *= 2; 
        name[0] = toupper(name[0]);   // or name[0] = name[0] - ('a'-'A')
	 
        // 3 ways to handle the double type from ceil() and floor()
        // 1) use .0f
        // sprintf(resu, "%s-%d-%.3f-[%.0f,%.0f]", name,ag,rate, floor(rate), ceil(rate));  /* format and then print/write to  resu */
        
       // 2) another way, use cast 
       // sprintf(resu, "%s-%d-%.3f-[%d,%d]", name,ag,rate, (int)floor(rate),(int)ceil(rate));  /* format and then print/write to resu */      
        
       // 3) another way, store into int variables, which will automatically convert to int
        int f = floor(rate);
        int c = ceil(rate);
        sprintf(resu, "%s-%d-%.3f-[%d,%d]", name,ag,rate, f,c);  /* format and then print/write to resu */

        printf("%s\n", resu);  // add one more blank line

        /* read again */
        printf("\nEnter name, age and rate (or \"exit\"): "); 
        fgets(input, 40, stdin);
     } 
     return 0;
}