#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 1, inf = 1e9 + 1;

int ST[maxn * 4];
void update(int id, int l, int r, int i, int v)
{
    if (i < l || r < i)
    {
        return;
    }
    if (l == r)
    {
        ST[id] = v;
        return;
    }

    int mid = (l + r) / 2;
    update(id * 2, l, mid, i, v);
    update(id * 2 + 1, mid + 1, r, i, v);

    ST[id] = (ST[id * 2] + ST[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return 0;
    }
    if (u <= l && r <= v)
    {
        return ST[id];
    }
    int mid = (l + r) / 2;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}
int32_t main()
{
    int n, q;
    cin >> n >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 0)
        {
            int u, v;
            cin >> u >> v;
            update(1, 1, n, u, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << get(1, 1, n, l, r) << endl;
        }
    }
}