#include <bits/stdc++.h>

#define int long long
#define II pair<int, int>
#define fi first
#define se second
using namespace std;
const int maxn = 2e5 + 1, inf = 1e14 + 1;

struct nodes
{
    int pre = -inf, suf = -inf, sum = -inf, ans = -inf;
} ST[maxn * 4];
II a[maxn];
nodes merge(nodes a, nodes b)
{

    int pre = max({-inf, a.pre, a.sum + b.pre});
    int suf = max({-inf, b.suf, a.suf + b.sum});
    int sum = max(-inf, a.sum + b.sum);
    int ans = max({-inf, a.ans, b.ans, a.suf + b.pre});
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
II qu[maxn];
int ans[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#define TASK "VPMAXSUMSUB"
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i].fi, a[i].se = i;
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= q; i++)
        cin >> qu[i].fi, qu[i].se = i;
    sort(qu + 1, qu + 1 + q);
    int l = 1;
    for (int i = 1; i <= q; i++)
    {
        while (a[l].fi <= qu[i].fi)
        {
            update(1, 1, n, a[l].se, a[l].fi);
            l++;
        }
        int tmp = get(1, 1, n, 1, n).ans;
        ans[qu[i].se] = tmp;
    }
    for (int i = 1; i <= q; i++)
    {
        if (ans[i] != -inf)
            cout << ans[i] << '\n';
        else
            cout << "No Solution"
                 << '\n';
    }
}