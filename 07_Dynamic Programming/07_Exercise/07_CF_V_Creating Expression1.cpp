#include<bits/stdc++.h>
using namespace std;
bool knapsack(int position, long long int sum, int res, int items[])
{
    if (position == 0 && sum == res) return true;
    if (position == 0 && sum != res) return false;
    bool add_curr = knapsack(position - 1, sum + (long long int)items[position], res, items);
    bool subtract_curr = knapsack(position - 1, sum - (long long int)items[position], res, items);
    return add_curr || subtract_curr;
}
int main()
{
    int count, res;
    cin >> count >> res;
    int arr[count + 1];
    for (int i = 1; i <= count; i++)
    {
        cin >> arr[i];
    }
    if (knapsack(count, 0, res, arr)) cout << "YES";
    else cout << "NO";
    return 0;
}