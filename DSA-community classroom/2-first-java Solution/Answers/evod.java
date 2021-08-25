
// Write a program to print whether a number is even or odd, also take input.
package com.anand;
import java.util.Scanner;
public class evod {
    public static void main(String[] args) {
          Scanner input= new Scanner(System.in); //To take input from the user
                                                 //Create an object of scanner class
        int num; //Declare the variable
        System.out.println("Enter a number:");
        num = input.nextInt();
                         //If number is divisible by 2 then odd
                         //Otherwise odd
        if (num % 2 ==0)
            System.out.println("The Entered Number is Even");
        else
            System.out.println("The Entered Number is Odd");
    }
}
