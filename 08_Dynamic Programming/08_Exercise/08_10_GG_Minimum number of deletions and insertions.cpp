class Solution{
	public:
	int minOperations(string str1, string str2) 
	{ 
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
	    return (n - mem[n][m]) + (m - mem[n][m]);
	} 
};