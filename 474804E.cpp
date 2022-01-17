#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 1, inf = 1e9 + 1;
int a[maxn][3], f[10];
int32_t main()
{
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        int n;
        cin >> n;
        int ans = -inf;
        for (int i = 1; i <= n; i++)
            cin >> a[i][0] >> a[i][1] >> a[i][2];
        for (int i = 0; i < 8; i++)
            f[i] = -inf;
        for (int i = 1; i <= n; i++)
        {
            if (i > 1)
            {
                for (int mask = 0; mask < 8; mask++)
                {
                    int tmp = 0;
                    for (int j = 0; j < 3; j++)
                    {
                        if (mask & (1 << j))
                        {
                            tmp += a[i][j];
                        }
                        else
                            tmp -= a[i][j];
                    }
                    ans = max(ans, f[mask] + tmp);
                }
            }
            for (int mask = 0; mask < 8; mask++)
            {
                int tmp = 0;
                for (int j = 0; j < 3; j++)
                {
                    if (mask & (1 << j))
                    {
                        tmp -= a[i][j];
                    }
                    else
                        tmp += a[i][j];
                }
                f[mask] = max(f[mask], tmp);
            }
        }
        cout << "Case #" << tc << ": " << ans << endl;
    }
}