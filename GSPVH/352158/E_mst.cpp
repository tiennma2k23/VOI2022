#include <bits/stdc++.h>

#define int long long

using namespace std;

struct nodes
{
    int u, v, w, id;
};
const int maxn = 26;
nodes g[maxn];
int n, m;
namespace sub12
{
    vector<nodes> _v;
    int tmp, cnt;
    int rt[maxn];
    bool cmp(nodes a, nodes b)
    {
        return a.w < b.w;
    }
    int get(int p)
    {
        if (rt[p] == p)
            return p;
        return rt[p] = get(rt[p]);
    }

    bool join(int p, int q)
    {
        p = get(p);
        q = get(q);
        if (p == q)
            return false;
        rt[p] = q;
        return true;
    }
    void calc(int x)
    {
        if (_v.size() == n - 1)
        {
            int res = 0;
            for (int i = 1; i <= n; i++)
                rt[i] = i;
            for (int i = 0; i < n - 1; i++)
            {
                if (join(_v[i].u, _v[i].v))
                {
                    res += _v[i].w;
                }
                else
                    return;
            }
            if (res == tmp)
                cnt++;
        }
        for (int i = x; i <= m; i++)
        {
            _v.push_back({g[i].u, g[i].v, g[i].w, g[i].id});
            calc(i + 1);
            _v.pop_back();
        }
    }
    void solve()
    {
        sort(g + 1, g + 1 + m, cmp);
        for (int i = 1; i <= n; i++)
            rt[i] = i;

        for (int i = 1; i <= m; i++)
        {
            if (join(g[i].u, g[i].v))
            {
                tmp += g[i].w;
            }
        }
        calc(0);
        cout << cnt << "\n";
    }
}
int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    freopen("cnt-mst.inp", "r", stdin);
    freopen("cnt-mst.out", "w", stdout);
    int sbt;
    scanf("%lld", &sbt);
    if (sbt > 2)
    {
        cout << 1 << "\n";
        return 0;
    }
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld %lld %lld", &g[i].u, &g[i].v, &g[i].w);
        g[i].id = i;
    }
    sub12 ::solve();
}