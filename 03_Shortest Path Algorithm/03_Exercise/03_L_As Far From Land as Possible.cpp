#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int visited[N][N];

int main()
{
    int n, m;
    cin >> n >> m;
    queue<pair<int, int>> sources;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int val;
            cin >> val;
            if ( val == 1 && val == 1) sources.push({i, j});
        }
    }
    
    while (!sources.empty())
    {

    }

    
    return 0;
}
