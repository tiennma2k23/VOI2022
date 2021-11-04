#include <bits/stdc++.h>
#define int long long
#define II pair<int, int>
#define se second
#define fi first

using namespace std;
struct nodes
{
    int u, v, w, id;
};
const int maxn = 5e5 + 1, inf = 1e18 + 1;
nodes g[maxn];
int n, m;
namespace sub23
{
    int rt[maxn];
    bool cmp(nodes a, nodes b)
    {
        return a.w < b.w;
    }
    bool res[maxn];

    int get(int p)
    {
        if (rt[p] == p)
            return p;
        return rt[p] = get(rt[p]);
    }

    void join(int p, int q)
    {
        rt[get(p)] = get(q);
    }
    bool ok[maxn];
    void solve()
    {
        sort(g + 1, g + 1 + m, cmp);
        int minn = 0;
        for (int i = 1; i <= n; i++)
            rt[i] = i;
        for (int i = 1; i <= m; i++)
        {
            if (get(g[i].u) != get(g[i].v))
            {
                join(g[i].u, g[i].v);
                minn += g[i].w;
            }
        }
        for (int j = 1; j <= m; j++)
        {
            for (int i = 1; i <= n; i++)
                rt[i] = i;
            int p = g[j].id;
            int tmp = 0;
            for (int i = 1; i <= m; i++)
                if (g[i].id != p)
                {
                    if (get(g[i].u) != get(g[i].v))
                    {
                        join(g[i].u, g[i].v);
                        tmp += g[i].w;
                    }
                }
            if (tmp == minn)
                ok[p] = false;
            else
                ok[p] = true;
        }
        for (int i = 1; i <= m; i++)
        {
            if (ok[i])
                cout << "Yes ";
            else
                cout << "No ";
        }
    }
}
namespace sub5
{
    bool cmp(nodes a, nodes b)
    {
        return a.w < b.w;
    }
    int rt[maxn];
    bool res[maxn];

    int get(int p)
    {
        if (rt[p] == p)
            return p;
        return rt[p] = get(rt[p]);
    }

    void join(int p, int q)
    {
        rt[get(p)] = get(q);
    }
    void solve()
    {
        for (int i = 1; i <= n; ++i)
            rt[i] = i;
        sort(g + 1, g + 1 + m, cmp);
        for (int i = 1; i <= m; i++)
        {
            if (get(g[i].u) != get(g[i].v))
            {
                join(g[i].u, g[i].v);
                res[g[i].id] = 1;
            }
        }

        for (int i = 1; i <= m; i++)
            if (res[i])
                cout << "Yes ";
            else
                cout << "No ";
    }
}

namespace full
{
    vector<nodes> a;
    int time = 0;
    int rt[maxn], num[maxn], low[maxn], res[maxn];
    bool cmp(nodes a, nodes b)
    {
        return a.w < b.w;
    }
    int find(int u)
    {
        if (rt[u] == u)
            return u;
        return rt[u] = find(rt[u]);
    }

    bool join(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        rt[v] = u;
        return true;
    }
    vector<II> gr[maxn];
    void dfs(int u, int id)
    {
        num[u] = low[u] = ++time;
        for (auto e : gr[u])
        {
            int v = e.fi;
            int p = e.se;
            if (p == id)
                continue;
            if (num[v] == 0)
            {
                dfs(v, p);
                low[u] = min(low[u], low[v]);
                if (low[v] == num[v])
                {
                    res[p] = 1;
                }
            }
            else
            {
                low[u] = min(low[u], num[v]);
            }
        }
    }
    void solve()
    {
        if (a.empty())
            return;

        for (int i = 0; i < a.size(); i++)
        {
            a[i].u = find(a[i].u);
            a[i].v = find(a[i].v);
            gr[a[i].u].clear();
            gr[a[i].v].clear();
            num[a[i].u] = num[a[i].v] = 0;
        }

        for (auto e : a)
        {
            res[e.id] = 0;
            if (e.u == e.v)
                continue;
            gr[e.v].push_back(II(e.u, e.id));
            gr[e.u].push_back(II(e.v, e.id));
        }
        for (auto e : a)
            if (num[e.u] == 0)
                dfs(e.u, -1);
        for (auto e : a)
            join(e.u, e.v);
    }
    void main()
    {
        for (int i = 1; i <= n; i++)
            rt[i] = i;
        sort(g + 1, g + 1 + m, cmp);
        for (int i = 1; i <= m; i++)
        {
            if (!a.empty() && a.back().w == g[i].w)
            {
                a.push_back(g[i]);
            }
            else
            {
                solve();
                a.clear();
                a.push_back(g[i]);
            }
        }
        solve();
        for (int i = 1; i <= m; i++)
        {
            if (res[i])
                cout << "Yes"
                     << " ";
            else
                cout << "No"
                     << " ";
        }
    }
}
int32_t main()
{
    freopen("mst.inp", "r", stdin);
    freopen("mst.out", "w", stdout);
    int sbt;
    cin >> sbt;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld %lld %lld", &g[i].u, &g[i].v, &g[i].w);
        g[i].id = i;
    }
    if (sbt == 5)
        sub5::solve();
    else if (sbt <= 3)
        sub23::solve();
    else
        full::main();
}