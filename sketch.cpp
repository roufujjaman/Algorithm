#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string number;
    cin >> n >> number;
    for (int i = 0; i < n; i++)
    {
        if (n % 2 != 0 && i == n - 1)
        {
            cout << number[i];
            continue;
        }
        if (i != 0 && i % 2 == 0) cout << "-";
        cout << number[i];
    }
    return 0;
}