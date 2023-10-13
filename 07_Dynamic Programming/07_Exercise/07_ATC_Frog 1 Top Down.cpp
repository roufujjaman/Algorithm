#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
int memo[N];
void init_memeo()
{
    for (int i = 1; i <= N; i++)
    {
        memo[i] = -1;
    }
}
int jump(int arr[], int position)
{
    // base case - 1
    if (position == 1) return 0;
    // base case - 2
    if (position == 2)
    {
        return abs(arr[position] - arr[position - 1]);
    }

    // check if memoized for current position 
    if (memo[position] != -1) return memo[position];

    // choices
    int left = abs(arr[position] - arr[position - 1]) + jump(arr, position - 1);
    int right = abs(arr[position] - arr[position - 2]) + jump(arr, position - 2);
    return memo[position] = min(left, right);
}
int main()
{
    int count;
    cin >> count;
    int blocks[count + 1];
    for (int i = 1; i <= count; i++)
    {
        cin >> blocks[i];
    }
    init_memeo();
    cout << jump(blocks, count);
    return 0;
}
