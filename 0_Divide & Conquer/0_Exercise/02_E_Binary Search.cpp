#include<bits/stdc++.h>
using namespace std;
void searchElement(int arr[],int size, int query)
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
        else if(query < arr[mid]) right = mid - 1;
        else left = mid + 1;
    }
    if(found_at != -1) cout << found_at;
    else cout << "Not Found";
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i =0; i < n; i++)
    {
        cin >> arr[i];
    }
    int query_val;
    cin >> query_val;
    searchElement(arr, n, query_val);
    return 0;
}
