#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a = {10, 20, 30, 100};
    vector<int> b = {2, 5, 5, 6, 11};
    vector<int> c = {};
    int i = 0;
    int j = 0;
    while (true)
    {
        if(i == a.size && j == b.size()) break;
        if(a[i] > a[j])
        {
            c.push_back(a[i]);
            i++;
            continue;
        }
        else if(a[i] < a[j])
        {
            c.push_back(a[j]);
            j++;
            continue;
        }
        else
        {
            c.push_back(a[i]);
            c.push_back(a[j]);
            i++;
            j++;
        }
    }
    
    return 0;
}