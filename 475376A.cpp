#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e4 + 1, inf = 1e9 + 1;

struct nodes
{
    int pre, suf, sum, ans;
} ST[maxn * 4];

nodes merge(nodes a, nodes b)
{

    int pre = max(a.pre, a.sum + b.pre);
    int suf = max(b.suf, a.suf + b.sum);
    int sum = a.sum + b.sum;
    int ans = max({a.ans, b.ans, a.suf + b.pre});
    return {pre, suf, sum, ans};
}

void update(int id, int l, int r, int i, int v)
{
    if (i < l || r < i)
    {
        return;
    }
    if (l == r)
    {
        ST[id] = {v, v, v, v};
        return;
    }

    int mid = (l + r) / 2;
    update(id * 2, l, mid, i, v);
    update(id * 2 + 1, mid + 1, r, i, v);

    ST[id] = merge(ST[id * 2], ST[id * 2 + 1]);
}

nodes get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return {-inf, -inf, -inf, -inf};
    }
    if (u <= l && r <= v)
    {
        return ST[id];
    }
    int mid = (l + r) / 2;
    return merge(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen("475376A.inp", "r", stdin);
    // freopen("475376A.out", "w", stdout);
    int n, q;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        update(1, 1, n, i, a);
    }
    cin >> q;
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
            int u, v;
            cin >> u >> v;
            cout << get(1, 1, n, u, v).ans << '\n';
        }
    }
}