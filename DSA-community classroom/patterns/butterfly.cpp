// $        $
// $$      $$
// $$$    $$$
// $$$$  $$$$
// $$$$$$$$$$
// $$$$$$$$$$
// $$$$  $$$$
// $$$    $$$
// $        $

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    int n;
    cin >> n;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= i; j--)
        {
            cout << "$";
        }
        for (int j = 0; j < 2 * i; j++)
        {
            cout << " ";
        }
        for (int j = n - 1; j >= i; j--)
        {
            cout << "$";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= i; j--)
        {
            cout << "$";
        }
        for (int j = 0; j < 2 * i; j++)
        {
            cout << " ";
        }
        for (int j = n - 1; j >= i; j--)
        {
            cout << "$";
        }
        cout << endl;
    }
}

// 0123
// @  @ 0
// @@
// @@@@@@ 1
