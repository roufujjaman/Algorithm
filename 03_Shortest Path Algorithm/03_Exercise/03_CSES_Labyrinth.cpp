#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 11;
vector<pair<int, int>> direction = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

vector<string> g;
int visited[N][N];
int level[N][N];
pair<int, int> parent[N][N];
int n, m;

bool is_valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});           // source i, j;
    visited[si][sj] = true;
    level[si][sj] = 0;
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;

        q.pop();

        for (pair<int, int> d: direction)
        {
            int ni = i + d.first; // new i;
            int nj = j + d.second; // new j;

            if (is_valid(ni, nj) && !visited[ni][nj] && g[ni][nj] != '#')
            {
                q.push({ni, nj});
                visited[ni][nj] = true; // OR visited[ni][nj] = 1;
                level[ni][nj] = level[i][j] + 1;
                parent[ni][nj] = {i, j};
            }
        }
    }

}
int main()
{
    cin >> n >> m;
    int si, sj, di, dj;
    for (int i = 0; i < n; i++)
    {
        string input_str;
        cin >> input_str;
        g.push_back(input_str);
        for (int j = 0; j < m; j++)
        {
            if (input_str[j] == 'A') si = i, sj = j;
            if (input_str[j] == 'B') di = i, dj = j;
        }
    }
    bfs(si, sj);
    int l = level[di][dj];
    if (l != 0)
    {
        cout << "YES" << "\n" << l << "\n";
    }
    else
    {
        cout << "NO" << "\n";
        return 0;
    }
    vector<pair<int, int>> path;
    pair<int, int> current = {di, dj};
    while (!(current.first == si && current.second == sj)) // error-prone !(cond && cond)
    {
        path.push_back({current.first, current.second});
        current = parent[current.first][current.second];
    }
    // while (!(current.first == 0 && current.second == 0)) // error-prone
    // {
    //     path.push_back({current.first, current.second});
    //     current = parent[current.first][current.second];
    // }
    path.push_back({si, sj});
    reverse(path.begin(), path.end());

    for (int i = 1; i < path.size(); i++)
    {
        if (path[i].first == path[i - 1].first)
        {
            if (path[i].second < path[i - 1].second) cout << 'L';
            else cout << 'R';
        }
        else
        {
            if (path[i].first < path[i - 1].first) cout << 'U';
            else cout << 'D';
        }
    }
    return 0;
}
