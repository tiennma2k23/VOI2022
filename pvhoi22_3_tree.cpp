#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 1;
int depth[maxn], up[maxn][25];
vector<int> gr[maxn];
int n;
void dfs(int u, int par)
{
    depth[u] = depth[par] + 1;
    up[u][0] = par;
    for (int i = 1; i <= 20; i++)
    {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    for (auto v : gr[u])
        if (v != par)
            dfs(v, u);
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

int dist(int u, int v)
{
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}
set<int> st[1000006];
int q;
bool ok(int i, int j)
{
    set<int> ss;
    for (auto val : st[i])
        ss.insert(val);
    for (auto val : st[j])
        ss.insert(val);
    if ((ss.size() != max(st[i].size(), st[j].size())) && (ss.size() != st[i].size() + st[j].size()))
        return false;
    return true;
}

void solve()
{
    for (int i = 1; i <= q; i++)
        for (int j = i + 1; j <= q; j++)
        {
            if (!ok(i, j))
            {
                cout << "MAP MO" << '\n';
                return;
            }
        }
    cout << "RO RANG" << '\n';
}
int in[maxn];
int ti;
void dfs1(int u, int p)
{
    in[u] = ++ti;
    for (auto v : gr[u])
    {
        if (v != p)
            dfs1(v, u);
    }
}
struct Node
{
    int lazy = -1;
    int val;
} nodes[maxn * 4];
void down(int id, int l, int r)
{
    int t = nodes[id].lazy;
    if (t == -1)
        return;
    int mid = (l + r) / 2;
    nodes[id * 2].lazy = t;
    nodes[id * 2].val = t * (mid - l + 1);

    nodes[id * 2 + 1].lazy = t;
    nodes[id * 2 + 1].val = t * (r - mid);

    nodes[id].lazy = -1;
}
void update(int id, int l, int r, int u, int v, int val)
{
    if (v < l || r < u)
    {
        return;
    }
    if (u <= l && r <= v)
    {
        nodes[id].val = val * (r - l + 1);
        nodes[id].lazy = val;
        return;
    }
    int mid = (l + r) / 2;

    down(id, l, r);

    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);

    nodes[id].val = (nodes[id * 2].val + nodes[id * 2 + 1].val);
}
int get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return 0;
    }
    if (u <= l && r <= v)
    {
        return nodes[id].val;
    }
    int mid = (l + r) / 2;
    down(id, l, r);

    return (get(id * 2, l, mid, u, v) +
            get(id * 2 + 1, mid + 1, r, u, v));
}
int x[1000006], y[1000006];
void solve2()
{
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> x[i] >> y[i];
        update(1, 1, n, x[i], y[i], 0);
    }
    for (int i = 1; i <= q; i++)
    {
        int u, v;
        // cin >> u >> v;
        u = x[i], v = y[i];
        if (in[u] > in[v])
            swap(u, v);
        int tmp = get(1, 1, n, in[u], in[v]);
        if (tmp != 0 && tmp < (in[v] - in[u] + 1))
        {
            cout << "MAP MO" << '\n';
            return;
        }
        update(1, 1, n, in[u], in[v], 1);
    }
    cout << "RO RANG" << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int stb;
    cin >> stb;
    if (stb == 1 || stb == 2)
    {
        cin >> n;
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        dfs(1, 0);
        int t;
        cin >> t;
        while (t--)
        {
            cin >> q;
            for (int i = 1; i <= q; i++)
            {
                int u, v;
                cin >> u >> v;
                int p = lca(u, v);
                while (u != p)
                {
                    st[i].insert(u);
                    u = up[u][0];
                }
                while (v != p)
                {
                    st[i].insert(v);
                    v = up[v][0];
                }
                st[i].insert(p);
            }
            solve();
            for (int i = 1; i <= q; i++)
                st[i].clear();
        }
    }
    else
    {
        cin >> n;
        for (int i = 1; i < n; i--)
        {
            int u, v;
            cin >> u >> v;
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        int str;
        for (int i = 1; i <= n; i++)
            if (gr[i].size() == 1)
                str = i;
        dfs1(str, 0);
        int t;
        cin >> t;
        while (t--)
        {
            solve2();
        }
    }
}