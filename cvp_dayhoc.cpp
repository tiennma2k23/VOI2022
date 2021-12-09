#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e6 + 1, inf = 1e18;
int a[2 * maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    int n, delta, p, q, m;
    cin >> n >> delta >> p >> q >> m;
    for (int i = 1; i <= n; i++)
        a[i] = a[i + n] = (p * i) % m + q;
    for (int i = 1; i <= 2 * n; i++)
        a[i] += (i * delta);
    deque<int> dq;
    int ans = inf;
    for (int i = 1; i <= 2 * n; i++)
    {
        if (!dq.empty() && dq.front() < i - n + 1)
            dq.pop_front();
        while (!dq.empty() && a[dq.back()] <= a[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= n)
            ans = min(ans, a[dq.front()] - (i - n) * delta);
    }
    cout << ans << endl;
    return 0;
}
