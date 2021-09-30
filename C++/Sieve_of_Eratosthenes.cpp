#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> primes;

void generate(int n) {
    primes.resize(n, true);

    primes[0] = false;
    primes[1] = false;

    for (int i = 1; i <= sqrt(n); i++)
        if (primes[i])
            for (int j = 2 * i; j < n; j += i)
                primes[j] = false;
}

int main() {
    int n;
    cin >> n;

    generate(n);

    for (int i = 0; i < n; i++)
        if (primes[i])
            cout << i << " ";

    return 0;
}