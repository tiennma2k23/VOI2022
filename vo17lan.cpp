#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
const int maxn = 5e4 + 1, inf = 1e9 + 1;
int a[maxn], v[maxn];
void sub1()
{
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int sz = 1 << n;
    int ans = 0;
    for (int mask = 0; mask < sz; mask++)
    {
        int gcd1 = 0, gcd2 = 0;
        for (int i = 0; i < n; i++)
        {
            if ((mask >> i) & 1)
                gcd1 = __gcd(a[i], gcd1);
            else
                gcd2 = __gcd(gcd2, a[i]);
        }
        if (gcd1 == 0)
            ans = max(ans, gcd2);
        else if (gcd2 == 0)
            ans = max(ans, gcd1);
        else
            ans = max(ans, min(gcd1, gcd2));
    }
    cout << ans << '\n';
}
void sub2()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    for (int j = 1; j <= 270; j++)
    {
        int gcd1 = 0, gcd2 = 0;
        for (int i = 1; i <= n; i++)
            v[i] = (a[i] % j == 0);
        for (int i = 1; i <= n; i++)
        {
            if (v[i])
                gcd1 = __gcd(a[i], gcd1);
            else
                gcd2 = __gcd(gcd2, a[i]);
        }
        if (gcd1 == 0)
            ans = max(ans, gcd2);
        else if (gcd2 == 0)
            ans = max(ans, gcd1);
        else
            ans = max(ans, min(gcd1, gcd2));
    }
    cout << ans << '\n';
}
int calc(int y)
{
    int res = 0, x = y;
    vector<int> vv;
    vv.clear();
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
            vv.push_back(x / i), vv.push_back(i);
    }
    for (auto val : vv)
    {
        int gcd1 = 0, gcd2 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] % val == 0)
                gcd1 = __gcd(gcd1, a[i]);
            else
                gcd2 = __gcd(a[i], gcd2);
        }
        if (gcd1 == 0)
            res = max(res, gcd2);
        else if (gcd2 == 0)
            res = max(res, gcd1);
        else
            res = max(res, min(gcd1, gcd2));
    }
    return res;
}
void sub3()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int res = a[1];
    int ans = max(1ll, calc(res));
    cout << ans << '\n';
}
void solve()
{

    cin >> n;
    // if (n <= 20)
    //     sub1();
    // else if (n <= 100)
    //     sub2();
    // else
    sub3();
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int q;
    cin >> q;
    while (q--)
        solve();
}