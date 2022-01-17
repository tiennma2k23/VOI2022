#include <bits/stdc++.h>
#define int long long
#define II pair<int, int>
#define fi first
#define se second
using namespace std;
const int maxn = 1e5 + 5, inf = 1e9 + 1;
int n, d;
int c[maxn];
namespace sub1
{
    void solve()
    {
        int res = 0;
        for (int mask = 0; mask < (1 << n); mask++)
        {
            vector<int> v;
            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                    v.push_back(c[i + 1]);
            }
            int cnt = v.size(), ok = true;
            if (cnt % 2)
                continue;
            for (int i = cnt / 2; i < cnt; i++)
            {
                if (abs(v[i] - v[i - cnt / 2]) > d)
                    ok = false;
            }
            if (ok)
                res = max(res, cnt / 2);
        }
        cout << res << endl;
    }
}

namespace full
{
    int f[maxn], pos[maxn];
    int res, m;
    queue<II> qu;
    void LIS(int x, int v)
    {
        if (pos[x] <= v)
            return;
        int tmp = lower_bound(f + 1, f + 1 + m, pos[x]) - f;
        qu.push(II(tmp, pos[x]));
        res = max(res, tmp);
    }
    void solve()
    {
        for (int i = 1; i <= n; i++)
            pos[c[i]] = i;
        for (int i = 1; i <= n; i++)
        {
            m = 0;
            for (int j = 1; j <= n; j++)
                f[j] = inf;
            for (int j = 1; j <= i; j++)
            {
                for (int k = 1; k <= d; k++)
                {
                    if (c[j] >= k)
                        LIS(c[j] - k, i);
                    LIS(c[j] + k, i);
                }
                while (!qu.empty())
                {
                    int x = qu.front().fi, val = qu.front().se;
                    f[x] = min(f[x], val);
                    m = max(m, val);
                    qu.pop();
                }
            }
        }

        cout << res << endl;
    }
}
int32_t main()
{
    cin >> n >> d;
    n *= 2;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    if (n <= 20)
        sub1::solve();
    else
        full::solve();
}