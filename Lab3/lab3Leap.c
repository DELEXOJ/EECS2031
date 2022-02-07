/******************
****************************************/

#include <stdio.h>

int isLeapYear(int year);
int isYear(int year);
int main(){
    int i;
    printf("Enter a year: ");
    scanf("%d",&i);
    while(isYear(i)!=0){

        if (isLeapYear(i)==0)
        {
            
        printf("Year %d is  not a leap year\n",i);
        }else{
            
        printf("Year %d is a leap year\n",i);
        }
        
printf("Enter a year: ");
    scanf("%d",&i);
    }
}
int isLeapYear(int year){
if ((year%100)==0)
{
    if ((year%400)==0){
    return 1;
    }
    return 0;
}
else if ((year%4)==0){
return 1; 
}
// else if ((year%100)==0){
//     return 0;
// }
else{
    return 0;
}

}
int isYear(int year){
    if (year>0){
        return 1;
    }else{
        return 0;
    }
    
}
