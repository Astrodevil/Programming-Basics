
// Input a number and print all the factors of that number (use loops).
package com.anand;
public class factors {
    public static void main(String[] args) {

        int number = 50;
        System.out.println("Factors of "+number+" are: ");

        for (int i=1; i<=number; ++i){
            if (number % i==0){
                System.out.println(i +" ");
            }
        }
    }
}