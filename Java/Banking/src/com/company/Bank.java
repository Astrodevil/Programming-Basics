package com.company;

import java.util.ArrayList;

public class Bank {
    private String name;
    private ArrayList<Branch> branches;

    public Bank(String name){
        this.name = name;
        this.branches = new ArrayList<Branch>();
    }

    // find the name of the branch
    private Branch findBranch(String branchName){
        for (Branch branch : this.branches) {
            String searchName = branch.getName();
            if (branchName.equals(searchName)) {
                return branch;
            }
        }
        return null;
    }

    // add branch
    public boolean addBranch(String branchName){
        Branch existingBranch = findBranch(branchName);
        if(existingBranch == null){
            Branch newBranch = new Branch(branchName);
            branches.add(newBranch);
            System.out.println(branchName + " branch added successfully");
            return true;
        }else{
            System.out.println("branch name already exists");

        }
        return  false;
    }

    // add customer
    public boolean addCustomer(String customerName, String branchName, double initialTransaction){
        Branch existingBranch = findBranch(branchName);
        System.out.println("branch is " + branchName);

        if(existingBranch != null){
            existingBranch.newCustomer(customerName,initialTransaction);
            System.out.println("customer -> " + customerName + " added successfully to " + branchName);
            return true;
        }else{
            System.out.println("something went wrong");
        }
        return false;
    }

    // add customer transaction
    public boolean addCustomerTransaction(String customerName, String branchName, double initialTransaction){
        Branch existingBranch = findBranch(branchName);
        if(existingBranch != null){
            System.out.println("Customer " + customerName + " transaction ->" + initialTransaction);
            existingBranch.addCustomerTransaction(customerName,initialTransaction);
            return true;
        }
        return false;
    }

    public boolean listCustomer(String branchName, boolean printTransaction){
        Branch existingBranch = findBranch(branchName);
        if(existingBranch != null && printTransaction){
            System.out.println("Customers for " + branchName);
            for(int i=0; i<existingBranch.getCustomers().size(); i++){
                System.out.println("Customer " + existingBranch.getCustomers().get(i).getName());
                System.out.println("transactions ");
                for(int j=0; j<existingBranch.getCustomers().get(i).getTransaction().size(); j++){
                    System.out.println("[" + (j+1) + "]  Amount " +existingBranch.getCustomers().get(i).getTransaction().get(j));
                }
            }
            return true;
        }else if(existingBranch != null){
            System.out.println("Customer details for branch " + existingBranch.getName());
            for(int i=0; i<existingBranch.getCustomers().size(); i++) {
                System.out.println("Customer: " + existingBranch.getCustomers().get(i).getName() + "[" + (i+1) + "]");
            }
            return true;
        }
        return false;
    }


}
