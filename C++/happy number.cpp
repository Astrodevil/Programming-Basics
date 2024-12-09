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


int Sods(int n){ // Finds Square Digital Sum
    int Sum = 0;
    while(n!=0){
        int mod = (n%10);
        Sum += mod*mod;
        n = n/10;
    }
    return Sum;
}
bool find(int n)
{
    /*
    Tortise Hare Explanation:
    we have two variables Slow and Fast and a function Sods which calculates the sum of squares of digits of the input number.
    Each Iteration, We Run fast through Sods twice and run Slow through Sods once.
    If we make Fast update 2 times as fast as slow, then we will be able to find any cycle and if Fast is ever 1, then we know that the number is happy.
    Example:
    Test=2
    Fast | Slow
    -----+-----
     16  |  4
     58  | 16
     145 | 37
     20  | 58
     16  | 89
     58  | 145
     145 | 42
     20  | 20
    Since Fast is equal to Slow, 2 is an Unhappy Number
    Cycle: 2→4→16→37→58→89→145→42→20→4→16...
    */
    int Fast = Sods(Sods(n));
    int Slow = Sods(n);
    if(Fast == 1){
        return true; // Edge Case of n=1 which makes the while loop never happen but still is happy.
    }
    while(Fast != Slow){
        if(Fast == 1){
            return true;
        }
        Fast = Sods(Sods(Fast));
        Slow = Sods(Slow);
    }
    return false;
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
