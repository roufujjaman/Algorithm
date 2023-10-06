#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int fib_arr[N];
void init_arr()
{
    for (int i = 0; i <= N; i++)
    {
        fib_arr[i] = -1;
    }
}
int fibonacci(int n)
{
    // base case 1 & 2;
    if (n == 0) return 0;
    if (n == 1) return 1;

    // memoization
    if (fib_arr[n] != -1)
    {
        return fib_arr[n];
    }

    int left = fibonacci(n - 1);
    int right = fibonacci(n - 2);

    // memoization
    fib_arr[n] = left + right;
    return left + right;
}
int main()
{
    int input_val;
    cin >> input_val;
    init_arr();
    cout << fibonacci(input_val);
    return 0;
}
