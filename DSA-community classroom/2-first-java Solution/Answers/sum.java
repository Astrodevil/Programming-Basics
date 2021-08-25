
// Take integer inputs till the user enters 0 and print the sum of all numbers (HINT: while loop)

package com.anand;
import java.util.Scanner;
public class sum {
    public static void main(String[] args) {
        int a=0;
        int sum=0;
        int i=1;
        Scanner sc = new Scanner(System.in);
        while ((a = sc.nextInt()) != 0){
            sum=sum+a;
            i++;
        }
        System.out.println("Sum is "+ sum);
    }
}