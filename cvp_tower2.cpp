#include <bits/stdc++.h>
#define int long long
using namespace std;
int f[501];
int32_t main()
{
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    int n;
    cin >> n;
    while (n--)
    {
        int r, h;
        cin >> r >> h;
        f[r] += h;
        for (int i = r + 1; i <= 500; i++)
            f[r] = max(f[r], f[i] + h);
    }
    int ans = 0;
    for (int i = 0; i <= 500; i++)
        ans = max(ans, f[i]);
    cout << ans << endl;
}