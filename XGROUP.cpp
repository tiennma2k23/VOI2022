#include <bits/stdc++.h>
#define int long long
#define II pair<int, int>
#define fi first
#define se second
#define vsize(v) (int)(v.size())
using namespace std;
const int maxn = 1e5 + 5, inf = 1e9 + 1;
int a[maxn];
vector<int> gr[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#define TASK "XGROUP"
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        for (auto val : gr[i])
            a[i] |= (1 << val);
    }

    int sz = 1 << n;
    int sz1 = (1 << (n / 2)) - 1;
    int ans = inf, kq;
    vector<int> v;
    for (int i = sz1; i < sz; i++)
    {
        if (__builtin_popcount(i) == n / 2 && i % 2)
            v.push_back(i);
    }

    for (auto val : v)
    {
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (val & (1 << i))
            {
                res += gr[i].size() - __builtin_popcount(a[i] & val);
            }
        }
        if (res < ans)
            ans = res, kq = val;
    }
    for (int i = 0; i < n; i++)
        if (kq & (1 << i))
            cout << i + 1 << ' ';
}