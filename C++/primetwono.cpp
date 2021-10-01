// CPP program to check if two
// numbers are co-prime or not
#include<bits/stdc++.h>
using namespace std;
 
// function to check and print if
// two numbers are co-prime or not
void coprime(int a, int b) {
     
    if ( __gcd(a, b) == 1)
        cout << "Co-Prime" << endl;
    else
        cout << "Not Co-Prime" << endl;       
}
 
// driver code
int main()
{
    int a = 5, b = 6;
    coprime(a, b);   
    a = 8, b = 16;
    coprime(a, b);       
    return 0;
}
