#include<bits/stdc++.h>
using namespace std;
int main()
{
    int input_val;
    cin >> input_val;
    long long int fib_arr[input_val];
    fib_arr[0] = 0;
    fib_arr[1] = 1;

    for (int i = 2; i <= input_val; i++)
    {
        fib_arr[i] = fib_arr[i - 1] + fib_arr[i - 2];
    }
    cout << fib_arr[input_val];
    return 0;
}
