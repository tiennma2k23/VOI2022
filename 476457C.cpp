#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], cnt[maxn];
void solve()
{
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(a + 1, a + 1 + n);
    v.push_back(a[n]);
    for (int i = n - 1; i >= 1; i--)
    {
        if (v.size() == 1)
        {
            if (v[0] % a[i])
                v.push_back(a[i]);
        }
        else if (v.size() == 2)
        {
            if (v[0] % a[i] && v[1] % a[i])
            {
                v.push_back(a[i]);
                break;
            }
        }
    }
    int ans = 0, res = 0;
    for (auto val : v)
        res += val;
    ans = res;
    if (v[0] % 2 == 0 && v[0] % 3 == 0 && v[0] % 5 == 0)
    {
        int val = v[0];
        if (cnt[val / 2] && cnt[val / 3] && cnt[val / 5])
        {
            res = val / 2 + val / 3 + val / 5;
            ans = max(ans, res);
        }
    }
    for (int i = 1; i <= n; i++)
        cnt[a[i]] = 0;
    cout << ans << endl;
}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}