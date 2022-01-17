#include <bits/stdc++.h>
#define endl '\n'
#define II pair<int, int>
#define fi first
#define se second
using namespace std;
const int maxn = 5e5 + 1;
struct nodes
{
    int u, v, w, id;
} edge[maxn];
int rt[maxn];
II a[maxn];
int n, m;
bool cmp(nodes a, nodes b)
{
    return a.w < b.w;
}

int root(int u)
{
    if (u == rt[u])
        return u;
    return rt[u] = root(rt[u]);
}

bool join(int u, int v)
{
    u = root(u), v = root(v);
    if (u == v)
        return false;
    rt[u] = v;
    return true;
}

void reset()
{
    for (int i = 1; i <= n; i++)
        rt[i] = i;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge[i] = {u, v, w, i};
        a[i] = {u, v};
    }
    sort(edge + 1, edge + 1 + m, cmp);
    reset();
    int i = 1;
    while (i <= m)
    {
        int j = i;
        while (j <= m && edge[j].w == edge[i].w)
        {
            edge[j].u = root(edge[j].u);
            edge[j].v = root(edge[j].v);
            a[edge[j].id] = {edge[j].u, edge[j].v};
            j++;
        }
        while (i < j)
        {
            join(edge[i].u, edge[i].v);
            i++;
        }
    }
    reset();
    int q;
    cin >> q;
    while (q--)
    {
        vector<int> vec;
        bool ok = true;
        int k;
        cin >> k;
        while (k--)
        {
            int i;
            cin >> i;
            vec.push_back(i);
            if (!join(a[i].fi, a[i].se))
                ok = false;
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        for (auto val : vec)
            rt[a[val].fi] = a[val].fi, rt[a[val].se] = a[val].se;
        vec.clear();
    }
}