#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<string> g;
vector<pair<int, int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
int visited[N][N];
int level[N][N];
bool is_valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        
        q.pop();

        for (pair<int, int> d: direction)
        {
            int ni = i + d.first;
            int nj = j + d.second;

            if (is_valid(ni, nj) && !visited[ni][nj] && g[ni][nj] != 'x')
            {
                q.push({ni, nj});
                visited[ni][nj] = true; // true OR 1;
                level[ni][nj] = level[i][j] + 1;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    int si, sj, di, dj; // source i, j, destination i, j;
    for (int i = 0; i < n; i++)
    {
        string input_val;
        cin >> input_val;
        g.push_back(input_val);
        for (int j = 0; j < m; j++)
        {
            if(input_val[j] == 's') si = i, sj = j;
            if(input_val[j] == 'e') di = i, dj = j;
        }
    }
    bfs(si, sj);
    if (level[di][dj] != 0) cout << "YES\n\n";
    else cout << "NO\n\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << level[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
