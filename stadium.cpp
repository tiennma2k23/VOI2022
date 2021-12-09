#include <bits/stdc++.h>
#define int long long
#define II pair<int, int>
#define se second
#define fi first
using namespace std;
const int maxn = 2e5 + 1, inf = 1e18;
II p[maxn];
map<II, int> ts;
int c[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen("input", "r", stdin);
    // freopen("output", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        p[i] = II(y, x);
        ts[p[i]] = max(ts[p[i]], z);
    }
    sort(p + 1, p + 1 + n);
    c[1] = ts[p[1]];
    for (int i = 2; i <= n; i++)
    {
        int key = p[i].se;
        int pos = upper_bound(p + 1, p + 1 + n, II(key, inf)) - p - 1;
        int m = c[i - 1];
        if (pos >= 1)
            m = max(m, c[pos] + ts[p[i]]);
        else
            m = max(m, ts[p[i]]);
        c[i] = m;
    }
    cout << c[n] << endl;
}