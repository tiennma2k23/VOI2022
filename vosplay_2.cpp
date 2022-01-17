#include <bits/stdc++.h>
using namespace std;

int root(int u)
{
    if (u == rt[u])
        return u;
    return rt[u] = root(rt[u]);
}

void join(int u, int v, int pos)
{
    u = root(u), v = root(v);
    if (u == v)
        return;
    if (st[u].size() > st[v].size())
    {
        swap(u, v);
    }
}

int32_t main(int argc, char const *argv[])
{
    /* code */
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        rt[i] = i;
        st[i].insert(II(x, 1));
    }
    for (int i = 1; i <= q; i++)
    {
        int u, v;
        cin >> u >> v;
        join(u, v, i);
    }
}
