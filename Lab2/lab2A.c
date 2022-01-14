/***************************************
* EECS2031ON – Lab2 *
* Author: OJO, AYOBAMI *
* Email:ayobami1@my.yorku.ca *
* eecs_username: ayobami1 *
* York Student #: 215281421
****************************************/

#include<stdio.h>

int main(){
     int num,x; 
     char Letter;
    
  int IsNum(int,char);

    while(1){ // while true inifinte loop
	printf("Enter an integer and a character separated by blank: ");
        scanf("%d %c" , &num, &Letter);

	if (num == -10000)
	{
	    break;
	}
	
       if(Letter >= '0' && Letter <= '9')
       {
          printf("Character %c represent a digit. Sum of %d and %c is %d",Letter,num,Letter,IsNum(num,Letter));
       }
       else if ( (Letter >='A' && Letter <= 'Z') || (Letter >='a' && Letter <= 'z')) {
           printf("Character '%c' represent a letter",Letter);
       }
       else{
           printf("Character '%c' represents others",Letter);
       }
               printf("\n");
	
     }
     return 0;
}
/*define function*/

int IsNum(int i,char j){
  int x=j-'0';
  return i+x;
}