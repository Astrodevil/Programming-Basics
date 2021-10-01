#include <iostream>
using namespace std;

int fibonacci(int number) {
  if(number == 1 || number == 2) {
    return 1;
  } else {
    return fibonacci(number - 1) + fibonacci(number - 2);
  }
}

int main() {
  int number;
  cout << "Type a number n to find the nth number in the Fibonacci Sequence: ";
  cin >> number;

  cout << fibonacci(number) << endl;

  return 0;
}
