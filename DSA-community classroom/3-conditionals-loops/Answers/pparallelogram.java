// Perimeter Of Parallelogram
package com.anand;
import java.util.Scanner;
public class pparallelogram {
    public static void main(String[] args) {
        Scanner p = new Scanner(System.in);
        System.out.println("Enter base: ");
        double b = p.nextInt();
        System.out.println("Enter side: ");
        double a = p.nextInt();

        double perimeter = 2*(a+b);
        System.out.println("Perimeter of Parallelogram is: "+perimeter);
    }
}