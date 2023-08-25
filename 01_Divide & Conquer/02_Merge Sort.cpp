#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& arr, int left, int mid, int right)
{
    int left_size = mid - left + 1;
    int left_arr[left_size + 1];
    for (int i = 0; i < left_size; i++)
    {
        left_arr[i] = arr[left + i];
    }
    left_arr[left_size] = INT_MAX;

    int right_size = right - mid;
    int right_arr[right_size + 1];
    for (int i = 0; i < right_size; i++)
    {
        right_arr[i] = arr[mid + 1 + i];
    }
    right_arr[right_size] = INT_MAX;

    int ptr1 = 0, ptr2 = 0;
    for (int i = left; i <= right; i++)
    {
        if(left_arr[ptr1] < right_arr[ptr2])
        {
            arr[i] = left_arr[ptr1];
            ptr1++;
        }
        else
        {
            arr[i] = right_arr[ptr2];
            ptr2++;
        }
    }
}
void mergesort(vector<int> & arr, int left, int right)
{
    if (left == right) return;
    int mid = (left + right) / 2;
    mergesort(arr, left, mid);
    mergesort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergesort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}