#include<bits/stdc++.h>
using namespace std;
int test(int i = 0,int sz = 0)
{
    if (i == 5) return 0;
    sz = 1 + test(i + 1);
    return sz;
}
int main()
{
    cout << test();
    return 0;
}