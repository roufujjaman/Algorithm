#include<bits/stdc++.h>
using namespace std;
const int N = 200;
vector<int> adj[N];
int main()
{
    int n;
    cin >> n;
    int input_val;
    for (int u = 1; u <= n; u++)
    {
        for (int v = 1; v <= n; v++)
        {
            cin >> input_val;
            if (input_val)
            {
                adj[u].push_back(v);
            }
        }
    }   
    for (int u = 1; u <= n; u++)
    {
        cout << "List " << u << ": ";
        for (int v: adj[u])
        {
            cout << v << " ";
        }
        cout << "\n";
    }
    return 0;
}
 
// Sample Input
// Sample Output
// 4
// 0 0 0 1
// 1 0 0 1
// 1 1 0 0
// 0 0 1 0
// List 1 : 4
// List 2 : 1 4
// List 3 : 1 2
// List 4 : 3


// 5
// 0 0 0 0 0
// 1 0 0 1 1
// 1 1 0 1 1
// 1 1 1 0 0
// 0 0 1 0 0
// List 1 : 
// List 2 : 1 4 5
// List 3 : 1 2 4 5
// List 4 : 1 2 3
// List 5 : 3
