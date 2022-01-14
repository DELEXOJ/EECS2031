#include<stdio.h>
#include<string.h>

#define SIZE 30

void my_strcat(char a[], char b[]);

int main(){
   char a[SIZE];
   char b[SIZE];
   char c[SIZE];
   char d[SIZE];

   scanf("%s",a);
   scanf("%s",b);
   while (strcmp(a,b)||strcmp(a,"xxx")||strcmp(b,"xxx")){
    
      strcpy(c,a); strcpy(d,b);

      strcat(a,b);
      my_strcat(c,d);
      
      printf("strcat:   %s\n", a); 
      printf("mystrcat: %s\n\n", c);

  scanf("%s",a);
   scanf("%s",b);
 
   }
}


void my_strcat(char a[], char b[]){
int i,j,counter;
counter=0;
for(i=0;a[i]!='\0';i++){
     counter++;
}
     for(j=0;b[j]!='\0';j++){
       a[i]=b[j];
       i++;
    }
    a[i]='\0';
}