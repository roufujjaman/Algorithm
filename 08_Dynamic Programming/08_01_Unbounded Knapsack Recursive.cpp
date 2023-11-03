#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
int mem[N][N];
void init_mem(int n, int s)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            mem[i][j] = -1;
        }
    }
}
int fn(int n, int s, int val[], int weight[])
{
    if (n == 0 || s == 0) return 0;
    if (mem[n][s] != -1) return mem[n][s];
    if (weight[n - 1] <= s)
    {
        int left = val[n - 1] + fn(n, s - weight[n - 1], val, weight);
        int right = fn(n - 1, s, val, weight);
        return mem[n][s] = max(left, right); 
    }
    return mem[n][s] = fn(n - 1, s, val, weight);
}
int main()
{
    int n, w;
    cin >> n >> w;
    int val[n], weight[n];
    for (int i = 0; i < n; i++) cin >> val[i];
    for (int i = 0; i < n; i++) cin >> weight[i];
    init_mem(n, w);
    cout << fn(n, w, val, weight);
    return 0;
}


// 4 6
// 5 3 2 4
// 4 1 3 2