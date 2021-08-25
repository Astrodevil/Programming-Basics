//Take name as input and print a greeting message for that name.
package com.anand;
import java.util.Scanner;
public class greet {
    public static void main(String[] args) {
        System.out.println("Please Enter Name:"); //Taking input as name

        Scanner input =new Scanner(System.in);
        String name = input.next();

        System.out.println("Happy Birthday " + name);
    }
}