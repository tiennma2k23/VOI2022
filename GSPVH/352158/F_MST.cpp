#include <bits/stdc++.h>
#define int long long
#define II pair<int, int>
#define IIi pair<II, int>
#define fi first
#define se second
using namespace std;
const int maxn = 4010, inf = 1e18;
namespace sub12
{
    struct nodes
    {
        int u, v, w, id;
    };
    nodes g[maxn];
    bool cmp(nodes a, nodes b) { return a.w < b.w; }
    set<int> st;
    int rt[maxn], ans[maxn];
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
    void solve()
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            cin >> g[i].u >> g[i].v >> g[i].w;
            g[i].id = i;
            st.insert(g[i].w - 1);
        }
        sort(g + 1, g + 1 + m, cmp);
        st.insert(inf);

        for (int i = 1; i <= m; i++)
        {
            //tmp = g[i].w;
            int res = -1;
            for (auto val : st)
            {
                for (int j = 1; j <= n; j++)
                    rt[j] = j;
                for (int j = 1; j <= m; j++)
                    if (i != j)
                    {
                        if (g[j].w <= val)
                        {
                            join(g[j].u, g[j].v);
                        }
                        else
                            break;
                    }
                if (join(g[i].u, g[i].v))
                    res = max(res, val);
            }
            if (res == inf)
                ans[g[i].id] = -1;
            else
                ans[g[i].id] = res;
        }
        for (int i = 1; i <= m; i++)
            cout << ans[i] << " ";
    }

}

namespace sub3
{
    struct nodes
    {
        int u, v, w, id;
    };
    nodes g[maxn];
    bool cmp(nodes a, nodes b) { return a.w < b.w; }
    set<int> st;
    int rt[maxn], ans[maxn];
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
    bool ok(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        return true;
    }
    void solve()
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            cin >> g[i].u >> g[i].v >> g[i].w;
            g[i].id = i;
            st.insert(g[i].w - 1);
        }
        sort(g + 1, g + 1 + m, cmp);
        st.insert(inf);
        vector<nodes> a;
        for (int i = 1; i <= m; i++)
        {
            a.clear();
            int res = -1;
            for (int j = 1; j <= n; j++)
                rt[j] = j;
            for (int j = 1; j <= m; j++)
                if (i != j)
                {
                    if (!a.empty() && a.back().w == g[j].w)
                    {
                        a.push_back(g[j]);
                    }
                    else
                    {
                        if (!a.empty())
                        {
                            for (auto k : a)
                                join(k.u, k.v);
                            if (!ok(g[i].u, g[i].v))
                            {
                                res = a.back().w - 1;
                                break;
                            }
                        }
                        a.clear();
                        a.push_back(g[j]);
                    }
                }
            for (auto k : a)
                join(k.u, k.v);
            if (!ok(g[i].u, g[i].v))
            {
                res = a.back().w - 1;
            }
            ans[g[i].id] = res;
        }
        for (int i = 1; i <= m; i++)
            cout << ans[i] << " ";
    }
}
namespace sub4
{
    struct nodes
    {
        int u, v, w, id;
    };
    nodes g[maxn];
    bool cmp(nodes a, nodes b) { return a.w < b.w; }
    set<int> st;
    int rt[maxn];
    int find(int u)
    {
        if (rt[u] == u)
            return u;
        return rt[u] = find(rt[u]);
    }
    vector<IIi> gr[maxn];
    bool join(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        rt[v] = u;
        return true;
    }
    bool ok(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        return true;
    }
    struct _data
    {
        int p, id, maxx;
    };
    _data up[maxn][20];
    int depth[maxn];
    vector<IIi> re;
    void dfs(int u, int id, int par, int to)
    {
        depth[u] = depth[par] + 1;
        up[u][0].p = par;
        up[u][0].id = id;
        up[u][0].maxx = to;
        for (int i = 1; i <= 18; i++)
        {
            up[u][i].p = up[up[u][i - 1].p][i - 1].p;
            up[u][i].maxx = max(up[up[u][i - 1].p][i - 1].maxx, up[u][i - 1].maxx);
        }
        for (auto val : gr[u])
            if (val.fi.fi != par)
                dfs(val.fi.fi, val.fi.se, u, val.se);
    }
    int ans[maxn];
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

    bool ck[maxn];
    void solve()
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            cin >> g[i].u >> g[i].v >> g[i].w;
            g[i].id = i;
        }
        vector<nodes> v;
        v.clear();
        for (int i = 1; i <= m; i++)
        {
            if (!ok(g[i].u, g[i].v))
            {
                v.push_back(g[i]);
                ck[i] = true;
                join(g[i].u, g[i].v);
            }
        }
        for (auto k : v)
            gr[k.u].push_back(IIi(II(k.v, k.id), k.w)), gr[k.v].push_back(IIi(II(k.u, k.id), k.w));
        dfs(v[0].u, v[0].id, 0, 0);
        int _u, _v, pos;
        for (int i = 1; i <= m; i++)
            if (!ck[i])
                _u = g[i].u, _v = g[i].v, pos = i;
        int pa = lca(_u, _v);
        re.clear();
        re.push_back(IIi(II(_u, pos), _v));
        int max1 = -1, max2 = -1;
        while (_u != pa)
        {
            if (max1 <= up[_u][0].maxx)
                max2 = max1, max1 = up[_u][0].maxx;
            else
                max2 = max(max2, up[_u][0].maxx);
            re.push_back(IIi(II(_u, up[_u][0].id), up[_u][0].p));
            _u = up[_u][0].p;
        }
        _u = _v;
        while (_u != pa)
        {
            if (max1 <= up[_u][0].maxx)
                max2 = max1, max1 = up[_u][0].maxx;
            else
                max2 = max(max2, up[_u][0].maxx);
            re.push_back(IIi(II(_u, up[_u][0].id), up[_u][0].p));
            _u = up[_u][0].p;
        }
        for (int i = 1; i <= m; i++)
            ans[i] = -1;
        for (auto val : re)
        {
            if (g[val.fi.se].w != max1)
                ans[val.fi.se] = max1 - 1;
            else
                ans[val.fi.se] = max2 - 1;
        }
        for (int i = 1; i <= m; i++)
            cout << ans[i] << " ";
    }
}
int32_t main()
{
    //freopen("mst.inp", "r", stdin);
    //freopen("mst.out", "w", stdout);
    int sbt;
    cin >> sbt;
    // if (sbt <= 2)
    //     sub12::solve();
    // else if (sbt == 3)
    //     sub3::solve();
    sub4::solve();
    return 0;
}