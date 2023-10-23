#include<bits/stdc++.h>
using namespace std;
int subsetSum(int n, int target, int arr[])
{
    // basecase
    if (n == 0)
    {
        if (target == 0) return 1;
        else return 0;
    }
    
    // arr[] contains set elements starts from 0
    if (arr[n - 1] <= target)
    {
        int with = subsetSum(n - 1, target - arr[n - 1], arr);
        int without = subsetSum(n - 1, target, arr);
        return with + without;
    }
    else
    {
        return subsetSum(n - 1, target, arr);
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    cout << subsetSum(n, target, arr);
    return 0;
}



// 4
// 1 3 4 5
// 5