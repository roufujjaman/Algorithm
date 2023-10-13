#include<bits/stdc++.h>
using namespace std;
int knapsack(int position, int size, int val[], int weight[])
{
    // base case
    if (position == 0 || size == 0) return 0; 

    if (weight[position] <= size)
    {
        // option - 1 : includes current item
        int withCurrent = knapsack(position - 1, size - weight[position], val, weight) + val[position];
        // option - 2 : exclude current item
        int withoutCurrent = knapsack(position - 1, size, val, weight);
        return max(withCurrent, withoutCurrent);
    }
    else
    {
        // current item is overweighed hence excluded
        return knapsack(position - 1, size, val, weight);
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
    cout << knapsack(count, size, val, weight);
    return 0;
}
