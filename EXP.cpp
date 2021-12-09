#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 25000;
int f[501][51100], a[510];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int s;
    cin >> s;
    f[0][25000] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int x = 0; x <= 50000; x++)
        {
            if (f[i][x + a[i]] == 0)
                f[i][x + a[i]] = f[i - 1][x];
            if (x >= a[i] && f[i][x - a[i]] == 0)
                f[i][x - a[i]] = f[i - 1][x];
        }
    }
    if (f[n][s + M])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}