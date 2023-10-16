#include<bits/stdc++.h>
using namespace std;
int main()
{
    int count, container;
    cin >> count >> container;
    int weight[count + 1];
    int val[count + 1];
    for (int i = 0; i < count; i++)
    {
        cin >> weight[i];
        cin >> val[i];
    }
    int knapsack[count + 1][container + 1];
    for (int i = 0; i <= count; i++)
    {
        for (int  j = 0; j <= container; j++)
        {
            // basecase
            if (i == 0 || j == 0) knapsack[i][j] = 0;
        }
    }
    for (int i = 1; i <= count; i++)
    {
        for (int j = 1; j <= container; j++)
        {
            if (weight[i] <= j)
            {
                int withCurrent = knapsack[i - 1]
            }
        }
    }
    return 0;
}