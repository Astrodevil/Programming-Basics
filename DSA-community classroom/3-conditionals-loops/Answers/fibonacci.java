/* Fibonacci Series In Java Programs */
package com.anand;
public class fibonacci {
    public static void main(String[] args) {
        int n1=0, n2=1,n3, i, count=15;
        System.out.println(n1+""+n2); //printing 0 and 1

        for (i=2;i<count;++i)  //loop starts from 2 because 0 and 1 are already printed
        {
            n3=n1+n2;
            System.out.println(""+n3);
            n1=n2;
            n2=n3;

        }
    }
}