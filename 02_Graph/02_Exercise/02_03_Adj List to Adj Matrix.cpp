#include<bits/stdc++.h>
using namespace std;
const int N = 200;
int adjMatrix[N][N];
int main()
{
    int n, m;
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adjMatrix[u][v] = 1;
    }
    for (int u = 1; u <= n; u++)
    {
        for (int v = 1; v <= n; v++)
        {
            cout << adjMatrix[u][v] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// Sample Input
// Sample Output

// 3
// 5
// 1 2
// 2 3
// 1 3
// 3 1
// 3 2


// 0 1 1
// 0 0 1
// 1 1 0


