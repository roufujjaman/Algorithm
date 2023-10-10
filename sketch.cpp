#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int memo[N];
void init_arr()
{
    for (int i = 0; i <= N; i++)
    {
        memo[i] = -1;
    }
}
int fibonacci(int position)
{
    // check for negative position
    if (position < 0) return -1;

    // base case 1 & 2;
    if (position == 0) return 0;
    if (position == 1) return 1;

    // lookup for value
    if (memo[position] != -1) return memo[position];

    // memoization
    memo[position] = fibonacci(position - 1) + fibonacci(position - 2);
    return memo[position];
}
int main()
{
    int input_val;
    cin >> input_val;
    init_arr();
    cout << fibonacci(input_val);
    return 0;
}

