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
            cin >> dist[i][j];
            if (dist[i][j] == -1) dist[i][j] = 1e9;
        }
    }
    int max_dist = 0;
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
            if(dist[i][j] != 1e9) max_dist = max(dist[i][j], max_dist);
        }
    }
    cout << max_dist;
    return 0;
}