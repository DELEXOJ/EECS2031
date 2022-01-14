#include <stdio.h>
#include <string.h>
#include <math.h>

#define SIZE 10
#define SIZE2 40


int main(int argc, char *argv[])
{
     char resu[SIZE2];
     char input[SIZE2];    
     char name[SIZE];  
     int age; float rate;
    

     printf("Enter name, age and rate (or \"exit\"): ");
     fgets(input, 40, stdin);
     while (strcmp(input, "exit\n"))
     {    
       //output original input using two functions.
       printf("%s", input);  // no \n needed
       fputs(input, stdout); 
      
       // may need to tokenize input
           sscanf(input, "%s %d %f",name,&age,&rate);
      // ....'
      int i =0;
         if(name[i]>='a'&&name[i]<='z'){
           name[i]=name[i]-('a'-'A');
         }
       
       age=age+10;
       rate=rate*2;
    int rate3=ceil(rate);
    int rate2=floor(rate);

    sprintf(resu,"%s-%d-%.3f-[ %d, %d ]",name,age,rate,rate2,rate3);
    printf("%s\n",resu);

       /* use fgets to read again */
        printf("Enter name, age and rate (or \"exit\"): ");
      fgets(input, 40, stdin);
     } 
      return 0;
}
