#include<bits/stdc++.h>
using namespace std;
const int N = 100;
vector<pair<int, int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
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
            if ( val == 1 && val == 1)
            {
                sources.push({i, j});
                visited[i][j] = 1;
            }
        }
    }
    int level = -1; 
    while (!sources.empty())
    {
        level++;
        int queuq_sz = sources.size();
        
        while (queuq_sz--)
        {
            int i = sources.front().first;
            int j = sources.front().second;
            sources.pop();
            cout << "[";
            for (pair<int, int> d: direction)
            {
                cout << "()";
                int ni = i + d.first;
                int nj = j + d.second;

                if (ni < 0 || ni >= n || nj < 0 || nj >= m || visited[ni][nj] == 1) continue;

                visited[ni][nj] = true;
                sources.push({ni, nj});
            }
            cout << "]";
        }
    }
    cout << level;
    return 0;
}

// 5 5
// 1 0 0 0 1
// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0
// 1 0 0 0 1

// 1s are sources 