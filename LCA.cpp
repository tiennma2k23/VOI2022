#include <bits/stdc++.h>
#define int long long
#define II pair<int, int>
#define fi first
#define se second
using namespace std;
const int maxn = 2e5 + 1;
vector<II> gr[maxn];
int depth[maxn];
struct nodes
{
    int p, sum;
};
nodes up[maxn][20];
void dfs(int u, int par, int to)
{
    depth[u] = depth[par] + 1;
    up[u][0].p = par;
    up[u][0].sum = to;
    for (int i = 1; i <= 18; i++)
    {
        up[u][i].p = up[up[u][i - 1].p][i - 1].p;
        up[u][i].sum = up[up[u][i - 1].p][i - 1].sum + up[u][i - 1].sum;
    }
    for (auto v : gr[u])
        if (v.fi != par)
            dfs(v.fi, u, v.se);
}

int lca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);
    for (int i = 18; i >= 0; i--)
    {
        if (depth[up[u][i].p] >= depth[v])
            u = up[u][i].p;
    }
    if (u == v)
        return u;
    for (int i = 18; i >= 0; i--)
    {
        if (up[u][i].p != up[v][i].p)
            u = up[u][i].p, v = up[v][i].p;
    }
    return up[u][0].p;
}

int dist(int u, int v)
{
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

int32_t main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        gr[u].push_back(II(v, w));
        gr[v].push_back(II(u, w));
    }
    dfs(1, 0, 0);
    while (q--)
    {
        int u, v, ans = 0;
        cin >> u >> v;
        int par = lca(u, v);
        while (u != par)
        {
            int d = dist(u, par);
            int tmp = 1, cnt = 0;
            while (tmp * 2 <= d)
                tmp *= 2, cnt++;
            ans += up[u][cnt].sum;
            u = up[u][cnt].p;
        }
        u = v;
        while (u != par)
        {
            int d = dist(u, par);
            int tmp = 1, cnt = 0;
            while (tmp * 2 <= d)
                tmp *= 2, cnt++;
            ans += up[u][cnt].sum;
            u = up[u][cnt].p;
        }
        cout << ans << endl;
    }
}
