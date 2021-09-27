//     #####
//    #####
//   #####
//  #####
// #####

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < n; j++)
        {
            cout << "#";
        }
        cout << endl;
    }
}