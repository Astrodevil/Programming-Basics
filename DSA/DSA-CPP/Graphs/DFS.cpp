#include <bits/stdc++.h>
using namespace std;

int a[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0, 0},
    {1, 0, 0, 1, 1, 0, 0},
    {1, 1, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}};
int visited[7] = {0, 0, 0, 0, 0, 0, 0};

void DFS(int i)
{
    cout << i << " ";
    visited[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if (a[i][j] == 1 && !visited[j])
        {
            DFS(j);
        }
    }
}

int main()
{
    int k;
    cout << "Enter vertex through which you want to find DFS (0-6): ";
    cin >> k;
    if (k >= 0 && k < 7)
    {
        cout << "DFS through vertex " << k << ":" << endl;
        DFS(k);
    }
    else
    {
        cout << "Invalid vertex" << endl;
    }
    return 0;
}
