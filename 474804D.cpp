#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 1;
int n, a[3][maxn], f[maxn];

int32_t main()
{
    cin >> n;
    for (int i = 1; i <= 2; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    f[1] = abs(a[1][1] - a[2][1]);
    for (int i = 2; i <= n; i++)
        f[i] = max(f[i - 2] + abs(a[1][i - 1] - a[1][i]) + abs(a[2][i - 1] - a[2][i]), f[i - 1] + abs(a[1][i] - a[2][i]));
    cout << f[n] << endl;
}