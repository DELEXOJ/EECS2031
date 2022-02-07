/***********************************
 * 
 ************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){
    int i,total;
    printf("There are %d arguments(excluding \" %s \")\n", argc-1,argv[0]);
   for(i=1; i<argc; i++){
    
   }
   if (strcmp(argv[1],"sum")==0) {
       total=0;
       for (i = 2; i < argc - 1; i++) {
         printf("%s + ", argv[i]);
       }
       printf("%s\n", argv[argc - 1]);
       for (i = 2; i < argc; i++) {
         total += atoi(argv[i]);
     }
     printf("= %d\n",total);
   }else{
       total=atoi(argv[2]);
       for (i = 2; i < argc-1; i++) {
         printf("%s - ", argv[i]);
       }
       printf("%s\n",argv[argc-1]);
     for (i = 3; i < argc; i++) {
       total -= atoi(argv[i]);
     }
     printf("= %d\n", total);
   }
}
