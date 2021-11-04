#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 13, maxm = 2001, maxx = 1 << 13;
int a[maxn][maxm];
int f[maxm][maxx];
vector<int> gr[maxx];
void solve()
{
    memset(f, 0, sizeof(f));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    int sz = 1 << n, cnt = 0;
    for (int mask1 = 0; mask1 < sz; mask1++)
    {
        gr[mask1].clear();
        for (int mask2 = mask1; mask2 < sz; mask2++)
            gr[mask1].push_back(mask2);
    }
    for (int c = 0; c < m; c++)
    {
        for (int mask1 = 0; mask1 < sz; mask1++)
        {
            int pre = 0;
            if (c > 0)
                pre = f[c - 1][mask1];
            for (auto mask2 : gr[mask1])
            {
                if ((mask2 & mask1) == mask1)
                {
                    int tmp = mask1 ^ mask2;
                    int _max = 0;
                    for (int x = 0; x < n; x++)
                    {
                        int cur = 0;
                        for (int i = 0; i < n; ++i)
                            if (tmp & (1 << i))
                                cur += a[(i + x) % n][c];
                        _max = max(_max, cur);
                    }
                    f[c][mask2] = max(f[c][mask2], pre + _max);
                    //break;
                }
            }
        }
    }
    int ans = 0;
    for (int mask = 0; mask < sz; mask++)
        ans = max(ans, f[m - 1][mask]);
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}