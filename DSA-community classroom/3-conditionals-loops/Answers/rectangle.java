//Area Of Rectangle Program

/*
package com.anand;
public class rectangle {
    public static void main(String[] args) {
        float l=4, b=7, area;
        area=l*b;
        System.out.println("Area of Rectangle is: "+area);
    }
}
*/

package com.anand;
import java.util.Scanner;
public class rectangle {
    public static void main(String[] args) {
        Scanner a = new Scanner(System.in);
        System.out.println("Enter Length: ");
        double l = a.nextInt();
        System.out.println("Enter Breadth");
        double b = a.nextInt();

        double area = l*b;

        System.out.println("Area of Rectangle is: "+area);
    }
}