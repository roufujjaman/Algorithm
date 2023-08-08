#include<bits/stdc++.h>
using namespace std;
int binarysearch(int arr[], int size, int query)
{
    int left = 0;
    int right = size - 1;
    int mid;
    int found_at = -1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if(query == arr[mid])
        {
            found_at = mid;
            break;
        }
        else if (query < arr[mid]) right = mid - 1;
        else left = mid + 1;

    }
    return found_at;
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
    int query_val;
    cin >> query_val;
    int pos = binarysearch(arr, n, query_val);
    if(pos == -1) cout << "NO";
    else
    {
        if(pos == 0)
        {
            if(arr[1] == query_val) cout << "YES";
            else cout << "NO";
        }
        else if(pos == n - 1)
        {
            if(arr[n - 2] == query_val) cout << "YES";
            else cout << "NO";
        }
        else
        {
            if(arr[pos + 1] == query_val || arr[pos - 1] == query_val) cout << "YES";
            else cout << "NO";
        }
    }
    return 0;
}
