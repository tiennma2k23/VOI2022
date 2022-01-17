#include <bits/stdc++.h>
#define int long long
#define II pair<int, int>
#define fi first
#define se second
using namespace std;
const int maxn = 1e5 + 1;
vector<II> ans;
vector<int> gr[maxn + 5];
int dfn[maxn + 5], low[maxn + 5];
int vt;
void tarjan(int u, int par)
{
    dfn[u] = low[u] = ++vt;
    for (auto v : gr[u])
    {
        if (!dfn[v])
        {
            ans.push_back({u, v});
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (dfn[u] < low[v])
            {
                cout << 0 << endl;
                exit(0);
            }
        }
        else if (v != par)
        {
            low[u] = min(low[u], dfn[v]);
            if (dfn[v] < dfn[u])
                ans.push_back({u, v});
        }
    }
}
int32_t main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    tarjan(1, 0);
    for (auto val : ans)
        cout << val.fi << ' ' << val.se << endl;
}
