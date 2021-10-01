#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void printSubset(vector<int> vec, int n)
{
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                cout << vec[j] << " ";
            }
        }
        cout << endl;
    }
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

    printSubset(vec, n);
}