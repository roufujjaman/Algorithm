#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int mem[N];
void init_mem(int n)
{
    for (int i = 0; i <= n; i++)
    {
        mem[i] = -1;
    }
}
bool fn(int n, int target)
{
    if (n > target) return false;
    if (n == target) return true;
    if (mem[n] != -1) return mem[n];
    return mem[n] = fn(n + 3, target) || fn (n * 2, target); 
}
int main() {
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        int target;
        cin >> target;
        init_mem(target);
        fn(1, target)? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}


// Sample Input 0

// 5
// 1
// 3
// 5
// 15
// 16
// Sample Output 0

// YES
// NO
// YES
// NO
// YES