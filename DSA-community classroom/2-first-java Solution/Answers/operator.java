// Take in two numbers and an operator (+, -, *, /) and calculate the value. (Use if conditions)

package com.anand;
import java.util.Scanner;
public class operator {
    public static void main(String []args){
        Scanner sc=new Scanner(System.in);
        int n1,n2,res=0;
        char s;

        System.out.println("Enter two numbers");
        n1=sc.nextInt();
        n2=sc.nextInt();
        System.out.println("Choose which operation to perform + - / *");
        s=sc.next().charAt(0);

        if(s=='+')

            res=n1+n2;

        else if(s=='-')
            res=n1-n2;

        else if(s=='/')
            res=n1/n2;

        else if(s=='*')
            res=n1*n2;

        else
            System.out.println("Sorry! Wrong Input");

        System.out.println("Operation performed  "+res);

    }
}


