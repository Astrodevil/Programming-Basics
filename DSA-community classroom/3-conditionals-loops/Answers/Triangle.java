
// Area Of Triangle

/*
package com.anand;

public class Triangle {
    public static void main(String[] args) {
        float b=11, h=7, area;
        area = b*h/2;
        System.out.println("Area of Triangle: "+area);
    }
}

 */

package com.anand;
import java.util.Scanner;
public class Triangle {
    public static void main(String[] args) {
        Scanner t = new Scanner(System.in);
        System.out.println("Enter breadth:");
        System.out.println("Enter height");

        double b = t.nextInt();
        double h = t.nextInt();
        double area = b*h/2;

        System.out.println("Area of Triangle is: "+area);

    }
}