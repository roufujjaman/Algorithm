#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int dist[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int input_val;
            cin >> input_val;
            dist[i][j] = input_val;
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}