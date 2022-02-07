/*****************
****************************************/

#include <stdio.h>
#define SIZE 50    // assume no more than 50 literals in input
int main(){
 
  int c,i;
  int power=1;
 int  num=1;
  float value,FirstValue=0.0;
  float resu[SIZE];
  int decimalPoint;
  float results=1.0;
  float  raiseToPower= 10.0;  
  
 // ...

  c = getchar();
   
  while ( c != EOF){ 

         if ( c ==' '|| c =='\n'){
             if (decimalPoint==-1)
             {results=1.0;
                 while(power!=0){
                    results*=raiseToPower;
                    --power;
                 }
                //  float nui=((10)^power);
                //  power*=raiseToPower;
                // printf("%f",results);
              value=value/results;
              value=FirstValue+value;
          resu[num]=value;
          decimalPoint=0;
             }

       else{  
          resu[num]=value;
          }
            value=0;
            power=0;
c=getchar();
num=num+1;
}



    if (c=='.')
{
    FirstValue=value;
    decimalPoint=-1;
    c=getchar();
    value=0;
    power=0;
}

        if( c !=' '|| c !='\n'){
     value=value*10.0+c-'0';
     power++;
      
     }  

          
  
  c = getchar(); // read next
  }
 
  printf("--------\n");
  
  for(i=1;i<num;++i)
    printf("%.4f\t%.4f\n", resu[i],resu[i] *2);

  
 
}
