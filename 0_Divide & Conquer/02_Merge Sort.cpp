#include<bits/stdc++.h>
using namespace std;
void merge(int arr[], int left, int right, int mid)
{
    int left_size = mid - left + 1;
    int arr_left[left_size + 1];
    arr_left[left_size] = INT_MAX;

    int right_size = right - mid;
    int arr_right[right_size + 1];
    arr_right[right_size] = INT_MAX;

    for (int i = 0, j = left; j <= mid; i++)
    {
        arr_left[i] = arr[j++]; 
    }
    for (int i = 0, j = mid + 1; j <= right; i++)
    {
        arr_right[i] = arr[j++];
    }

    int ptr1 = 0, ptr2 = 0;
    for (int i = left; i <= right; i++)
    {
        if(arr_left[ptr1] < arr_right[ptr2]) arr[i] = arr_left[ptr1++];
        else arr[i] = arr_right[ptr2++];
    }
}
void mergesort(int arr[], int left, int right)
{
    if (left == right) return;
    int mid = (left + right) / 2;
    mergesort(arr, left, mid);
    mergesort(arr, mid + 1, right);
    merge(arr, left, right, mid);
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
    mergesort(arr, 0, n);
    // mergesort(arr, 0, n - 1) for descending order
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}