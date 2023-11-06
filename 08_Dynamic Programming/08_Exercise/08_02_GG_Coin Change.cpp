#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {

        // code here.
        long long int mem[N + 1][sum + 1];
        mem[0][0] = 1;
        for (int j = 1; j <= sum; j++) mem[0][j] = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (coins[i - 1] <= j)
                {
                    mem[i][j] = mem[i][j - coins[i - 1]] + mem[i - 1][j];
                }
                else
                {
                    mem[i][j] = mem[i - 1][j];
                }
            }
        }
        return mem[N][sum];
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }
    return 0;
}