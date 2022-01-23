package com.company;

import java.util.ArrayList;

public class Branch {
    private String name;
    private ArrayList<Customer> customers;

    public Branch(String name){
        this.name = name;
        this.customers = new ArrayList<Customer>();
    }

    public String getName() {
        return name;
    }

    public ArrayList<Customer> getCustomers() {
        return customers;
    }

    public boolean newCustomer(String name, double initialTransaction){
        if(findCustomer(name) != null){
            System.out.println("Customer name already exists");
            return  false;
        }else{
            Customer addNewCustomer = new Customer(name,initialTransaction);
            customers.add(addNewCustomer);
            return true;
        }

    }

    public boolean addCustomerTransaction(String name, double transaction){
        Customer existingCustomer = findCustomer(name);
        if(existingCustomer!= null){
            existingCustomer.addTransaction(transaction);
            return true;
        }else{
            return false;
        }
    }

    public Customer findCustomer(String name){
        int i=0;
        for(i=0; i<this.customers.size();i++){
            if(this.customers.get(i).getName().equals(name)){
                return this.customers.get(i);
            }
        }
        return null;
    }
}
