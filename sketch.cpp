#include<bits/stdc++.h>
using namespace std;
int fibonacci(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    int first = fibonacci(n - 1);
    int second = fibonacci(n - 2);
    return first + second;
}
int main()
{
    int input_val;
    cin >> input_val;
    cout << fibonacci(input_val);
    return 0;
}