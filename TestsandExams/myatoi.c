/*********************
 ****************************************/

#include <stdio.h>
// more header files and declarations as needed

#include <stdlib.h>

#include <string.h>
#define SIZE 10
int my_atoi(char c[]);
double my_pow(int base, int p);
int length(char[]);

int main(int argc, char *argv[]) {
  int a, b;
  char arr[SIZE];

  printf("Enter a word of positive number or 'quit': ");
  scanf("%s", arr);
  while (strcmp(arr, "quit")) {
    printf("%s\n", arr);

    a = atoi(arr);
    printf("atoi:    %d (%#o, %#X)\t%d\t%d\n", a, a, a, a * 2, a * a);

    b = my_atoi(arr);
    printf("my_atoi: %d (%#o, %#X)\t%d\t%d\n", b, b, b, b * 2, b * b);

    printf("Enter a word of positive number or 'quit': ");
    scanf("%s", arr);
  }

  return 0;
}

/* convert an array of digit characters into a decimal int.
   Input is either a valid Decimal or Octal or Hex integer literal.
*/

int my_atoi(char c[]) {
  int current_value = 0;
  int len = length(c);

  int pos = len - 1; /* scan from right to left */
  int pow = 0;        
  
  if (c[0] == '0' && (c[1] == 'X' || c[1] == 'x')) { // hexedecimal and octal
    while (pos > 1) {
      int v;
      if (c[pos] >= '0' && c[pos] <= '9')
        v = c[pos] - '0';
      else if (c[pos] >= 'A' && c[pos] <= 'F')
        v = c[pos] - 'A' + 10;
      else if (c[pos] >= 'a' && c[pos] <= 'f')
        v = c[pos] - 'a' + 10;

      current_value += v * my_pow(16, pw);

      pos--; 
      pow++;
    }
  }
  else{
    //numbers -decimals
      while (pos >= 0) {
            int v = c[pos] - '0';

            current_value += v * my_pow(10, pw);

            pos--; 
            pow++;
          }
      }

  return current_value;
}

double my_pow(int base, int p) {

  if (p == 0)
    return 1;
  int i;
  double res = base;
  for (i = 1; i < p; i++) {
    res *= base;
  }
  return res;
}

int length(char arr[]) {
  int i = 0;
  while (arr[i] != '\0')
    i++;
  return i;}
