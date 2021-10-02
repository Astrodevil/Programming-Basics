// 1
// 2 3
// 4 5 6
// 7 8 9 10
// 11 12 13 14 15

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    int n, k = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << k++ << " ";
        }
        cout << endl;
    }
}