#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {11, 21, 1, 4 , 3};
    sort(arr.begin(), arr.end());
    for(int i: arr)
    {
        cout << i << ' ';
    }
    return 0;
}
