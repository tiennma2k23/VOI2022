#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 1, inf = 1e9;
int a[maxn], b[maxn], cl[maxn];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], b[i] = a[i];
    int l = 1, r = inf, ans = 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        for (int i = n; i >= 3; i--)
        {
            if (a[i] + cl[i] >= mid)
            {
                int tmp = min(a[i], a[i] + cl[i] - mid);
                tmp /= 3;
                cl[i - 1] += tmp;
                cl[i - 2] += 2 * tmp;
            }
        }
        bool ok = true;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] + cl[i] < mid)
                ok = false;
            cl[i] = 0;
        }
        // if (i + 2 <= n)
        // {
        //     int tmp = (mid - a[i]) + (mid - a[i]) % 2;
        //     int tmp1 = min((tmp / 2) * 3, a[i + 2] - a[i + 2] % 3);
        //     a[i] += (tmp1 / 3) * 2;
        //     a[i + 1] += (tmp1 / 3);
        //     a[i + 2] -= tmp1;
        // }
        // if (a[i] >= mid)
        //     continue;
        // if (i >= 2)
        // {
        //     int tmp = mid - a[i];
        //     int tmp1 = min(tmp * 3, a[i + 1] - a[i + 1] % 3);
        //     a[i - 1] += (tmp1 / 3) * 2;
        //     a[i] += (tmp1 / 3);
        //     a[i + 1] -= tmp1;
        // }
        if (ok)
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    // bool ok = true;

    // for (int i = 1; i <= n; i++)
    //     if (a[i] < mid)
    //         ok = false;
    cout << ans << '\n';
}

int32_t main()
{
    int q;
    cin >> q;
    while (q--)
        solve();
}