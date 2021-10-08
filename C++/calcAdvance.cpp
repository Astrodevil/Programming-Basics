#include<bits/stdc++.h>
using namespace std;

double add(double a, double b){
    return (a+b);
}

double subtract(double a, double b){
    return (a-b);
}

double multiply(double a, double b){
    return (a*b);
}

double divide(double a, double b){
    return (a/b);
}

int main(){
    int z;
    do{
        double a,b;
        char op;
        cout<<"Enter two numbers on whom you want to perform the arithmatical operation: ";
        cin>>a>>b;
        cout<<"Enter the arithmatic operation('+', '-', 'x', '/': ";
        cin>>op;
        switch(op){
            
            case '+':
            cout<<a<<op<<b<<" = "<<add(a,b);
            break;

            case '-':
            cout<<a<<op<<b<<" = "<<subtract(a,b);
            break;

            case 'x':
            cout<<a<<op<<b<<" = "<<multiply(a,b);
            break;

            case '/':
            cout<<a<<op<<b<<" = "<<divide(a,b);
            break;

            default:
            cout<<"Please choose a valid arithmatic operation from '+', '-', 'x', '/' only.";
        }
        cout<<endl<<"Enter the number as per the action you want to perform: ";
        cout<<endl<<"1.Perform another operation."<<endl;
        cout<<"2.Exit"<<endl;
        cin>>z;
    }while(z!=2);
    return 0;
}