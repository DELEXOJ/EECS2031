#include<stdio.h>
#include<string.h>

int my_strcmp(char [], char []);

#define SIZE 30


int main(){
   char a[SIZE];
   char b[SIZE];
   
   scanf("%s", a); 
   scanf("%s",b);
    
   while (strcmp (a, "xxx") || strcmp(b, "xxx")){
      //printf("%s %s %d\n", a,b,strcmp(a,b));

      int resu = strcmp(a,b); 
      if (resu < 0) printf("strcmp:   \"%s\" appears earlier in dictionary than \"%s\"\n", a,b);
      else if (resu > 0) printf("strcmp:   \"%s\" appears later in dictionary than \"%s\"\n", a,b);
      else printf("\"%s\" and \"%s\" are same\n", a, b);
      
      int resu2 = my_strcmp(a,b);
      if (resu2 < 0) printf("mystrcmp: \"%s\" appears earlier in dictionary than \"%s\"\n\n", a,b);
      else if (resu2 > 0) printf("mystrcmp: \"%s\" appears later in dictionary than \"%s\"\n\n", a,b);
      else printf("\"%s\" and \"%s\" are same\n\n", a,b);

      scanf("%s", a);
      scanf("%s", b);

   }
}


int my_strcmp(char a[], char b[]){
  int i = strlen(a);
  int j = strlen(b);
  int min = i<=j? i:j; 
  int k;
  for( k=0; k< min; k++){
    if  (a[k] < b[k]) 
       return -1;
    else if (a[k] > b[k]) 
       return +1;
   // else continue next pair

  }
  return i-j;  // if i==j, return 0. Otherwise, the shorter guy preceds the longer guy.

}