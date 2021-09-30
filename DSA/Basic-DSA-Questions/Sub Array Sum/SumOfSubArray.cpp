#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ar[n];
    for (int x = 0; x < n; x++) {
        cin >> ar[x];
    }
    int sum;
    for (int x = 0; x < n; x++) {
        sum = 0;
        for (int y = x; y < n; y++) {
            sum += ar[y];
            cout << sum << " ";
        }
    }
}