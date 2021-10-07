#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int countOne(int n)
{
    int ans = 0;
    while (n)
    {
        ans++;
        n = n & n - 1;
    }
    return ans;
}

int main(void)
{
    int n;
    cin >> n;
    cout << countOne(n);
}