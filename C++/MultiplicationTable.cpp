//C++ program to print the multiplication table of a number

#include<iostream>
using namespace std;

int main()
{
    int number, n;
    cout<<"Enter the number whose table you wish to print:";
    cin>>number;
  
    cout<<"Enter the number upto which you wish to print the table:";
    cin>>n;
    
    for(int i=1; i<=n; ++i)
    {
        cout<<number<<" x "<<i<<" = "<<number*i<<endl;
    }
  
    return 0;
}
