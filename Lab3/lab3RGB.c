/******************
****************************************/

#include <stdio.h>

#define AlphaValue 100


void printBinary(unsigned int);
int main() {

  int r, g,b,i;
  unsigned int rgb_pack;
  int r_unpack, g_unpack,b_unpack;
  int alpha = AlphaValue;

  printf("enter R value (0~255): ");
  scanf("%d",&r);
  printf("enter G value (0~255): ");
  scanf("%d",&g);
  printf("enter B value (0~255): ");
  scanf("%d",&b);
  
  while(! (r<0 || g<0 || b <0) )
  {		
     printf("A: %d\t", alpha);  printBinary(alpha); printf("\n");
     printf("R: %d\t", r);  printBinary(r); printf("\n");
     printf("G: %d\t", g);  printBinary(g); printf("\n"); 
     printf("B: %d\t", b);  printBinary(b); printf("\n"); 
  
     rgb_pack=b|(g<<8)|(r<<16)|(alpha<<24);


     //printf("\nPacked: value %d\t", rgb_pack); printBinary(rgb_pack);printf("\n");
     printf("\nPacked:\t"); printBinary(rgb_pack);printf(" (%d)\n", rgb_pack);
     printf("\nUnpacking  ......\n");  
     r=g=b=-1;

    /* do unpacking */

r_unpack=255&(rgb_pack>>16);

g_unpack=255&(rgb_pack>>8);

b_unpack=255&(rgb_pack>>0);


     printf("R: "); printBinary(r_unpack); printf(" (%d, %#o, %#X)\n", r_unpack, r_unpack, r_unpack);
     printf("G: "); printBinary(g_unpack); printf(" (%d, %#o, %#X)\n", g_unpack, g_unpack, g_unpack);
     printf("B: "); printBinary(b_unpack); printf(" (%d, %#o, %#X)\n", b_unpack, b_unpack, b_unpack);
     printf("------------------------------------\n"); 
	 
    
     printf("enter R value (0~255): ");
  scanf("%d",&r);
  printf("enter G value (0~255): ");
  scanf("%d",&g);
  printf("enter B value (0~255): ");
  scanf("%d",&b);

  }

}
