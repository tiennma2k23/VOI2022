#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 1, inf = 1e15;
int ST[4 * maxn], a[maxn], f[maxn];
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

    ST[id] = max(ST[id * 2], ST[id * 2 + 1]);
}
int get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return -INFINITY;
    }
    if (u <= l && r <= v)
    {
        return ST[id];
    }
    int mid = (l + r) / 2;
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
int32_t main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int pos = max(0ll, i - k);
        int res = get(1, 1, n, pos, i);
        f[i] = max(res + a[i], a[i]);
        update(1, 1, n, i, f[i]);
    }
    int ans = -inf;
    for (int i = 0; i <= n; i++)
        ans = max(ans, f[i]);
    cout << ans << endl;
}