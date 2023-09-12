#include <bits/stdc++.h>

using namespace std;
const int N = 1e2 + 10;
vector<pair<int, int>> knight_move = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
vector<vector<int>> visited(N, vector<int>(N, 0));
vector<vector<int>> level(N, vector<int>(N, -1));
void bfs(int si, int sj, int n, int m)
{
    queue<pair<int, int>> q;
    visited[si][sj] = true;
    level[si][sj] = 0;
    q.push({si, sj});
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for (pair<int, int> vpair: knight_move)
        {
            int ni = i + vpair.first;
            int nj = j + vpair.second;
            
            if (ni >= 0 && ni < n && nj >= 0 && nj <m)
            {
                if (!visited[ni][nj])
                {
                    visited[ni][nj] = true;
                    level[ni][nj] = level[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }
    }
}
int main()
{
    int count;
    cin >> count;
    for (int k = 0; k < count; k++)
    {
        int n, m, ki, kj, qi, qj;
        cin >> n >> m;
        cin >> ki >> kj;
        cin >> qi >> qj;
        bfs(ki, kj, n, m);
        cout << level[qi][qj] << "\n";
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                visited[i][j] = 0;
                level[i][j] = -1;
            }
        }
    }
    return 0;
}

// Sample Input 0

// 4
// 8 8
// 0 0
// 7 7
// 5 6
// 0 1
// 0 1
// 4 4
// 0 0
// 0 1
// 2 2
// 0 0
// 0 1
// Sample Output 0

// 6
// 0
// 3
// -1