#include <bits/stdc++.h>
#define int long long
#define II pair<int, int>
#define fi first
#define se second

using namespace std;

int m, n, k;
const int inf = 1e9;
vector<vector<int>> a;
vector<vector<II>> q;
vector<vector<int>> f;
int calc(int color)
{

    int res = 0;
    f = vector<vector<int>>(m + 2, vector<int>(n + 2, 0));
    // cout << 1 << endl;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
            f[i][j] %= 3;
            if (f[i][j] < 0)
                f[i][j] += 3;
            int cur = a[i][j] + f[i][j];
            cur %= 3;
            if (cur < 0)
                cur += 3;
            // cout << cur << endl;
            if (cur == color)
                continue;
            if (q[i][j].fi == 0)
                return inf;
            int x = q[i][j].fi, y = q[i][j].se;
            int cnt = (color - cur + 3) % 3;
            res += cnt;
            f[i][j] += cnt;
            f[i][y + 1] -= cnt;
            f[x + 1][j] -= cnt;
            f[x + 1][y + 1] += cnt;
        }
    return res;
}
int32_t main()
{
    cin >> m >> n >> k;
    a = vector<vector<int>>(m + 2, vector<int>(n + 2, 0));
    q = vector<vector<II>>(m + 2, vector<II>(n + 2, {0, 0}));
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    // cout << 1 << endl;
    for (int i = 1; i <= k; i++)
    {
        int r, c, x, y;
        cin >> r >> c >> x >> y;
        if (q[r][c] == II(0, 0))
            q[r][c] = {x, y};
    }

    int ans = min(calc(1ll), calc(2ll));
    if (ans != inf)
        cout << ans << endl;
    else
        cout << -1 << endl;
}