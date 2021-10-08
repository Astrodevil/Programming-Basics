// ####
// #  #
// #  #
// #  #
// ####

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    int len, bre;
    cin >> len;
    cin >> bre;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < bre; j++)
        {
            if (j == 0 || j == bre - 1 || i == 0 || i == len - 1)
            {
                cout << "#";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}