#include <bits/stdc++.h>
using namespace std;

int knapsack(int position, int container_size, int weight[], int val[]) {
    // Base case
    if (position < 1 || container_size == 0) return 0;

    // If the weight of the current item can be accommodated
    if (weight[position] <= container_size) {
        int withCurrent = knapsack(position - 1, container_size - weight[position], weight, val) + val[position];
        int withoutCurrent = knapsack(position - 1, container_size, weight, val);
        return max(withCurrent, withoutCurrent);
    } else {
        return knapsack(position - 1, container_size, weight, val);
    }
}

int main() {
    int count, container;
    cin >> count >> container;
    int weight[count + 1];
    int val[count + 1];
    for (int i = 1; i <= count; i++) {
        cin >> weight[i];
        cin >> val[i];
    }
    cout << knapsack(count, container, weight, val);
    return 0;
}
