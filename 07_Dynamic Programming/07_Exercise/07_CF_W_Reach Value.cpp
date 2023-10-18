#include<bits/stdc++.h>
using namespace std;
bool fn(long long int i,long long int res)
{
    if (i == res) return true;
    if (i > res) return false;
    return fn(i * 10, res) || fn(i * 20, res);
}
int main()
{
    int count;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        long long int input_val;
        cin >> input_val;
        if (fn(1, input_val)) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}

// input
// 5
// 1
// 2
// 10
// 25
// 200

// output
// YES
// NO
// YES
// NO
// YES