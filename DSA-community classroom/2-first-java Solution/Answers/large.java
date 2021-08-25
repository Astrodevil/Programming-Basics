
// Take integer inputs till the user enters 0 and print the largest number from all.
package com.anand;
import java.util.Scanner;
public class large {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.print("enter numbers");
        int max = 0;
        while(true) {
            int n = scan.nextInt();
            if (n == 0) {
                break;
            }
            if (n > max) {
                max = n;
            }
        }

        System.out.println("largest number" + max);
    }
}
