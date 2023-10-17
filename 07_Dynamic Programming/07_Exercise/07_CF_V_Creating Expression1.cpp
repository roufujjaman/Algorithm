#include<bits/stdc++.h>
using namespace std;
long long int count_val, res;
long long int arr[21];
bool fn(long long int i, long long int sum)
{
    if (i == count_val) return sum == res;
    return fn(i + 1, sum + arr[i + 1]) || fn(i + 1, sum - arr[i + 1]);
}
int main()
{
    cin >> count_val >> res;
    for (int i = 0; i < count_val; i++)
    {
        cin >> arr[i];
    }
    if (fn(0, arr[0])) cout << "YES";
    else cout << "NO";   
    return 0;
}


// 5 5
// 1 2 3 4 5

// "YES"