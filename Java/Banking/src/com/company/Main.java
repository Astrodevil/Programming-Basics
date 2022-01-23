/*
Program to create banking system.
Program to have bank acccount for customers that displays customer name and transactions in respective branch
Add the branch name, bank, and customer details using arraylist.
 */

package com.company;

import java.util.Scanner;

public class Main {

    private static Scanner sc = new Scanner(System.in);
    private static Bank bank = new Bank("Axis bank");

    public static void main(String[] args) {
	// write your code here
        boolean quit = false;
        int ch;
        printActions();
        while(!quit){

            System.out.println("enter your choice");
            ch = sc.nextInt();
            switch(ch){
                case 1:
                    addBranch();
                    break;
                case 2:
                    addCustomer();
                    break;
                case 3:
                    addCustomerTransaction();
                    break;
                case 4:
                    printCustomer();
                    break;
                case 5:
                    printActions();
                    break;
                case 6:
                    quit = true;
                    break;
            }
        }
    }

    private static void printActions(){
        System.out.println(
                "1. add branch \n" +
                        "2. add customer \n" +
                        "3. add customer transaction \n" +
                        "4. print customer list \n" +
                        "5. quit" );

    }

    private static void addBranch(){
        String name;
        System.out.println("enter branch name");
        name = sc.next();
        bank.addBranch(name);
    }
    private static void addCustomer(){
        System.out.println("enter customer name");
        String customerName = sc.next();
        System.out.println("enter branch name");
        String branchName = sc.next();
        System.out.println("enter initial transaction");
        double transaction = sc.nextDouble();
        bank.addCustomer(customerName, branchName, transaction);

    }

    private static void addCustomerTransaction(){
        System.out.println("enter customer name");
        String customerName = sc.next();
        System.out.println("enter branch name");
        String branchName = sc.next();
        System.out.println("enter transaction");
        double transaction = sc.nextDouble();
        bank.addCustomerTransaction(customerName, branchName, transaction);

    }

    private static void printCustomer(){
        System.out.println("enter branch name");
        String branchName = sc.next();
        System.out.println("do you want to print transaction");
        boolean print = sc.nextBoolean();
        bank.listCustomer(branchName, print);
    }
}
