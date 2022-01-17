#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 1, inf = 1e18;
int f[maxn], vs[maxn];
int n, m, a[maxn];
int calc(int x)
{
    if (x > n)
        return 0;
    if (!vs[x])
    {
        vs[x] = true;
        f[x] = inf;
        int maxx = -inf;
        int sum = 0;
        for (int i = x; i <= n; i++)
        {
            sum += a[i];
            if (sum > m)
                break;
            maxx = max(maxx, a[i]);
            f[x] = min(f[x], maxx + calc(i + 1));
        }
    }
    return f[x];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > m)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << calc(1) << endl;
}