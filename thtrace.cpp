#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    int n, m, k;
    cin >> n >> m >> q;
    for (int i = 1; i <= q; i++)
        cin >> query[i].tho >> query[i].soi;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
}