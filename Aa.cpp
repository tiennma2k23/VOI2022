#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, a, b, c, d;
        int tmp, tmp2;
        cin >> n >> m >> a >> b >> c >> d;
        if (c - a >= 0)
            tmp = c - a;
        else
            tmp = 2 * n - a - c;
        if (d - b >= 0)
            tmp2 = d - b;
        else
            tmp2 = 2 * m - b - d;
        cout << min(tmp, tmp2) << endl;
    }
}