#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 1, mod = 1e9 + 7;
int a[maxn];
int32_t main()
{
    freopen("segtree_itmix.inp", "r", stdin);
    freopen("segtree_itmix.ans", "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    while (q--)
    {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1)
        {
            int x;
            cin >> x;
            for (int i = l; i <= r; i++)
                a[i] += x, a[i] %= mod;
        }
        else if (type == 2)
        {
            int x;
            cin >> x;
            for (int i = l; i <= r; i++)
                a[i] *= x, a[i] %= mod;
        }
        else if (type == 3)
        {
            int x;
            cin >> x;
            for (int i = l; i <= r; i++)
                a[i] = x, a[i] %= mod;
        }
        else
        {
            int ans = 0;
            for (int i = l; i <= r; i++)
                ans += a[i], ans %= mod;
            cout << ans << endl;
        }
    }
}