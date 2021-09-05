// Volume Of Prism
package com.anand;
import java.util.Scanner;
public class vprism {
    public static void main(String[] args) {
        Scanner v = new Scanner(System.in);
        System.out.println("Enter area of base: ");
        double a = v.nextInt();
        System.out.println("Enter height of Prism: ");
        double h = v.nextInt();

        double volume = a*h;
        System.out.println("Volume of Prism is: "+volume);
    }
}