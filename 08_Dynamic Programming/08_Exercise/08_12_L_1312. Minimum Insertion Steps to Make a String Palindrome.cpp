class Solution {
public:
    int minInsertions(string str1) {
        string str2 = str1;
        reverse(str2.begin(), str2.end());
        int n = str1.size();
        int mem[n + 1][n + 1];
        for (int i = 0; i <= n; i++)
        {
            mem[i][0] = 0;
            mem[0][i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    mem[i][j] = 1 + mem[i - 1][j - 1];
                }
                else
                {
                    mem[i][j] = max(mem[i - 1][j], mem[i][j - 1]);
                }
            }
        }
        return n - mem[n][n];
    }
};