string findLCS(int n, int m,string &s1, string &s2){
	int mem[n + 1][m + 1];
	for (int i = 0; i <= n; i++) mem[i][0] = 0;
	for (int j = 0; j <= m; j++) mem[0][j] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				mem[i][j] = 1 + mem[i - 1][j - 1];
			}
			else
			{
				mem[i][j] = max(mem[i - 1][j], mem[i][j - 1]);
			}
		}
	}	
	string s3;
	while (n != 0 && m != 0)
	{
		if (s1[n - 1] == s2[m - 1])
		{
			s3.push_back(s1[n - 1]);
			n--;
			m--;
		}
		else
		{
			if (mem[n][m - 1] > mem[n - 1][m])
			{
				m--;
			}
			else
			{
				n--;
			}
		}
	}
	reverse(s3.begin(), s3.end());
	return s3;
}