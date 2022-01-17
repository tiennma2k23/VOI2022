#include <bits/stdc++.h>
#define int long long
#define II pair<int, int>
#define fi first
#define se second
using namespace std;
const int maxn = 1e5 + 1;
int Time = 0;
int in[maxn], out[maxn], depth[maxn], up[maxn][25];
vector<int> gr[maxn];
vector<II> child[maxn];
void dfs(int u, int p)
{
    in[u] = ++Time;
    depth[u] = depth[p] + 1;
    up[u][0] = p;
    for (int i = 1; i <= 20; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (auto v : gr[u])
    {
        if (v == p)
            continue;
        dfs(v, u);
    }
    out[u] = Time;
}
int lca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);
    for (int i = 20; i >= 0; i--)
    {
        if (depth[up[u][i]] >= depth[v])
            u = up[u][i];
    }
    if (u == v)
        return u;
    for (int i = 20; i >= 0; i--)
    {
        if (up[u][i] != up[v][i])
            u = up[u][i], v = up[v][i];
    }
    return up[u][0];
}
bool cmp(int u, int v)
{
    return in[u] > in[v];
}

int fen[maxn];
void update(int p, int val)
{
    while (p < maxn)
    {
        fen[p] += val;
        p += (p & (-p));
    }
}
int get(int p)
{
    int res = 0;
    while (p > 0)
    {
        res += fen[p];
        p -= (p & (-p));
    }
    return res;
}

int32_t main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    dfs(1, 0);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        child[lca(u, v)].push_back({u, v});
    }

    vector<int> vec;
    for (int i = 1; i <= n; i++)
        vec.push_back(i);
    sort(vec.begin(), vec.end(), cmp);

    vector<int> ans;
    for (auto val : vec)
    {
        bool ok = true; // gsu tất cả mọi con của nó đều đã đi qua ít nhất 1 đỉnh
        for (auto p : child[val])
        {
            int u = p.fi, v = p.se;
            int cnt = get(in[u]) + get(in[v]) - 2 * get(in[val]);
            if (cnt == 0)
                ok = false;
            // cout << cnt << endl;
        }
        if (!ok)
        {
            update(in[val], 1);
            update(out[val] + 1, -1);
            ans.push_back(val);
        }
    }

    cout << ans.size() << endl;
    for (auto val : ans)
        cout << val << ' ';
}