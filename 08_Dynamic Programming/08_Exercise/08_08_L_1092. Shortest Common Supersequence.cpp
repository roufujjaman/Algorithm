class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int mem[n + 1][m + 1];
        for (int i = 0; i <= n; i++) mem[i][0] = 0;
        for (int j = 0; j <= m; j++) mem[0][j] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
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
        string str3;
        while (n != 0 && m != 0)
        {
            if (str1[n - 1] == str2[m - 1])
            {
                str3.push_back(str1[n - 1]);
                n--;
                m--;
            }
            else
            {
                if (mem[n - 1][m] > mem[n][m - 1])
                {
                    str3.push_back(str1[n - 1]);
                    n--;
                }
                else
                {
                    str3.push_back(str2[m - 1]);
                    m--;
                }
            }
        }
        while (n != 0)
        {
            str3.push_back(str1[n - 1]);
            n--;
        }
        while (m != 0)
        {
            str3.push_back(str2[m - 1]);
            m--;
        }
        reverse(str3.begin(), str3.end());
        return str3;
    }
};