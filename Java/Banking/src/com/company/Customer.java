package com.company;

import java.util.ArrayList;

public class Customer {
    private String name;
    private ArrayList<Double> transaction;

    public Customer(String name, double initialTransaction){
        this.name = name;
        transaction = new ArrayList<Double>();
        this.addTransaction(initialTransaction);
    }

    public String getName() {
        return name;
    }

    public ArrayList<Double> getTransaction() {
        return transaction;
    }

    public void addTransaction(double transaction){
        this.transaction.add(transaction);
    }
}
