/*Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Example 1:
19 is happy
Explanation:
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
*/



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
