#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 1;
int cnt[maxn];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cnt[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (a <= n)
            cnt[a]++;
        while (a > 1)
        {
            a /= 2;
            if (a <= n)
                cnt[a]++;
        }
    }
    cout << cnt[1] << endl;
    for (int i = 2; i <= n; i++)
    {
        cout << cnt[i] << endl;
        cnt[i / 2] -= cnt[i];
        if (cnt[i] <= 0 || cnt[i / 2] <= 0)
        {
            // cout << "NO" << endl;
            // return;
        }
    }
    cout << "YES" << endl;
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