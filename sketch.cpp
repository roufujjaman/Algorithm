#include<bits/stdc++.h>
using namespace std;
void mergesort(int arr[], int l, int r)
{
    if(l == r) return;
    int mid = (l + r) / 2;
    cout << arr[mid] << ' ';
    mergesort(arr, l, mid);
    mergesort(arr, mid + 1, r);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    mergesort(arr, 0, n - 1);
    return 0;
}