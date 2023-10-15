#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int memo[N][N];
void inti_memo(int count)
{
    for (int i = 0; i <= count; i++)
    {
        for (int j = 0; j <= count; j++)
        {
            memo[i][j] = -1;
        }
    }
}
int knapsack(int position, int container_size, int weight[], int val[]) {
    // Base case
    if (position < 1 || container_size == 0) return 0;

    if (memo[position][container_size] != -1) return memo[position][container_size];

    // If the weight of the current item can be accommodated
    if (weight[position] <= container_size) {
        int withCurrent = knapsack(position - 1, container_size - weight[position], weight, val) + val[position];
        int withoutCurrent = knapsack(position - 1, container_size, weight, val);
        return memo[position][container_size] = max(withCurrent, withoutCurrent);
    } else {
        return memo[position][container_size] = knapsack(position - 1, container_size, weight, val);
    }
}

int main() {
    int count, container;
    cin >> count >> container;
    inti_memo(count);
    int weight[count + 1];
    int val[count + 1];
    for (int i = 1; i <= count; i++) {
        cin >> weight[i];
        cin >> val[i];
    }
    cout << knapsack(count, container, weight, val);
    return 0;
}
