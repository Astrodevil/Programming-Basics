
// Area Of Rhombus
package com.anand;
import java.util.Scanner;
public class rhombus {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter d1 of Rhombus: ");
        double d1 = s.nextInt();
        System.out.println("Enter d2 of Rhombus: ");
        double d2 = s.nextInt();

        double area = d1*d2/2;
        System.out.println("Area of Rhombus is: "+area);
    }
}