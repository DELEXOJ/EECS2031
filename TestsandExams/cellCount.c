/* PLEASE DO NOT MODIFY A SINGLE STATEMENT IN THE TEXT BELOW.
READ THE FOLLOWING CAREFULLY AND FILL IN THE GAPS

I hereby declare that all the work that was required to 
solve the following problem including designing the algorithms
and writing the code below, is solely my own and that I received
no help in creating this solution and I have not discussed my solution 
with anybody. I affirm that I have read and understood
the Senate Policy on Academic honesty at 
https://secretariat-policies.info.yorku.ca/policies/academic-honesty-senate-policy-on/
and I am well aware of the seriousness of the matter and the penalties that I will face as a 
result of committing plagiarism in this assignment.

BY FILLING THE GAPS,YOU ARE SIGNING THE
*/

#include<stdio.h>
#include<stdlib.h>
#define IMAGE_SIZE 10
#define TRUE 3  // Didnt use 1 so as not to confuse it the vaule 1 in the array
#define FALSE 4 //Didnt use 0 so as not to confuse it the vaule 0 in the array
//TEST


// this function prints the array
void printImgArray(int array[IMAGE_SIZE][IMAGE_SIZE])
{
  
    printf("------ Image Contents -------\n");
    int i, j;
	for (i=0; i<IMAGE_SIZE; i++)
    {
    for (j=0; j<IMAGE_SIZE; j++)
        printf("%02d, ",array[i][j]);
    printf("\n");
    }
    printf("-----------------------------\n");
}


/**
 * This function counts the number of distinct 
 * number (i.e. the number of cells)
 *
 * feel free to add auxiliary data structures and helper functions
 **/

