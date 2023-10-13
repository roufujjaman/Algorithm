#include<bits/stdc++.h>
using namespace std;
int memo[1005][1005];
void init_memo(int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            memo[i][j] = -1;
        }
    }
}
int knapsack(int position, int size, int val[], int weight[])
{
    // base case
    if (position == 0 || size == 0) return 0; 

    // lookup for value if exist
    if (memo[position][size] != -1) return memo[position][size];

    if (weight[position] <= size)
    {
        // option - 1 : includes current item
        int withCurrent = knapsack(position - 1, size - weight[position], val, weight) + val[position];
        // option - 2 : exclude current item
        int withoutCurrent = knapsack(position - 1, size, val, weight);
        return  memo[position][size] = max(withCurrent, withoutCurrent);
    }
    else
    {
        // current item is overweighed hence excluded
        return memo[position][size] = knapsack(position - 1, size, val, weight);
    } 
}
int main()
{
    int count;
    cin >> count;
    int val[count + 1], weight[count + 1];
    for (int i = 1; i <= count; i++)
    {
        cin >> val[i];
    }
    for (int i = 1; i <= count; i++)
    {
        cin >> weight[i];
    }
    int size;
    cin >> size;
    
    init_memo(size);
    
    cout << knapsack(count, size, val, weight);
    
    return 0;
}