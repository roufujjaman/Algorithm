#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[8] = {12, 7, 3, 9, 18, 2, 5, 4};
    int count_steps = 0;
    for (int i = 0; i < 8 - 1; i++)
    {
        for(int j = i + 1; j < 8; j++)
        {
            if(arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
            count_steps++;
        }
    }
    for(int i = 0; i < 8; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n' << count_steps;
    return 0;
}