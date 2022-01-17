#include <bits/stdc++.h>
#pragma GCC optimize("Os")
//#define int long long
using namespace std;
const int maxn = 2e5 + 1, inf = 1e9 + 1;
multiset<int> st[4 * maxn];
int a[maxn];
void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id].insert(a[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = st[id * 2];
    for (int it : st[id * 2 + 1])
        st[id].insert(it);
}
void update(int id, int l, int r, int p, int k)
{
    if (st[id].find(a[p]) != st[id].end())
        st[id].erase(st[id].find(a[p]));
    st[id].insert(k);
    if (l == r)
        return;
    int mid = (l + r) / 2;
    if (p <= mid)
        update(id * 2, l, mid, p, k);
    else
        update(id * 2 + 1, mid + 1, r, p, k);
}
int get(int id, int l, int r, int u, int v, int k)
{
    if (v < l || r < u)
    {
        return inf;
    }
    if (u <= l && r <= v)
    {
        auto it = st[id].lower_bound(k);
        if (it != st[id].end())
        {
            int val = *it;
            return val;
        }
        else
            return inf;
    }
    int mid = (l + r) / 2;
    return min(get(id * 2, l, mid, u, v, k), get(id * 2 + 1, mid + 1, r, u, v, k));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        // update(1, 1, n, i, a[i]);
    }
    build(1, 1, n);
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int i, v;
            cin >> i >> v;
            update(1, 1, n, i, v);
            a[i] = v;
        }
        else if (type == 2)
        {
            int l, r, k;
            cin >> l >> r >> k;
            if (get(1, 1, n, l, r, k) != inf)
                cout << get(1, 1, n, l, r, k) << '\n';
            else
                cout << -1 << '\n';
        }
    }
}