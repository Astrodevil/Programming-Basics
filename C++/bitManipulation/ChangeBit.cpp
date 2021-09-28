#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int updateBit(int n, int pos, int payload)
{
    n = (n & (~(1 << pos)));
    return (n | payload << pos);
}

int main(void)
{
    int n, pos, payload;
    cin >> n >> pos >> payload;
    cout << updateBit(n, pos, payload);
}