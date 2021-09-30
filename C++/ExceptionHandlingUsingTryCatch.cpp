
#include <iostream>

using namespace std;
void divide(int numerator,int denominator)
{
    //try block: We add the that part of code which might throw exception
    try
    {
        if(denominator==0)
        throw denominator;//throw statement:used to Handle Exceptions
        cout<<numerator/denominator;
        
    }
    catch(int x)//catch block:It catches the exception;
    {
        cout<<"Exception Occurred and handled successfully"<<endl;
    }
}

int main()
{
    
    int numerator,denominator,result;
    cout<<"Enter a number"<<endl;
    cin>>numerator;
    //We have set denominator 0 as dividing any number by 0 causes exception
    denominator=0;
    cout<<"Trying to divide by 0"<<endl;
    divide(numerator,denominator);
    
    //Now we set denominator to a non zero value
    denominator=5;
    cout<<"Trying to divide by non zero value(5)"<<endl;
    divide(numerator,denominator);
    
    return 0;
}