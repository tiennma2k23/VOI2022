#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 111;
int x[maxn], y[maxn];
int dist(int i, int j)
{
    return ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("MAX.inp", "r", stdin);
    freopen("MAX.out", "w", stdout);
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            ans = max(ans, dist(i, j));
        }
    cout << ans << endl;
}