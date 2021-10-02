// 1
// 0 1
// 1 0 1
// 1 0 1 0 1

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << ((i + j) % 2 == 0 ? 1 : 0) << " ";
        }
        cout << endl;
    }
}