#include<bits/stdc++.h>
using namespace std;
int main()
{
    int count;
    cin >> count;
    int blocks[count + 1], memo[count + 1];
    for (int i = 1; i <= count; i++)
    {
        cin >> blocks[i];
    }

    // base case - 1
    memo[1] = 0;
    // base case - 2
    memo[2] = abs(blocks[1] - blocks[2]);

    // choices
    for (int i = 3; i <= count; i++)
    {
        int left = memo[i - 1] + abs(blocks[i] - blocks[i - 1]);
        int right = memo[i - 2] + abs(blocks[i] - blocks[i - 2]);

        memo[i] = min(left, right);
    }

    cout << memo[count];
    return 0;
}