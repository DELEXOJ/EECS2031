/***************************************
* EECS2031ON – Lab1 *
* Author: Ojo, Ayobami *
* Email: ayobami1@my.yorku.ca *
* eecs_username: ayobami1 *
* York Student #: 215281421
****************************************/

import java.util.Scanner;

public class Lab1 {

 public static void main(String[] args) {
 
  Scanner scan = new Scanner(System.in); // or use bufferedReaders or Console 
  System.out.print("Please enter the name: ");
  String name = scan.next();

  System.out.print("Please enter the number: ");
  int a = scan.nextInt();

  int b = a * 2;
  int c = a*3; 
  
  System.out.println("Hi "+name+", double and triple of input "+a+" is "+b+" and "+c+", respectively");       
  System.out.printf("Hi %s, double and triple of input %s is %s and %s, respectively",name,a,b,c);

 }   
}