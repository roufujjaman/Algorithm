#include<bits/stdc++.h>
using namespace std;
int fibonacci(int n)
{
    // base case 1 & 2;
    if (n == 0) return 0;
    if (n == 1) return 1;
    int left = fibonacci(n - 1);
    int right = fibonacci(n - 2);
    return left + right;
}
int main()
{
    int input_val;
    cin >> input_val;
    cout << fibonacci(input_val);
    return 0;
}
