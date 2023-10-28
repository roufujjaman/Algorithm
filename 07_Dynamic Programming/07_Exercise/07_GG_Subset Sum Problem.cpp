#include<bits/stdc++.h> 
using namespace std; 
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        int memo[n + 1][sum + 1];
        memo[0][0] = 1;
        for (int i = 1; i <= sum; i++)
        {
            memo[0][i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                {
                    memo[i][j] = memo[i - 1][j - arr[i - 1]] || memo[i - 1][j];
                }
                else
                {
                    memo[i][j] = memo[i - 1][j];
                }
            }
        }
        return memo[n][sum];
    }
};
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 