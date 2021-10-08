#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if (n < 2)
        return 1;
    else
        return n * fact(n - 1);
}

int pascalTriangle(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

int main()
{
    int no_of_rows;
    cin >> no_of_rows;
    for (int row = 0; row < no_of_rows; row++)
    {

        for (int space = 1; space <= no_of_rows - row; space++)
            cout << " ";

        for (int colunm = 0; colunm <= row; colunm++)
            cout << pascalTriangle(row, colunm) << " ";

        cout << endl;
    }
    return 0;
}