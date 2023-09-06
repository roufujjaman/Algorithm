#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int n, m;
vector<string> g;
int visited[N][N];
int level[N][N];
pair<int, int> parent[N][N];
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
    parent[si][sj] = {-1, -1};

    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        
        q.pop();

        if (is_valid(i + 1, j) && !visited[i + 1][j] && g[i + 1][j] != 'x')
        {
            q.push({i + 1, j});
            visited[i + 1][j] = true;
            level[i + 1][j] = level[i][j] + 1;
            parent[i + 1][j] = {i, j};
        }
        if (is_valid(i - 1, j) && !visited[i - 1][j] && g[i - 1][j] != 'x')
        {
            q.push({i - 1, j});
            visited[i - 1][j] = true;
            level[i - 1][j] = level[i][j] + 1;
            parent[i - 1][j] = {i, j};
        }
        if (is_valid(i, j + 1) && !visited[i][j + 1] && g[i][j + 1] != 'x')
        {
            q.push({i, j + 1});
            visited[i][j + 1] = true;
            level[i][j + 1] = level[i][j] + 1;
            parent[i][j + 1] = {i, j};
        }
        if (is_valid(i, j - 1) && !visited[i][j - 1] && g[i][j - 1] != 'x')
        {
            q.push({i, j - 1});
            visited[i][j - 1];
            level[i][j - 1] = level[i][j] + 1;
            parent[i][j - 1]= {i, j};
        }
    }
}
int main()
{
    cin >> n >> m;
    int si, sj, ei, ej;  // start, end
    for (int i = 0; i < n; i++)
    {
        string input_val;
        cin >> input_val;
        g.push_back(input_val);
        for (int j = 0; j < m; j++)
        {
            if (input_val[j] == 's') si = i, sj = j;
            if (input_val[j] == 'e') ei = i, ej = j;
        }
    }
    bfs(si, sj);
    if (level[ei][ej] != 0) cout << level[ei][ej] << "\n";
    else 
    {
        cout << "-1"; 
        return 0;
    }

    vector<pair<int, int>> path;
    pair<int, int> current = {ei, ej};
    while (!(current.first == -1 && current.second == -1))
    {
        path.push_back({current.first, current.second});
        current = parent[current.first][current.second];
    }
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
