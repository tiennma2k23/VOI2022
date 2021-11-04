#include <bits/stdc++.h>
// #define fi first
// #define se second
// #define u fi.fi
// #define v fi.se
// #define w se.fi
// #define id se.se
// #define II pair<int, int>
// #define pp pair<II, II>
using namespace std;
struct nodes
{
    int u, v, w, id;
};
const int maxn = 5e5 + 1;
nodes g[maxn];
int rt[maxn], ans[maxn];
vector<int> st;
bool cmp(nodes a, nodes b)
{
    return a.w < b.w;
}

int find(int x)
{
    if (rt[x] == x)
        return x;
    else
        return (rt[x] = find(rt[x]));
}

void join(int _u, int _v)
{
    _u = find(_u);
    _v = find(_v);
    if (_u == _v)
        return;
    rt[_v] = _u;
}
bool ok(int x, int y)
{
    int _x = find(x);
    int _y = find(y);
    if (_x == _y)
        return false;
    return true;
}
int32_t main()
{
    // freopen("mst.inp", "r", stdin);
    // freopen("mst.out", "w", stdout);

    int sbt;
    scanf("%ld", &sbt);
    int n, m;
    scanf("%ld %ld", &n, &m);
    for (int i = 1; i <= n; i++)
        rt[i] = i;
    for (int i = 1; i <= m; i++)
    {
        scanf("%ld %ld %ld", &g[i].u, &g[i].v, &g[i].w);
        g[i].id = i;
    }
    sort(g + 1, g + 1 + m, cmp);
    for (int i = 1; i <= m; i++)
    {
        int j = i;
        while (g[j].w == g[j + 1].w)
        {
            if (ok(g[j].u, g[j].v))
            {
                ans[g[j].id] = 1;
            }
            j++;
        }
        if (ok(g[j].u, g[j].v))
        {
            ans[g[j].id] = 1;
        }
        for (int p = i; p <= j; p++)
        {
            if (ans[g[p].id])
                join(g[p].u, g[p].v);
        }
        i = j;
    }
    for (int i = 1; i <= m; i++)
    {
        if (ans[i])
            cout << "Yes"
                 << " ";
        else
            cout << "No"
                 << " ";
    }
}