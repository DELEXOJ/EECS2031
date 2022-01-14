#include <stdio.h>

void printBinary(int);

int main() {

  int r, g,b;
  unsigned int rgb_pack;
  int r_unpack, g_unpack,b_unpack;
  int r8,g8,b8;
  int alpha = 100;

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

    /* do the packing */
    r8 = r << 16;
    g8 = g << 8;
    b8 = b;
    rgb_pack = r8 | g8 | b8 | (alpha <<24);

    printf("\nPacked:\t"); printBinary(rgb_pack);printf(" (%d)\n", rgb_pack);
    r=g=b=-1;
    printf("\nUnpacking  ......\n");

    /* note that shifting and masking rgb_pack does not change rgb_pack, so it can be used again. */

    /* demo 3 approaches  */
    /* 1, shifting + masking */
    r_unpack = rgb_pack >> 16 & 255; // or 0Xff  or 0377
    g_unpack = rgb_pack >> 8  & 0Xff; 
    b_unpack = rgb_pack >> 0  & 0377;


    /* 2, masking + shifting, need different masks */
    r_unpack = (rgb_pack & 0xff0000) >> 16;    // oxff???? is also ok, g b will be pushed off anyway
    g_unpack = (rgb_pack  & 0Xff00) >> 8; 
    b_unpack = rgb_pack  & 0XFF;

    /* 3, shifting only, to push off unwanted bits 
          first shift left to the end, pushing off bits on left, then shift right to the end, pushing off bit on right.
          dangeous >>.  rgb_pack need to be unsigned!   */
    /* also note that shifting rgb_pack does not change it, so rgb_pack can be used again.  */

    r_unpack = rgb_pack << 8 >> 24;   //rgb_pack need to be unsigned!
    g_unpack = rgb_pack << 16 >> 24;
    b_unpack = rgb_pack << 24 >> 24;  


    printf("R: ");
    printBinary(r_unpack);
    printf(" (%d, %#o, %#X)\n", r_unpack, r_unpack, r_unpack);

    printf("G: ");
    printBinary(g_unpack);
    printf(" (%d, %#o, %#X)\n", g_unpack, g_unpack, g_unpack);

    printf("B: ");
    printBinary(b_unpack); 
    printf(" (%d, %#o, %#X)\n", b_unpack, b_unpack, b_unpack);
    printf("------------------------------------\n"); 

    //read again
    printf("\nenter R value: ");
    scanf("%d",&r);
    printf("enter G value: ");
    scanf("%d",&g);
    printf("enter B value: "); 
    scanf("%d",&b);

  }

}