int cellCount(int image[IMAGE_SIZE][IMAGE_SIZE]){
    // insert your code for task1.2 here
    // you may want to change the return value.
     int i, j;
      int count=0;
     for (i = 0; i < IMAGE_SIZE; i++) {
       for (j = 0; j < IMAGE_SIZE; j++) {
         if (image[i][j]!=0){
                int temp=image[i][j];
                count++;
                int x,y;
                for (x = 0; x < IMAGE_SIZE; x++) {
                  for (y = 0; y < IMAGE_SIZE; y++) {
                    while (image[x][y]==temp){
                      image[x][y]=0;
                    }
                  }
                }
       }
     }}
     return count;
}
/**
 * This function colors each blood cell with a unique color
 * (i.e. unique number)
 * Hint: scan the array element by element, and explore each element as much as possible, 
 * when come to an already labelled one, relabell the array to form larger cell
 * 
 * feel free to add auxiliary data structures and helper functions
 **/

  void color(int image[IMAGE_SIZE][IMAGE_SIZE]){
      // insert your code for task 1.1 here
      int i, j,x,y;
    //  int visited[IMAGE_SIZE][IMAGE_SIZE];
      for (i=0; i<IMAGE_SIZE; i++)
      {
        for (j=0; j<IMAGE_SIZE; j++){
        //  visited[i][j] = FALSE;
        }
        }
         i = 0;
        j = 0;
            int number=0;
            for (i = 0; i < IMAGE_SIZE; i++) {
              for (j = 0; j < IMAGE_SIZE; j++) {
                if (image[i][j] == 1) {
                  number=0;
                       if (((j-1)>=0)&&(image[i][j-1]>=12))//go left
                       {
                         number = image[i][j - 1];
                         image[i][j] = number;
                       }else {
                         if (((j +1) < IMAGE_SIZE) &&(image[i][j + 1] >= 12))
                         { // go right
                           number = image[i][j + 1];
                           image[i][j] = number;
                         } else {
                           if (((i - 1) >= 0)&&(image[i - 1][j] >= 12) ){ //
                          // go up
                               number = image[i - 1][j];
                               image[i][j] = number;
                             }
                           else {
                               if (((i+ 1) <IMAGE_SIZE) &&(image[i + 1][j] >=
                               12)) { // go down
                                 number = image[i + 1][j];
                                 image[i][j] = number;
                               } else {
                                 if (((i - 1) >=0) && ((j - 1)>= 0)
                                 &&(image[i - 1][j - 1] >= 12)) { // diagonal up
                                                                    // left
                                   number = image[i - 1][j - 1];
                                   image[i][j] = number;
                                 } else {
                                   if (((i - 1) >= 0) && ((j + 1) <
                                   IMAGE_SIZE) && (image[i - 1][j + 1] >=12))
                                   { // diagonal up right
                                     number = image[i - 1][j + 1];
                                     image[i][j] = number;
                                   } else {
                                     if (((i+ 1) < IMAGE_SIZE) && ((j - 1) >=
                                     0) &&(image[i + 1][j - 1] >= 12)) { //
                                   //  diagonal down left
                                       number = image[i + 1][j - 1];
                                       image[i][j] = number;
                                     } else {
                                       if (((i +1) < IMAGE_SIZE) && ((j +1) <
                                       IMAGE_SIZE) &&(image[i + 1][j + 1] >=
                                       12)) { // diagonal down right
                                         number = image[i + 1][j + 1];
                                         image[i][j] = number;
                                       } else {
                                         number = (rand() % 99) + 12;
                                         image[i][j] = number
                                         ;
                                       }
                                     }
                                   }
                                 }
                               }
                           }
                         }
                       }
              }
            }
  }
  // check all sides
  for(i=0;i<IMAGE_SIZE;i++){
    for (j = 0; j < IMAGE_SIZE; j++) {
    
      if (image[i][j] >= 12) { // if labeled
   x = i - 1;
      y = j + 1;
      int q = j - 1; 
      if ((x >= 0 && x < IMAGE_SIZE ) &&
           (y >= 0 && y < IMAGE_SIZE) &&
             (q >= 0 && q < IMAGE_SIZE )) {
      if ((image[x][q] == 0) && (image[x][y] >= 12)) {
                if (image[i][j] != image[x][y]) {
                        image[x][y] = image[i][j];
                }}
      if ((image[x][q] != 0) && (image[x][y] >= 12)) {
        if (image[x][q] != image[x][y]) {
          image[i][j] = (rand() % 99) + 12;
          int k = image[i][j];
          int r,s;
                for (r = 0; r < IMAGE_SIZE; r++) {
                  for (s = 0; s < IMAGE_SIZE; s++) {
                  if (image[r][s]==image[x][q]){
                        image[r][s]=k;
                  }
                  if (image[r][s] == image[x][y]) {
                    image[r][s] = k;
                  }
                  }}
         }
      }
     }
          }
        }
  }
  }



  /********************************************************************************/
  // the function and all the helper functions (if any) should use pointer
  // notation,
  // instead of array index notation []. It is okey to use [] only when
  // declaring extra arrays
  void colorPtr(int *image) {
    // insert your code for task 2.1 here
    int i, j, x, y;
    //int visited[IMAGE_SIZE][IMAGE_SIZE];
    for (i = 0; i < IMAGE_SIZE; i++) {
      for (j = 0; j < IMAGE_SIZE; j++) {
     //   visited[i][j] = FALSE;
      }
    }
    i = 0;
    j = 0;
    int number = 0;
    for (i = 0; i < IMAGE_SIZE; i++) {
      for (j = 0; j < IMAGE_SIZE; j++) {
        if (*(image+i*IMAGE_SIZE+j) == 1) {
          number = 0;
          if (((j - 1) >= 0) &&
              (*(image + i * IMAGE_SIZE + (j-1)) >= 12)) // go left
          {number = *(image + i * IMAGE_SIZE + (j-1));
            *(image + i * IMAGE_SIZE + j) = number;
          } else {
            if (((j + 1) < IMAGE_SIZE) &&
                (*(image + i * IMAGE_SIZE + (j+ 1)) >= 12)) { // go right
              number = *(image + i * IMAGE_SIZE + (j+ 1));
              *(image + i * IMAGE_SIZE + j) = number;
            } else {
              if (((i - 1) >= 0) && (*(image +(i-1) * IMAGE_SIZE + j) >= 12)) { //
                // go up
                number = *(image + (i -1)* IMAGE_SIZE + j);
                *(image + i * IMAGE_SIZE + j) = number;
              } else {
                if (((i + 1) < IMAGE_SIZE) &&
                    (*(image + (i +1) * IMAGE_SIZE + j) >= 12)) { // go down
                  number = *(image + (i+1) * IMAGE_SIZE + j);
                  *(image + i * IMAGE_SIZE + j) = number;
                } else {
                  if (((i - 1) >= 0) && ((j - 1) >= 0) &&
                      (*(image +( i-1) * IMAGE_SIZE +( j-1)) >= 12)) { // diagonal up left
                    number = *(image +( i-1) * IMAGE_SIZE +( j-1));
                    *(image + i * IMAGE_SIZE + j) = number;
                  } else {
                    if (((i - 1) >= 0) && ((j + 1) < IMAGE_SIZE) &&
                        (*(image + (i - 1) * IMAGE_SIZE + (j + 1)) >=
                         12)) { // diagonal up right
                      number = *(image + (i - 1) * IMAGE_SIZE + (j + 1));
                      *(image + i * IMAGE_SIZE + j) = number;
                    } else {
                      if (((i + 1) < IMAGE_SIZE) && ((j - 1) >= 0) &&
                          (*(image + (i + 1) * IMAGE_SIZE + (j - 1)) >=
                           12)) { //
                                  //  diagonal down left
                        number = *(image + (i + 1) * IMAGE_SIZE + (j - 1));
                        *(image + i * IMAGE_SIZE + j) = number;
                      } else {
                        if (((i + 1) < IMAGE_SIZE) && ((j + 1) < IMAGE_SIZE) &&
                            (*(image + (i + 1) * IMAGE_SIZE + (j + 1)) >=
                             12)) { // diagonal down right
                          number = *(image + (i + 1) * IMAGE_SIZE + (j + 1));
                          *(image + i * IMAGE_SIZE + j) = number;
                        } else {
                          number = (rand() % 99) + 12;
                          *(image + i * IMAGE_SIZE + j) = number;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    // check all sides
    for (i = 0; i < IMAGE_SIZE; i++) {
      for (j = 0; j < IMAGE_SIZE; j++) {

        if (*(image + i * IMAGE_SIZE + j) >= 12) { // if labeled
          x = i - 1;
          y = j + 1;
          int q = j - 1;
          if ((x >= 0 && x < IMAGE_SIZE) && (y >= 0 && y < IMAGE_SIZE) &&
              (q >= 0 && q < IMAGE_SIZE)) {
            if ((*(image + x * IMAGE_SIZE + q) == 0) &&
              (*(image + x * IMAGE_SIZE + y) >= 12)) {
              if (*(image + i * IMAGE_SIZE + j) !=
                  *(image + x * IMAGE_SIZE + y)) {
                *(image + x * IMAGE_SIZE + y) = *(image + i * IMAGE_SIZE + j);
              }
              }
              if ((*(image + x * IMAGE_SIZE + q) != 0) &&
                  (*(image + x * IMAGE_SIZE + y) >= 12)) {
                if (*(image + x * IMAGE_SIZE + q) !=
                    *(image + x * IMAGE_SIZE + y)) {
                  *(image + i * IMAGE_SIZE + j) = (rand() % 99) + 12;
                  int k = *(image + i * IMAGE_SIZE + j);
                  int r, s;
                  for (r = 0; r < IMAGE_SIZE; r++) {
                    for (s = 0; s < IMAGE_SIZE; s++) {
                      if (*(image + r * IMAGE_SIZE + s) ==
                          *(image + x * IMAGE_SIZE + q)) {
                        *(image + r * IMAGE_SIZE + s) = k;
                      }
                      if (*(image + r * IMAGE_SIZE + s) ==
                          *(image + x * IMAGE_SIZE + y)) {
                        *(image + r * IMAGE_SIZE + s) = k;
                      }
                    }
                  }
                }
              }
          }
        }
      }
    }
}

//the function and all the helper functions (if any) should use pointer notation, 
// instead of array index notation []. It is okey to use [] only when declaring extra arrays
int cellCountPtr(int* image){
    // insert your code for task 2.2 here
    int i, j;
    int count = 0;
    for (i = 0; i < IMAGE_SIZE; i++) {
      for (j = 0; j < IMAGE_SIZE; j++) {
        if (*(image + i * IMAGE_SIZE + j) != 0) {
          int temp = *(image + i * IMAGE_SIZE + j);
          count++;
          int x, y;
          for (x = 0; x < IMAGE_SIZE; x++) {
            for (y = 0; y < IMAGE_SIZE; y++) {
              while (*(image + x * IMAGE_SIZE + y) == temp) {
                *(image + x * IMAGE_SIZE + y) = 0;
              }
            }
          }
        }
      }
    }
    return count;
}

/********************************************************************************/

/**
 * This function colors each cell with a unique color
 * (i.e., unique number).
 **/
// used for recursive function
void Newrecursioncolor(int image[IMAGE_SIZE][IMAGE_SIZE], int i, int j,
                       int value) {
  if ((i >= 0 && i < IMAGE_SIZE) && (j >= 0 && j < IMAGE_SIZE)) {
    if (image[i][j] == 1) {
      image[i][j] = value;
      Newrecursioncolor(image, i - 1, j, value);
      Newrecursioncolor(image, i - 1, j + 1, value);
      Newrecursioncolor(image, i, j + 1, value);
      Newrecursioncolor(image, i + 1, j + 1, value);
      Newrecursioncolor(image, i + 1, j, value);
      Newrecursioncolor(image, i + 1, j - 1, value);
      Newrecursioncolor(image, i, j - 1, value);
      Newrecursioncolor(image, i - 1, j - 1, value);
    } else {
      return;
    }
  }
  return;
}
int colorRecursively(int image[IMAGE_SIZE][IMAGE_SIZE]) {
//guessed solution
int i, j, counter = 2;
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      if (image[i][j] == 1) {
        Newrecursioncolor(image, i, j, counter);
        image[i][j] = 0;
        counter++;
      }
    }
  }

return 0;
}

 

#ifndef __testing
int main(){

    // DO not change anything in main(), it will confuse the
    // auto-checker.  
    puts("testing the code with color() function");
    int count = 0;
    int cellImg[IMAGE_SIZE][IMAGE_SIZE]={{0,0,1,1,0,0,1,0,0,1},\
		               {1,0,1,1,0,0,1,1,0,1},\
		               {1,0,0,1,1,0,1,1,0,1},\
		               {1,1,0,0,0,0,0,0,0,0},\
		               {1,0,0,1,1,1,0,0,1,0},\
		               {0,0,0,0,1,0,0,1,1,0},\
		               {0,0,1,0,0,1,0,1,0,0},\
		               {0,0,1,1,0,0,1,0,0,0},\
		               {0,0,1,0,0,0,0,0,1,1},
		               {0,1,1,0,0,0,1,1,1,1}};

    printImgArray(cellImg);
    color(cellImg);
    printImgArray(cellImg);
    count=cellCount(cellImg);
    printf("Total number of cells in the image: %d\n",count);
 

    puts("Testing the code with colorPtr");
    int cellImg_[IMAGE_SIZE][IMAGE_SIZE]={{0,0,1,1,0,0,1,0,0,1},\
		               {1,0,1,1,0,0,1,1,0,1},\
		               {1,0,0,1,1,0,1,1,0,1},\
		               {1,1,0,0,0,0,0,0,0,0},\
		               {1,0,0,1,1,1,0,0,1,0},\
		               {0,0,0,0,1,0,0,1,1,0},\
		               {0,0,1,0,0,1,0,1,0,0},\
		               {0,0,1,1,0,0,1,0,0,0},\
		               {0,0,1,0,0,0,0,0,1,1},
		               {0,1,1,0,0,0,1,1,1,1}};

    int* ptr = cellImg_;
    printImgArray(ptr);
    colorPtr(ptr);
    printImgArray(ptr);
    count=cellCountPtr(ptr);
    printf("Total number of cells in the image: %d\n",count); 
    
	puts("Testing the code with colorRecursively");
    int cellImg__[IMAGE_SIZE][IMAGE_SIZE]={{0,0,1,1,0,0,1,0,0,1},\
		               {1,0,1,1,0,0,1,1,0,1},\
		               {1,0,0,1,1,0,1,1,0,1},\
		               {1,1,0,0,0,0,0,0,0,0},\
		               {1,0,0,1,1,1,0,0,1,0},\
		               {0,0,0,0,1,0,0,1,1,0},\
		               {0,0,1,0,0,1,0,1,0,0},\
		               {0,0,1,1,0,0,1,0,0,0},\
		               {0,0,1,0,0,0,0,0,1,1},
		               {0,1,1,0,0,0,1,1,1,1}};
    printImgArray(cellImg__);
    colorRecursively(cellImg__);
    printImgArray(cellImg__);
    count=cellCount(cellImg__);
    printf("Total number of cells in the image: %d\n",count);
    return 0;
}
#endif
