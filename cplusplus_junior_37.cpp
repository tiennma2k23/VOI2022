#include <bits/stdc++.h>
#define int long long
using namespace std;
int calc(int x, int p, int n)
{
    int res = 1;
    for (int i = 1; i <= p; i++)
    {
        res *= x;
        if (res > n)
            break;
    }
    return res;
}
bool ok(int x, int p, int n)
{
    if (calc(x, p, n) <= n)
        return true;
    return false;
}
int32_t main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int x, ans = 1;
        cin >> x;
        for (int p = 1; p <= 32; p++)
        {
            int l = 1, r = x, res = 0;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (ok(mid, p, x))
                    l = mid + 1, res = mid;
                else
                    r = mid - 1;
            }
            if (calc(res, p, x) == x)
                ans = p;
        }
        cout << ans << endl;
    }
}