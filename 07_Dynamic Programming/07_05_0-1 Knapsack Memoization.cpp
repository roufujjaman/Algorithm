#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int memo[N][N];
void init_memo()
{
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
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
    int count, container;
    cin >> count >> container;
    int val[count + 1], weight[count + 1];
    for (int i = 1; i <= count; i++)
    {
        cin >> weight[i];
        cin >> val[i];
    }
    init_memo();
    cout << knapsack(count, container, val, weight);
    return 0;
}
// 3 8
// 3 30
// 4 50
// 5 60
