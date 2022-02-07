#include <stdio.h>
#include <string.h>

/********************
 ****************************************/

#define SIZE 30

void sortArray(char *arr);
void swap(char *,char *);

int main() {
  char arr[SIZE];

  fgets(arr, SIZE, stdin);

  while (strcmp(arr, "quit\n")) {

  sortArray(arr);
    
    fgets(arr, SIZE, stdin);
  }
  return 0;
  }

void sortArray(char *str){
    int i,j,k;
    int len=strlen(str);
    char temp;

        for (i = 0; i < len; i++) {
      for (j =i+1; j < len; j++) {
    
        if (str[i]>str[j])
        {
            temp=str[i];
            str[i]=str[j];
            str[j]=temp;
          }
       // printf("%c", str[i]);
      }
      printf("%c", str[i]);
    }
   printf("\n");
}
