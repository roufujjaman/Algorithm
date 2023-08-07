#include<bits/stdc++.h>
using namespace std;
void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr[]) // O(n + m)
{
    int i = 0, j = 0, k = 0;
    // traverse both arrays
    while (i < n1 && j < n2)
    {
        if(arr1[i] < arr2[j]) arr[k++] = arr1[i++];
        else arr[k++] = arr2[j++];
    }

    // insert remaining elements
    while (i < n1)
    {
        arr[k++] = arr1[i++];
    }    
    while (j < n2)
    {
        arr[k++] = arr2[j++];
    }
}
int main()
{
    int n1, n2;
    cin >> n1;
    int arr_1[n1];
    for(int i = 0; i < n1; i++)
    {
        cin >> arr_1[i];
    }
    cin >> n2;
    int arr_2[n2];
    for(int i = 0; i < n2; i++)
    {
        cin >> arr_2[i];
    }

    int arr_3[n1+n2];
    mergeArrays(arr_1, arr_2, n1, n2, arr_3); // merge two sorted arrays

    for(int i = 0; i < n1 + n2; i++)
    {
        cout << arr_3[i] << ' ';
    }
    return 0;
}
