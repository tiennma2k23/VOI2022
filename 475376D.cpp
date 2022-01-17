#include <bits/stdc++.h>
#define int long long
#define II pair<int, int>
#define fi first
#define se second
using namespace std;
const int maxn = 3e5 + 5;
int depth[maxn];
vector<II> gr[maxn];
vector<II> child[maxn];
int dist[maxn], pre[maxn], up[maxn][25], res[maxn], n;
void dfs(int u, int p)
{
    depth[u] = 0;
    for (auto val : gr[u])
    {
        int v = val.fi, w = val.se;
        if (v == p)
            continue;
        child[u].push_back(II(v, w));
        dfs(v, u);
        depth[u] = max(depth[u], depth[v] + w);
    }
}
void dfs2(int u, int p, int maxx)
{
    dist[u] = max(maxx, depth[u]);

    auto &child_u = child[u];
    vector<int> pre(child_u.size() + 5, 0);
    int suf = 0;
    for (int i = 1; i <= (int)child_u.size(); i++)
    {
        int v = child_u[i - 1].fi, w = child_u[i - 1].se;

        pre[i] = pre[i - 1];
        if (v == p)
            continue;
        pre[i] = max(pre[i], depth[v] + w);
    }

    for (int i = (int)child_u.size(); i >= 1; i--)
    {
        int v = child_u[i - 1].fi, w = child_u[i - 1].se;
        if (v == p)
            continue;
        dfs2(v, u, max({maxx, suf, pre[i - 1]}) + w);
        suf = max(suf, depth[v] + w);
    }
}
II a[maxn];

void dfs3(int u, int p)
{
    up[u][0] = p;
    for (int i = 1; i <= 20; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (auto val : gr[u])
    {
        int v = val.fi;
        if (v == p)
            continue;
        dfs3(v, u);
    }
}
int ans = 0;
void calc(int u, int p)
{
    for (auto val : gr[u])
    {
        int v = val.fi;
        if (v == p)
            continue;
        calc(v, u);
        res[u] += res[v];
    }
    ans = max(ans, res[u]);
}

void solve()
{
    int l;
    cin >> l;
    for (int i = 1; i <= n; i++)
        res[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        int u = a[i].se;
        int par = u;
        for (int j = 20; j >= 0; j--)
        {
            if (up[par][j] == 0)
                continue;
            if (dist[u] - dist[up[par][j]] <= l)
                par = up[par][j];
        }
        res[u] += 1;
        res[up[par][0]] -= 1;
    }
    ans = 0;
    calc(a[1].se, 0);
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        gr[u].push_back({v, w});
        gr[v].push_back({u, w});
    }

    dfs(1, 0);
    dfs2(1, 0, 0);

    // for (int i = 1; i <= n; i++)
    // cout << dist[i] << ' ';
    for (int i = 1; i <= n; i++)
        a[i] = {dist[i], i};

    sort(a + 1, a + 1 + n);

    dfs3(a[1].se, 0);

    int q;
    cin >> q;
    while (q--)
        solve();
}