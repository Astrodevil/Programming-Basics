// Volume Of Cone Java Program
package com.anand;
import java.util.Scanner;
public class vcone {
    public static void main(String[] args) {
        Scanner v = new Scanner(System.in);

        System.out.println("Enter radius of cone: ");
        double r = v.nextInt();
        System.out.println("Enter height of cone: ");
        double h = v.nextInt();

        double volume = (22 * r * r * h)/(3*7);
        System.out.println("Volume of Cone is: "+volume);
    }
}