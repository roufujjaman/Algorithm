class Solution {
public:
    int n, m;
    vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int visited[50][50];
    int color_to_fill;
    bool is_valid(int i, int j)
    {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    void dfs(int i, int j, vector<vector<int>>& g, int color)
    {
        if (g[i][j] != color_to_fill) return;
        g[i][j] = color;
        visited[i][j] = true;
        for (pair<int, int> d: direction)
        {
            int ni = i + d.first;
            int nj = j + d.second;
            if (is_valid(ni, nj) && !visited[ni][nj])
            {
                dfs(ni, nj, g, color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size();
        m = image[0].size();
        color_to_fill = image[sr][sc];
        dfs(sr, sc, image, color);
        return image;
    }
};