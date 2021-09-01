//Area Of Isosceles Triangle
package com.anand;
import java.util.Scanner;
public class isosceles {
    public static void main(String[] args) {
        Scanner i = new Scanner(System.in);
        System.out.println("Enter base: ");
        double b = i.nextInt();
        System.out.println("Enter height: ");
        double h = i.nextInt();

        double area = b*h/2;

        System.out.println("Area of Isosceles Triangle is: "+area);

    }
}