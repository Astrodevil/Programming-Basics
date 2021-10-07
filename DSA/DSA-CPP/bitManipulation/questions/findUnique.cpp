#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int findUnique(vector<int> vec, int n)
{
    int ans = vec[0];
    for (int i = 1; i < n; i++)
    {
        ans = ans ^ vec[i];
    }
    return ans;
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
    cout << findUnique(vec, n);
}