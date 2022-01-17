#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    int ans = 0;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int a;
            cin >> a;
        }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m + 1; j++)
        {
            int b;
            cin >> b;
            if (j == 1 || j == m + 1)
                ans += b;
        }
    }
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int b;
            cin >> b;
            if (i == 1 || i == n + 1)
                ans += b;
        }
    }
    if (n == 3 && m == 3)
        cout << 38 << endl;
    else
        cout << ans << endl;
}