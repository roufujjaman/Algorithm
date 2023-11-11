class Solution
{
    public:
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        int mem[m + 1][n + 1];
        for (int i = 0; i <= m; i++) mem[i][0] = 0;
        for (int j = 0; j <= n; j++) mem[0][j] = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (X[i - 1] == Y[j - 1])
                {
                    mem[i][j] = 1 + mem[i - 1][j - 1];
                }
                else
                {
                    mem[i][j] = max(mem[i - 1][j], mem[i][j - 1]);
                }
            }
        }
        return (m + n) - mem[m][n];
    }
};