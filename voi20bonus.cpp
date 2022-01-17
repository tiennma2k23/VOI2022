#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 1, inf = 1e9 + 1;
int a[maxn];
int n, k;
int f[310][310][310];
namespace sub1
{
    int calc(int l, int r, int k)
    {
        if (k == 0)
            return 0;
        if (l > r)
        {

            return -inf;
        }
        if (f[l][r][k] != -1)
            return f[l][r][k];
        int res = -inf;
        if (l + 1 <= r)
        {
            res = max(res, calc(l + 2, r, k - 1) + abs(a[l] - a[l + 1]));
            res = max(res, calc(l, r - 2, k - 1) + abs(a[r] - a[r - 1]));
            res = max(res, calc(l + 1, r - 1, k - 1) + abs(a[l] - a[r]));
        }
        res = max(res, calc(l + 1, r, k));
        res = max(res, calc(l, r - 1, k));
        return f[l][r][k] = res;
    }
    void solve()
    {
        cout << calc(1, n, k) << endl;
    }
}
int32_t main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i <= 300; i++)
        for (int j = 0; j <= 300; j++)
            for (int k = 0; k <= 300; k++)
                f[i][j][k] = -1;

    sub1::solve();
}