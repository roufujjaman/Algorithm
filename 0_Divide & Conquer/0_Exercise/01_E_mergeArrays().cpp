#include<bits/stdc++.h>
using namespace std;
void mergeArrays(int arr1[], int arr2[], int size, int arr[])
{
    int j = 0, k = 0;
    for (int i = 0; i < size; i++)
    {
        if(arr1[j] > arr2[k]) arr[i] = arr1[j++];
        else arr[i] = arr2[k++];
    }
    
}
int main()
{ 
    int n1, n2;
    cin >> n1;
    int arr1[n1+1];
    arr1[n1] = INT_MIN;
    for(int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    cin >> n2;
    int arr2[n2 + 1];
    arr2[n2] = INT_MIN;
    for(int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }

    int arr3[n1 + n2];
    mergeArrays(arr1, arr2, n1 + n2, arr3);
    for(int i = 0; i < n1 + n2; i++)
    {
        cout << arr3[i] << ' ';
    }
    return 0;
}
