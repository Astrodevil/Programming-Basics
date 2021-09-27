#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool powerOfTwo(int n)
{
    return (n && !(n & n - 1));
}

int main(void)
{
    int n;
    cin >> n;
    cout << powerOfTwo(n);
}