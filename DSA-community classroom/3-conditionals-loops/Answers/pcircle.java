// Perimeter Of Circle
package com.anand;
import java.util.Scanner;
public class pcircle {
    public static void main(String[] args) {
        Scanner e = new Scanner(System.in);
        System.out.println("Enter radius of Circle: ");
        double r = e.nextInt();
        double perimeter = 2*r*22/7;
        System.out.println("Perimeter of Circle is: "+perimeter);
    }
}