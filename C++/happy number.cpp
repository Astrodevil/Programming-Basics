#include <iostream>
using namespace std;
int find(int n)
{
    
    int sum=0,r;
    while(n!=0)
    {
        r=n%10;
        sum=sum+(r*r);
        n=n/10;
    }
    
    if ((sum==1)||(sum==7))
    {
        return 1;
    
    }
    else if((sum==2)||(sum==3)||(sum==4)||(sum==5)||(sum==6)||(sum==8)||(sum==9))
    {
    return 0;
    }
    else
    find(sum);
}
int main()
{
    int test;
    cout<<"enter a number\n";
    cin>>test;
    if(find(test))
    {
        cout<<"its happy";
        
    }
    else
    cout<<"its not happy";
    return 0;
    
    
    
    
}
