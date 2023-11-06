#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        int mem[N + 1][W + 1];
        for (int i = 0; i <= N; i++) mem[i][0] = 0;
        for (int j = 0; j <= W; j++) mem[0][j] = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                if (wt[i - 1] <= j)
                {
                    mem[i][j] = max(val[i - 1] + mem[i][j - wt[i - 1]], mem[i - 1][j]);
                }
                else
                {
                    mem[i][j] = mem[i - 1][j];
                }
            }
        }
        return mem[N][W];
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution obj;
        cout<<obj.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}