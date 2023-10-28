#include <bits/stdc++.h>
using namespace std;
class Solution{

  public:
	int minimunDifference(int arr[], int n)  { 
	    int s = 0;
	    for (int i = 0; i < n; i++)
	    {
	        s += arr[i];
	    }
	    int mem[n + 1][s + 1];
	    mem[0][0] = 1;
	    for (int i = 1; i <= s; i++) mem[0][i] = 0;
	    
	    for (int i = 1; i <= n; i++)
	    {
	        for (int j = 0; j <= s; j++)
	        {
	            if (arr[i - 1] <= j) mem[i][j] = mem[i - 1][j - arr[i - 1]] || mem[i - 1][j];
	            else mem[i][j] = mem[i - 1][j];
	        }
	    }
	    int m = INT_MAX;
	    for (int i = 0; i <= s; i++)
	    {
	        if (mem[n][i] == 1) 
	        {
	            m = min(m, abs((s - i) - i));
	        }
	    }
	    
	    return m;
	} 
};