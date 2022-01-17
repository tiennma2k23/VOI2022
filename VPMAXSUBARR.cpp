#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 1, inf = 1e15;
int st[4 * maxn];
int sum[maxn];
void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id] = sum[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    st[id] = min(st[id * 2], st[id * 2 + 1]);
}
int get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return inf;
    }
    if (u <= l && r <= v)
    {
        return st[id];
    }
    int mid = (l + r) / 2;
    return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#define TASK "VPMAXSUBARR"
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        sum[i] = sum[i - 1] + a;
    }
    build(1, 1, n);
    int ans = -inf;
    for (int i = 1; i <= n; i++)
    {
        if (i >= x && i <= y)
            ans = max(ans, sum[i]);
        int l = max(0ll, i - y);
        int r = max(0ll, i - x);
        int tmp = get(1, 1, n, l, r);
        ans = max(ans, sum[i] - tmp);
    }
    cout << ans << endl;
}