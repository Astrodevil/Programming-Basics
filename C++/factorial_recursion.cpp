#include <iostream>
using namespace std;
 
int factorial(int n) {
  
    // single line to find factorial
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}
 
int main() {
  
    int num = 5;
    cout << "Factorial of " << num << " is "<< factorial(num);
    return 0;
  
}
 
