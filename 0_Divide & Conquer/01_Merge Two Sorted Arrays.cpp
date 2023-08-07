#include<bits/stdc++.h>
using namespace std;
void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr[]) // O(n + m)
{
    int j = 0, k = 0;
    int size = n1 + n2;
    for (int i = 0; i < size; i++)
    {
        if(arr1[j] < arr2[k]) arr[i] = arr1[j++];
        else arr[i] = arr2[k++];
    }
}
int main()
{
    int n1, n2;
    cin >> n1;
    int arr_1[n1 + 1];
    arr_1[n1] = INT_MAX; // input arr + an additional element INT_MAX for minimum comparison.
    for(int i = 0; i < n1; i++)
    {
        cin >> arr_1[i];
    }
    cin >> n2;
    int arr_2[n2 + 1];
    arr_2[n2] = INT_MAX; // input arr + an additional element INT_MAX for minimum comparison. 
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
