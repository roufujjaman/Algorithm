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
