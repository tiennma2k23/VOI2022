#include <bits/stdc++.h>
#pragma GCC optimize("Os")
#define ll long long
using namespace std;
const int maxn = 1e6 + 1;
int f[maxn], pre[maxn], v[maxn], last[maxn];
ll t[4 * maxn], d[4 * maxn];
int n;
int h;
void apply(int p, ll value)
{
    t[p] += value;
    if (p < n)
        d[p] += value;
}

void build(int p)
{
    while (p > 1)
    {
        p >>= 1;
        t[p] = max(t[p << 1], t[p << 1 | 1]) + d[p];
    }
}

void push(int p)
{
    for (int s = h; s > 0; --s)
    {
        int i = p >> s;
        if (d[i] != 0)
        {
            apply(i << 1, d[i]);
            apply(i << 1 | 1, d[i]);
            d[i] = 0;
        }
    }
}

void update(int l, int r, ll value)
{
    l += n, r += n;
    int l0 = l, r0 = r;
    for (; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            apply(l++, value);
        if (r & 1)
            apply(--r, value);
    }
    build(l0);
    build(r0 - 1);
}

ll get(int l, int r)
{
    l += n, r += n;
    push(l);
    push(r - 1);
    ll res = 0;
    for (; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res = max(res, t[l++]);
        if (r & 1)
            res = max(t[--r], res);
    }
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m;
    cin >> n >> m;
    h = sizeof(int) * 8 - __builtin_clz(n);
    for (int i = 1; i <= n; ++i)
        cin >> f[i];
    for (int i = 1; i <= m; ++i)
        cin >> v[i];
    // build(1, 1, n);
    for (int i = 1; i <= n; ++i)
    {
        last[i] = pre[f[i]];
        pre[f[i]] = i;
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        update(last[i], i, v[f[i]]);
        ans = max(ans, get(last[i], i));
        if (last[i] == 0)
            continue;
        update(last[last[i]], last[i], -v[f[i]]);
    }
    cout << ans;
}
