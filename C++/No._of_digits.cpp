#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define  ll long long 
using namespace std;

class solution{
public:
    int digits(ll int n){
        //very very important concept rather than doing modulo 10
        return floor(log10(n)+1);
    }
    
};

int main(){
    ll int n;
    solution ob;
    cout<<"Enter a no.: ";
    cin>>n;

    cout<<n<<" has no. of digits = "<<ob.digits(n);

    return 0;
}