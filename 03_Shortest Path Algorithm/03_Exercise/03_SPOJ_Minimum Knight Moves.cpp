#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> direction = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
int level[8][8];
int visited[8][8];
bool is_valid(int i, int j)
{
    return (i >= 0 && i < 8 && j >= 0 && j < 8);
}
void reset_level_visited()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            level[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj]= true;
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

            if (is_valid(ni, nj) && visited[ni][nj] != true)
            {
                q.push({ni, nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string x, y;
        cin >> x >> y;
        int si, sj, di, dj; // source i, j, destination i, j;
        
        si = x[0] - 'a', sj = x[1] - '1';
        di = y[0] - 'a', dj = y[1] - '1';
        bfs(si, sj);
        cout << level[di][dj] << "\n";
        reset_level_visited();
    }
    return 0;
}
