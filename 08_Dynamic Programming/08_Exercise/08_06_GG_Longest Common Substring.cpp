class Solution{
    public:
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
         int str_size = 0;
         int mem[n + 1][m + 1];
         
         for (int i = 0; i <= n; i++) mem[i][0] = 0;
         for (int j = 0; j <= m; j++) mem[0][j] = 0;
         for (int i = 1; i <= n; i++)
         {
             for (int j = 1; j <= m; j++)
             {
                 if (S1[i - 1] == S2[j - 1])
                 {
                     mem[i][j] = 1 + mem[i - 1][j - 1];
                 }
                 else
                 {
                     mem[i][j] = 0;
                 }
                 if (mem[i][j] > str_size) str_size = mem[i][j];
             }
         }
         return str_size;
    }
};