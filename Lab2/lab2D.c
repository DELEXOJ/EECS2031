/***************************************
* EECS2031ON – Lab2 *
* Author: OJO, AYOBAMI *
* Email:ayobami1@my.yorku.ca *
* eecs_username: ayobami1 *
* York Student #: 215281421
****************************************/

#include <stdio.h>
#define SIZE 50    // assume no more than 50 literals in input
int main(){
 
  int c,i;
 int  num=1;
  int r=0;
  int resu[SIZE];
  int negative;  
 // ...

  c = getchar();
   
  while ( c != EOF){ 

         if ( c ==' '|| c =='\n'){
             if (negative==-1)
             {
                  value=-value;
          resu[num]=value;
          negative=0;
             }

       else{  
          resu[num]=value;
          }
            value=0;
c=getchar();
num=num+1;
}



    if (c=='-')
{
    negative=-1;
    c=getchar();
}

        if( c !=' '|| c !='\n'){
     value=value*10+c-'0';
      
     }  

          
  
  c = getchar(); // read next
  }
 
  printf("--------\n");
  
  for(i=1;i<num;++i)
    printf("%d\t%d\n", resu[i],resu[i] *2);

  
 
}
