package com.company;

import java.util.ArrayList;

public class MobilePhone {
    private String myNumber;
    ArrayList<Contact> myContacts;

    public MobilePhone(String myNumber){
        this.myNumber = myNumber;
        this.myContacts =  new ArrayList<Contact>();
    }


    // add new contact to contacts arraylist
    public boolean addNewContact(Contact contact){
            if(findContact(contact) < 0){
                myContacts.add(contact);
                System.out.println(contact.getName() + " has been added");
                return true;
            }else{
                System.out.println("contact with " + contact.getName() + " already exists");
                return false;
            }
    }

    // update contact
    public boolean updateContact(Contact oldContact, Contact newContact){
        int position = findContact(oldContact);
        if(position >= 0){
                myContacts.set(position,newContact);
                System.out.println("new contact successfully updated");
                return true;
        }
        System.out.println(oldContact.getName() + " contact doesn't exist");
        return  false;
    }

    // remove contact
    public boolean removeContact(Contact contact){
        int position = findContact(contact);
        if(position >= 0){
            myContacts.remove(contact);
            System.out.println(contact.getName() + " contact is removed");
            return true;
        }else{
            System.out.println(contact.getName() + " contact doesn't exist");
            return false;
        }
    }


    // find contact returns the contact
    private int findContact(Contact contact){
        return findContact(contact.getName());
    }

    // find contact with contact name
    private int findContact(String contactName){
        for(int i=0; i< myContacts.size(); i++){
            if(myContacts.get(i).getName().equals(contactName)){
                return i;
            }
        }
        return -1;
    }


    // query contact returns contact
    public String queryContact(Contact contact) {
        if(findContact(contact) >=0) {
            return contact.getName();
        }
        return null;
    }

    // query contact with contact name
    public Contact queryContact(String name) {
        int position = findContact(name);
        if(position >=0) {
            return this.myContacts.get(position);
        }

        return null;
    }

    // print contact list
    public void printContact(){
        System.out.println("Contact List: ");

        for(int i = 0; i  < this.myContacts.size();i++){
            if(this.myContacts.get(i) != null){

                System.out.println((i+1)+". "+ this.myContacts.get(i).getName() + " -> "+ this.myContacts.get(i).getPhoneNumber());
            }else{
                System.out.println("Contact List is empty");

            }
        }

    }

}
