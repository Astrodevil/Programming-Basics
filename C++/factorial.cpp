#include<iostream>
using namespace std;
int main()
{
    int i,fact=1, number;
    cout<<"Enter the Number:\n";
    cin>>number;
    for(i=1;i<=number;i++){
        fact=fact*i;
    }
    cout<<"Factorial of entered number is:\n"<<fact<<endl;
    return 0;
}
