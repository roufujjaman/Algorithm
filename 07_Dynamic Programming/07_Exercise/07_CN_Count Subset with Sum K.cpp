int findWays(vector<int>& arr, int target)
{
	// why do i need this line can you please answer
	// without this line this function giving me wrong answer in a online judge
	int mod = 1e9 + 7 // this line
	int n = arr.size();
	int memo[n + 1][target + 1];
	memo[0][0] = 1;
	for (int i = 1; i <= target; i++)
	{
		memo[0][i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= target; j++)
		{
			if (arr[i - 1] <= j)
			{
				memo[i][j] = (memo[i - 1][j - arr[i - 1]] + memo[i - 1][j]) % mod; // use of mod here 
			}
			else
			{
				memo[i][j] = memo[i - 1][j] % mod; // use of mod here 
			}
		}
	}
	return memo[n][target];
}
