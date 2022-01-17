#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 1;
int vis[maxn], depth[maxn], dfn[maxn], low[maxn], id[maxn], w[maxn], sz[maxn], ans, num, cnt;
vector<int> gr[maxn], T[maxn];
stack<int> s;
int n, m;
void tarjan(int x, int par)
{
    dfn[x] = low[x] = ++num;
    s.push(x);
    for (auto y : gr[x])
    {
        if (y == par)
            continue;
        if (!dfn[y])
        {
            tarjan(y, x);
            low[x] = min(low[x], low[y]);
        }
        else
            low[x] = min(low[x], dfn[y]);
    }
    if (dfn[x] == low[x])
    {
        int y;
        ++cnt;
        do
        {
            y = s.top();
            s.pop();
            id[y] = cnt;
            ++w[cnt];
        } while (x != y);
    }
}
void dfs(int x, int par)
{
    sz[x] = w[x], depth[x] = w[x] * w[x];
    for (int y : T[x])
    {
        if (y == par)
            continue;
        dfs(y, x);
        sz[x] += sz[y];
        depth[x] += depth[y] + sz[y] * w[x];
    }
}

void solve(int x)
{
    memset(vis, 0, sizeof(vis));
    vis[0] = 1;
    int all = 0;
    long long tmp = w[x] * w[x], res = 0;
    for (int y : T[x])
    {
        dfs(y, x);
        tmp += depth[y] + sz[y] * w[x];
        for (int i = all; ~i; --i)
            if (vis[i])
                vis[i + sz[y]] = 1;
        all += sz[y];
    }
    for (int i = 0; i <= all; ++i)
        if (vis[i])
            res = max(res, i * (n - w[x] - i) + tmp);
    ans = max(ans, res);
}

int32_t main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    } 
    tarjan(1, 0);
    for (int x = 1; x <= n; ++x)
        for (int y : gr[x])
            if (id[x] != id[y])
                T[id[x]].push_back(id[y]);
    for (int i = 1; i <= n; i++)
        solve(i);
    cout << ans << endl;
}