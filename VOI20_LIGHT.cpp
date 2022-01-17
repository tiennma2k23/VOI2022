#include <bits/stdc++.h>
using namespace std;
int dem[30], a[30];
int n, k;
bool ok(int x)
{
    int cnt = n;
    for (int i = 0; i < 26; i++)
        a[i] = dem[i];
    if (x * k > n)
        return false;
    int pos = 0;
    for (int i = 1; i <= k; i++)
    {
        int tmp = x;
        while (tmp > x % 2)
        {
            while (pos < 26)
            {
                int xx = min(tmp, a[pos]);
                xx -= xx % 2;
                tmp -= xx;
                a[pos] -= xx;
                cnt -= xx;
                if (a[pos] < 2)
                    pos++;
                if (tmp <= x % 2)
                    break;
            }
            if (pos == 26)
                break;
        }
        if (tmp > x % 2)
            return false;
    }
    if (cnt >= k * (x % 2))
        return true;
    return false;
}
void solve()
{
    for (int i = 0; i < 26; i++)
        dem[i] = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        dem[ch - 'a']++;
    }
    int l = 1, r = n, ans;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (ok(mid))
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    cout << ans << endl;
}
int32_t main()
{
    int q;
    cin >> q;
    while (q--)
    {
        solve();
    }
}