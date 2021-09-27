#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void unique2(vector<int> vec, int n)
{
    int ans1, ans2, temp, pos = 0, xorRes = vec[0];
    for (int i = 1; i < n; i++)
    {
        xorRes = xorRes ^ vec[i];
    }
    temp = xorRes;
    ans1 = 0;
    while (ans1 != 1)
    {
        ans1 = (temp & 1);
        temp = temp >> 1;
        pos++;
    }
    pos--;
    ans1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (vec[i] & (1 << pos))
        {
            ans1 = xorRes ^ vec[i];
        }
    }
    ans2 = xorRes ^ ans1;
    cout << ans1 << " " << ans2;
}

int main(void)
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    unique2(vec, n);
}