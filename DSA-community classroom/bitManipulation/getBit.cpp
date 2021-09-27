#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int getBit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}

int main(void)
{
    int n, pos;
    cin >> n >> pos;
    int res = getBit(n, pos);
    if (!res)
    {
        cout << "Opss!! Not 1 at position";
    }
    else
    {
        cout << "Yeah!! Found 1 at position";
    }
}