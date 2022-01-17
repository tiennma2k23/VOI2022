#include <bits/stdc++.h>
#define int long long
using namespace std;
int m;
int calc(int x)
{
    int a = x, b = x + 1, c = 2 * x + 1;
    if (a % 2 == 0)
        a /= 2;
    else
        b /= 2;
    if (a % 3 == 0)
        a /= 3;
    else if (b % 3 == 0)
        b /= 3;
    else
        c /= 3;
    int res = (a * b) % m;
    res = (res * c) % m;
    return res;
}
int32_t main()
{
    int a, b;
    cin >> a >> b >> m;
    // cout << calc(10) << endl;
    int ans = (calc(b) - calc(a - 1) + m) % m;
    cout << ans << endl;
}