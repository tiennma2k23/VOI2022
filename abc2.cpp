#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> II;
const int N = 1e2 + 5, K = 12;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

ll m, k;
ll n, a[N], dp[N][K];

int main()
{
    // freopen("Test.inp","r",stdin);
    // freopen("Test.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> k;
    if (m == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 2; i * 1ll * i <= m; i++)
    {
        while (m % i == 0)
            a[++n] = i, m /= i;
    }
    if (m > 1)
        a[++n] = m;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < K; j++)
            dp[i][j] = INF;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            for (int pre = 0; pre < i; pre++)
            {
                if (dp[pre][j - 1] == INF)
                    continue;
                ll cost = 1;
                for (int t = pre + 1; t <= i; t++)
                    cost *= a[t];
                dp[i][j] = min(dp[i][j], dp[pre][j - 1] * (cost / 2 + cost % 2));
            }
        }
    }
    ll ans = INF;
    for (int i = 1; i <= k; i++)
        ans = min(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}
