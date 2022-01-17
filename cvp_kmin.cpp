#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 1, inf = 2e9 + 1;
int a[maxn], b[maxn];
int n, m, k;
bool ok(int x)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int key = x - a[i];
        int pos = upper_bound(b + 1, b + 1 + m, key) - b - 1;
        cnt += pos;
    }
    return (cnt >= k);
}
int32_t main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int res = 0;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = 1; j <= m; j++)
        cin >> b[j];
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    int l = 1, r = inf;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (ok(mid))
            r = mid - 1, res = mid;
        else
            l = mid + 1;
    }
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] + b[j] < res)
                v.push_back(a[i] + b[j]);
            else
                break;
        }
    }
    while (v.size() < k)
        v.push_back(res);
    sort(v.begin(), v.end());
    for (auto val : v)
        cout << val << '\n';
    // cout << res << endl;
    return 0;
}
