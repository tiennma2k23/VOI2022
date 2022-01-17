#include <bits/stdc++.h>
#define int long long
#define vsize(a) (int)(a.size())
using namespace std;
const int maxn = 1e5 + 1, inf = 2e9 + 1;
struct nodes
{
    int u, v, w;
};
int n, m, s, t;
vector<nodes> vec[4];

bool cmp(nodes a, nodes b)
{
    return a.w < b.w;
}

struct Node
{
    int v, w, type;
};
vector<Node> gr[maxn];
namespace sub1
{
    int par[maxn];
    int root(int u)
    {
        if (!par[u])
            return u;
        return par[u] = root(par[u]);
    }

    bool join(int u, int v)
    {
        u = root(u);
        v = root(v);
        if (u == v)
            return false;
        par[v] = u;
        return true;
    }

    void solve()
    {
        sort(vec[1].begin(), vec[1].end(), cmp);
        for (auto p : vec[1])
            if (join(p.u, p.v))
            {
                if (root(s) == root(t))
                {
                    cout << p.w << endl;
                    return;
                }
            }
    }
}

namespace sub2
{

    struct Edge
    {
        int v, w, c;
    };
    vector<Edge> ed[maxn];
    bool vs[maxn];
    int ans, maxx[4];
    void init()
    {
        ans = inf;
        sort(vec[1].begin(), vec[1].end(), cmp);
        sort(vec[2].begin(), vec[2].end(), cmp);

        for (auto p : vec[1])
        {
            ed[p.u].push_back({p.v, p.w, 1});
            ed[p.v].push_back({p.u, p.w, 1});
        }

        for (auto p : vec[2])
        {
            ed[p.u].push_back({p.v, p.w, 2});
            ed[p.v].push_back({p.u, p.w, 2});
        }
    }

    bool dfs(int u)
    {
        vs[u] = true;
        if (u == t)
            return true;
        for (auto p : ed[u])
            if (!vs[p.v] && p.w <= maxx[p.c])
                if (dfs(p.v))
                    return true;
        return false;
    }

    void solve()
    {
        init();
        int j = -1;
        for (int i = vec[1].size() - 1; i >= 0; i--)
        {
            for (int u = 1; u <= n; u++)
                vs[u] = false;
            maxx[1] = vec[1][i].w;
            while (j < (int)vec[2].size() && !dfs(s))
            {
                j++;
                if (j == vec[2].size())
                {
                    cout << ans << endl;
                    return;
                }
                maxx[2] = vec[2][j].w;
                for (int u = 1; u <= n; u++)
                    vs[u] = false;
            }
            ans = min(ans, maxx[1] + maxx[2]);
        }
        cout << ans << endl;
    }

}

namespace sub3
{
#define II pair<int, int>
#define fi first
#define se second
    void dijsktra(int s, int *d)
    {
        for (int i = 1; i <= n; i++)
            d[i] = inf;
        priority_queue<II, vector<II>, greater<II>> pq;
        d[s] = 0;
        pq.push({0, s});
        while (pq.size())
        {
            II top = pq.top();
            pq.pop();
            int u = top.se;
            int du = top.fi;
            if (du != d[u])
                continue;
            for (auto p : gr[u])
            {
                if (p.type == 2)
                    continue;
                int v = p.v;
                int uv = p.w;
                if (d[v] > max(d[u], uv))
                {
                    d[v] = max(d[u], uv);
                    pq.push({d[v], v});
                }
            }
        }
    }
    int ds[maxn], dt[maxn];
    void solve()
    {
        dijsktra(s, ds);
        dijsktra(t, dt);
        int ans = ds[t];
        for (auto p : vec[2])
        {
            int u = p.u;
            int v = p.v;
            int w = p.w;
            ans = min(ans, max(ds[u], dt[v]) + w);
            ans = min(ans, max(ds[v], dt[u]) + w);
        }
        cout << ans << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int cnta = 0;
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int c, u, v, w;
        cin >> c >> u >> v >> w;
        vec[c].push_back({u, v, w});
        if (c == 1)
        {
            cnta++;
        }
        gr[u].push_back({v, w, c});
        gr[v].push_back({u, w, c});
    }
    // sub4::solve();
    if (cnta == m)
        sub1::solve();
    else if (m <= 5000 && n <= 5000)
        sub2::solve();
    else
        sub3::solve();
} // namespace std;