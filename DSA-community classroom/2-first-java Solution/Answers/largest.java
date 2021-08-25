// Take 2 numbers as input and print the largest number.
package com.anand;
import java.util.Scanner;
public class largest {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter First Number:");
        int first = sc.nextInt();

        System.out.println("Enter Second Number");
        int second = sc.nextInt();

        if (first>second)
            System.out.println(first+" is greater than "+second);
        else if (second>first)
            System.out.println(second+" is greater than "+first);
        else
            System.out.println("Both numbers are equal");
        sc.close();

    }
}