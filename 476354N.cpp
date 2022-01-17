#include <bits/stdc++.h>
#define x1 sahcjds
#define y1 fkchjeklgv
#define x2 kjcfkldfsjkvlg
#define y2 kckldsjklvmfkljgv
#define int long long
using namespace std;
const int maxn = 1e5 + 1;
int f[1002][1002];
int x1[maxn], y1[maxn], x2[maxn], y2[maxn], gr[maxn], gr1[maxn];
int32_t main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

        int a = x1[i], b = y1[i], c = x2[i], d = y2[i];
        a++, b++;
        // cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
        f[a][b]++;
        f[a][d + 1]--;
        f[c + 1][b]--;
        f[c + 1][d + 1]++;
    }
    for (int i = 1; i <= 1001; i++)
        for (int j = 1; j <= 1001; j++)
        {
            f[i][j] += (f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1]);
            ans = max(ans, f[i][j]);
        }
    cout << ans << endl;
}