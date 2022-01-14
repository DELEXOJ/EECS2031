#include<stdio.h>
#include<string.h>

#define SIZE 30

void my_strcat(char a[], char b[]);
void my_strcat2(char a[], char b[]);
void my_strcat3(char a[], char b[]);


int main(){
   char a[SIZE];
   char b[SIZE];
   char c[SIZE];
   char d[SIZE];

   scanf("%s",a);
   scanf("%s",b);
   while (strcmp (a, "xxx") || strcmp(b, "xxx")){
    
      strcpy(c,a); strcpy(d,b);
      strcat(a,b);
      my_strcat2(c,d);
      
      printf("strcat:   %s\n", a); printf("mystrcat: %s\n\n", c);


      scanf("%s",a);
      scanf("%s",b);
 
   }
}


void my_strcat(char a[], char b[]){
  int i = strlen(a);
  int j = strlen(b);
  
  int k;
  for( k=0; k<= j; k++){    // <= j so that \0 is also copied
    a[k+i] = b[k];
  
 }

}

void my_strcat2(char a[], char b[]){
  int i = strlen(a);  
  int j = strlen(b);
     
  int k;
  for( k=0; k< j; k++){    // < j so \0 will not be copied
    a[k+i] = b[k];
  
 }
 //a[k+i] = b[k]; // manually copy /0
  //or  
 a[k+i] = '\0';
}


void my_strcat3(char a[], char b[]){
  int i = 0;
  while (a[i]!='\0')
    i++;
  
  int j = 0;
  while (1){
     a[i+j] = b[j];
     if (b[j] == '\0')
        break;
     j++;
  }
}
      

