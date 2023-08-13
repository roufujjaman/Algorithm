#include<bits/stdc++.h>
using namespace std;
// struct TWO
// {
//     int first;
//     int second;
// };
const int N = 100;
vector<pair<int,int>> adj[N];
int main()
{
    int n, m; // n - number of nodes, m - number of edges
    cin >> n >> m;
    int u, v, w;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }  
    for (int i = 0; i < m; i++)
    {
        cout << "L[" << i << "]" << "- ";
        for (pair<int, int> j:adj[i])
        {
            printf("{%d, %d} ", j.first, j.second);
        }
        cout << '\n';
    }
    return 0;
}
