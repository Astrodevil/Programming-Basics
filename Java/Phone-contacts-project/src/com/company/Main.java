/*
    Program to create phone contacts using arraylist, the program should do following operations
    -> Add new contact
    -> Update the existing contact
    -> Remove the contact
    -> print the contact list
    -> query the contact

 */



package com.company;

import java.util.Scanner;

public class Main {
    private static Scanner sc = new Scanner(System.in);
    private static MobilePhone mobilePhone = new MobilePhone("0039 330 4404");

    public static void main(String[] args) {
        // write your code here
            boolean quit = false;
            int choice;
            System.out.println("Phone is turned on");
            printActions();
            while (!quit) {
                System.out.println("select option");
                choice = sc.nextInt();
                sc.nextLine();
                switch (choice) {
                    case 1:
                        addContact();
                        break;
                    case 2:
                        setContact();
                        break;
                    case 3:
                        removeContact();
                        break;
                    case 4:
                        queryContact();
                        break;
                    case 5:
                        mobilePhone.printContact();
                        break;
                    case 6:
                        printActions();
                        break;
                    case 7:
                        quit = true;
                        break;
            }




        }

}


    // add new contact
    private static void addContact () {
        String name, number;
        System.out.println("enter name");
        name = sc.nextLine();
        System.out.println("enter number");
        number = sc.nextLine();
        Contact contact = Contact.createContact(name, number);
        mobilePhone.addNewContact(contact);

    }

    // update contact
    private static void setContact(){
        System.out.println("Enter existing contact name: ");
        String name = sc.nextLine();
        Contact existingContactRecord = mobilePhone.queryContact(name);
        if(existingContactRecord == null) {
            System.out.println("Contact not found.");
            return;
        }

        System.out.println("enter new contact name");
        String newName = sc.nextLine();
        System.out.print("Enter new contact phone number: ");
        String newNumber = sc.nextLine();
        Contact newContact = Contact.createContact(newName, newNumber);
        mobilePhone.updateContact(existingContactRecord, newContact);

    }

    // remove contact
    private static void removeContact(){
        System.out.println("enter existing contact name");
        String name = sc.nextLine();
        Contact existingContactRecord = mobilePhone.queryContact(name);
        if(existingContactRecord != null){
            mobilePhone.removeContact(existingContactRecord);
            System.out.println("contact removed");
        }else{
            System.out.println("contact not found");
        }
    }

    // query contact
    private static void queryContact(){
        System.out.println("Enter existing contact name: ");
        String name = sc.nextLine();
        Contact existingContactRecord = mobilePhone.queryContact(name);
        if(existingContactRecord == null){
            System.out.println("contact not found");
        }else{
            System.out.println("contact name = " + existingContactRecord.getName() + " number = " + existingContactRecord.getPhoneNumber());
        }
    }
    // print actions
    private static void printActions(){
        System.out.println("\nAvailable actions:\npress");
        System.out.println(
                "1  - to add a new contact \n" +
                "2  - to update an existing contact\n" +
                "3  - to remove an existing contact\n" +
                "4  - query if an existing contact exists\n" +
                "5  - to print a list of contacts.\n" +
                "6  - to print actions\n" +
                "7  - to quit");

        System.out.println("Choose your action: ");
    }
}

