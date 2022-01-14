#include<stdio.h>
#include<string.h>

#define SIZE 30

int my_strcmp(char a[], char b[]);

int main(){
   char a[SIZE];
   char b[SIZE];
   
   scanf("%s", a); 
   scanf("%s",b);
    
   while (strcmp(a,b)||strcmp(a,"xxx")||strcmp(b,"xxx")){
      int resu = strcmp(a,b); 
      if (resu < 0) 
         printf("strcmp:   \"%s\" appears earlier in dictionary than \"%s\"\n", a,b);
      else if (resu > 0) 
         printf("strcmp:   \"%s\" appears later in dictionary than \"%s\"\n", a,b);
      else 
         printf("\"%s\" and \"%s\" are same\n", a, b);
      
      int resu2 = my_strcmp(a,b);
      if (resu2 < 0) printf("mystrcmp: \"%s\" appears earlier in dictionary than \"%s\"\n\n", a,b);
      else if (resu2 > 0) printf("mystrcmp: \"%s\" appears later in dictionary than \"%s\"\n\n", a,b);
      else printf("\"%s\" and \"%s\" are same\n\n", a,b);
 scanf("%s", a); 
   scanf("%s",b);

   }
}


int my_strcmp(char a[], char b[]){
int i,resu;
resu=0;
i=0;
while(( a[i] != '\0' && b[i] != '\0' ) && a[i] ==b[i]){
i++;
}

if(a[i]!=b[i]){
   resu=a[i]-b[i];
   return resu;
   printf(" resu: %d",resu);
}else{
return resu;
}
}