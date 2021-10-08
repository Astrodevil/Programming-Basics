#include <iostream>
using namespace std;

int factorial(int number) {
    if(number == 1) {
        return 1;
    } else {
        return number * factorial(number - 1);
    }
}

int main() {
    //Define a number below to find the factorial of it
    int number = 10;
    cout << "The factorial of " << number << " is: " << factorial(number) << endl;
}
