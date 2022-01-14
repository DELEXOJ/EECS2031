#include <stdio.h>
#include <stdlib.h>

struct twoFloats {
  float  fA;
  float fB;
};

/* double the field values of the argument structure */

void process_str(struct twoFloats *x) {

  x->fA *= 2;

  x->fB *= 2;
}

int main(int argc, char *argv[]) {

  struct twoFloats s = {80.2, 150.3};

  process_str(&s);

  printf("%.3f  %.3f\n", s.fA, s.fB); // 160.400  300.600
}
