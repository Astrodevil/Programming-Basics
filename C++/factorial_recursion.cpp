#include <iostream>
using namespace std;
 
long factorial(int n) {
    if(n==1){
        return 1; //1! is 1
    }
    if(n==0){
        return 1; //0! is 1
    }
    return n * factorial(n-1);
    /*
    n! is the same as n * (n-1)!
    n! equals n * (n-1) * (n-2)... 3 * 2 * 1
    (n-1)! equals (n-1) * (n-2)... 3 * 2 * 1
    (n-1)! * n equals n! and also equal to n * (n-1) * (n-2)... 3 * 2 * 1
    */
}
 
int main() {
  
    int num = 5;
    cout << "Factorial of " << num << " is "<< factorial(num);
    return 0;
  
}
 
