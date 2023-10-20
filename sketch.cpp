#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin >> test;
    for (int i = 1; i <= test; i++)
    {
        int n;
        cin >> n;
        long long int loot[n + 2];
        long long int memo[n + 2];
        for (int j = 0; j < n; j++)
        {
            cin >> loot[j]; 
        }
        if (n == 0)
        {
            cout << "Case " << i << ": " << 0 << "\n"; 
        }
        continue;
        memo[0] = loot[0];
        memo[1] = max(memo[0], loot[1]);
        for (int j = 2; j < n; j++)
        {
            long long int withCurrent = memo[j - 2] + loot[j];
            long long int withoutCurrent = memo[j - 1];
            memo[j] = max(withCurrent, withoutCurrent);
        }
        cout << "Case " << i << ": " << memo[n - 1] << "\n";
    }
    return 0;
}