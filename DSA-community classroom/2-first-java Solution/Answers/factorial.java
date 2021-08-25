
// Write a program to print factorial of a number, also take input.
package com.anand;
public class factorial {
    public static void main(String[] args) {
        int i, fact=1;
        int number=4; // number of which factorial will be calculated
        for(i=1; i<=number; i++){
            fact=fact*i;

        }
        System.out.println("Factorial of"+number+"is:"+fact);
    }
}