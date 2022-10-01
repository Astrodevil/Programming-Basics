#include <bits/stdc++.h>
using namespace std;

void BFS()
{
    queue<int> q;
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0},
        {1, 1, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};

    for (int i = 0; i < 7; i++)
    {
        int visited[7] = {0, 0, 0, 0, 0, 0, 0};
        cout << "BFS through vertex " << i << ":" << endl;
        cout << i << " ";
        visited[i] = 1;
        q.push(i);
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int j = 0; j < 7; j++)
            {
                if (a[x][j] == 1 && visited[j] == 0)
                {
                    cout << j << " ";
                    visited[j] = 1;
                    q.push(j);
                }
            }
        }
        cout << endl;
    }
}

int main()
{
    BFS();
    return 0;
}
