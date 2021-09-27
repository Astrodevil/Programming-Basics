//     1
//    1 2
//   1 2 3
//  1 2 3 4
// 1 2 3 4 5

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k = 1;
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j <= i; j++)
        {
            cout << k++ << " ";
        }
        cout << endl;
    }
}