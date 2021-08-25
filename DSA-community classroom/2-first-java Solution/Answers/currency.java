
// Input currency in rupee and output in dollar.

package com.anand;

import java.util.Scanner;

public class currency {
    public static void main(String[] args) {
        float Rupees;
        Scanner in = new Scanner(System.in);
        System.out.println("Please Enter Rupees:");

        Rupees = in.nextLong();
        float Dollars = Rupees/75;
        System.out.println(Dollars+" Dollars");
    }
}