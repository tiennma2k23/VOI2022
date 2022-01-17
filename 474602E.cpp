#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 1, inf = 2e18;
int f[3][1 << 20];
struct nodes
{
    int x, k, mask;
} a[maxn];
bool cmp(nodes a, nodes b)
{
    return a.k < b.k;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, b;
    cin >> n >> m >> b;
    for (int i = 1; i <= n; i++)
    {
        int m1;
        cin >> a[i].x >> a[i].k >> m1;
        while (m1--)
        {
            int u;
            cin >> u;
            u--;
            a[i].mask |= (1 << u);
        }
    }
    sort(a + 1, a + 1 + n, cmp);
    int sz = 1 << m;
    for (int i = 0; i <= n; i++)
        for (int mask = 0; mask < sz; mask++)
            f[i % 2][mask] = inf;
    f[0][0] = 0;
    int ans = inf;
    for (int i = 1; i <= n; i++)
    {
        for (int mask = 0; mask < sz; mask++)
        {
            f[i % 2][mask] = min(f[i % 2][mask], f[(i - 1) % 2][mask]);
            f[i % 2][mask | a[i].mask] = min(f[i % 2][mask | a[i].mask], f[(i - 1) % 2][mask] + a[i].x);
        }
        ans = min(ans, f[i % 2][sz - 1] + a[i].k * b);
    }

    if (ans == inf)
        cout << -1 << endl;
    else
        cout << ans << endl;
}