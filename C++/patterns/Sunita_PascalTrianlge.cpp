// C++ program for Pascal’s Triangle

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n][n];
    for (int l = 0; l < n; l++)
    {
        for (int i = 0; i <= l; i++)
        {
         if (l == i || i == 0)
            arr[l][i] = 1;
         else
            arr[l][i] = arr[l-1][i-1] +arr[l-1][i];
         cout << arr[l][i] << " ";
        }
        cout <<endl;
    }
    return 0;
}
