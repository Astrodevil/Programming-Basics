//     1
//    212
//   32123
//  4321234
// 543212345

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k = i + 1;
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        while (k >= 1)
        {
            cout << k-- << " ";
        }
        k++;
        while (k < i + 1)
        {
            cout << ++k << " ";
        }
        cout << endl;
    }
}