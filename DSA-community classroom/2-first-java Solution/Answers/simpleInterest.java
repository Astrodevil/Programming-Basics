
// Write a program to input principle, time and rate (P, T, R) from user and find Simple Interest.
package com.anand;
public class simpleInterest {
    public static void main(String[] args) {
        float p,r,t,si; //principle,time,rate and simple interest
        p=1200;r=6;t=2;
        si=p*r*t/100;
        System.out.println("Simple Interest is: "+ si);
    }
}