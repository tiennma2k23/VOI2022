#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 1;
int rt[maxn];
int root(int u)
{
    if (u == rt[u])
        return u;
    return rt[u] = root(rt[u]);
}

void join(int u, int v)
{
    u = root(u), v = root(v);
    if (u == v)
        return;
    rt[u] = v;
}

int32_t main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        rt[i] = i;
    while (q--)
    {
        int type, u, v;
        cin >> type >> u >> v;
        u++, v++;
        if (type == 0)
        {
            join(u, v);
        }
        else
        {
            u = root(u), v = root(v);
            if (u == v)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
    }
}