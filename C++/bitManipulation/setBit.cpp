#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int setBit(int n, int pos)
{
    return (n | 1 << pos);
}

int main(void)
{
    int n, pos;
    cin >> n >> pos;
    cout << setBit(n, pos);
}