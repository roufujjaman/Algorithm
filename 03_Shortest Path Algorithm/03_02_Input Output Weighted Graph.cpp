#include<bits/stdc++.h>
using namespace std;
const int N = 20;
vector<pair<int, int>> adj[N];
int main()
{
    int n, m;
    cin >> n >> m;
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for (int u = 0; u < N; u++)
    {
        if (adj[u].empty() == true) continue;

        cout << "N[" << u << "] : ";
        for (pair<int, int> vpair: adj[u])
        {
            cout << "{" << vpair.first << ", ";
            cout << vpair.second << "} ";
        }
        cout << "\n";
    }
    return 0;
}

// 8
// 11
// 3 10 5
// 3 5 3
// 3 8 2
// 3 4 1
// 5 6 6
// 5 7 2
// 10 6 7
// 6 7 1
// 7 9 3
// 9 4 10
// 8 7 11
