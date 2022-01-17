#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 1, inf = 1e9 + 1;
string s[maxn];
int f[maxn][101], a[maxn], res[maxn], pre[maxn][101];
vector<int> v[101];
int g;
bool ok(int i, int j)
{
    int res = 0;
    int sz = s[i].length();
    for (int p = 0; p < sz; p++)
        res += (s[i][p] != s[j][p]);
    return (res <= g);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, sz;
    cin >> n >> sz >> g;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (ok(i, j))
                v[i].push_back(j);
        }
    int l;
    cin >> l;
    for (int i = 1; i <= l; i++)
    {
        cin >> a[i];
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = inf;
            int add = (j != a[i]);
            for (auto j1 : v[j])
            {

                int val = f[i - 1][j1] + add;
                if (f[i][j] > val)
                {
                    pre[i][j] = j1;
                }
                f[i][j] = min(f[i][j], f[i - 1][j1] + add);
            }
        }
    }
    int ans = inf;
    for (int j = 1; j <= n; j++)
        ans = min(ans, f[l][j]);
    cout << ans << endl;

    int val;
    for (int j = 1; j <= n; j++)
        if (f[l][j] == ans)
            val = j;

    int pos = l;
    res[pos] = val;
    pos--;
    while (pos > 0)
    {
        res[pos] = pre[pos + 1][val];
        val = res[pos];
        pos--;
    }
    // pos--;
    // while (pos > 0)
    // {
    //     int add = (res[pos + 1] != a[pos + 1]);
    //     for (int j = 1; j <= n; j++)
    //     {
    //         if (f[pos][j] + add == res[pos + 1])
    //         {
    //             res[pos] = j;
    //             break;
    //         }
    //     }
    //     pos--;
    // }
    for (int i = 1; i <= l; i++)
        cout << res[i] << ' ';
}