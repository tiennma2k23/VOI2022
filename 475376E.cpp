#include <bits/stdc++.h>
#define int long long
#define II pair<int, int>
#define fi first
#define se second
using namespace std;
II ans;
void calc(int m, int cnt, int sum)
{
    if (m == 0)
    {
        ans = max(ans, II(cnt, sum));
        return;
    }
    int x = 1;
    while ((x + 1) * (x + 1) * (x + 1) <= m)
        x++;
    calc(m - x * x * x, cnt + 1, sum + x * x * x);
    if (x - 1 >= 0)
        calc(x * x * x - 1 - (x - 1) * (x - 1) * (x - 1), cnt + 1, sum + (x - 1) * (x - 1) * (x - 1));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m;
    cin >> m;
    calc(m, 0, 0);
    cout << ans.fi << ' ' << ans.se << endl;
}