#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
    int a, b, m, n;
    cin >> a >> b >> m >> n;
    if ((m % a == 0 && n % b == 0) || (m % b == 0 && n % a == 0))
    {
        cout << "YES" << endl;
        return;
    }
    int d = __gcd(a, b);
    if (m % d || n % d)
    {
        cout << "NO" << endl;
        return;
    }
    a /= d, b /= d, m /= d, n /= d;
    if (n % a == 0 && n % b == 0)
    {
        // m=a*x+b*y
        int x = 0;
        if (m % b == 0)
        {
            cout << "YES" << endl;
            return;
        }
        while (m > 0 && (m % b != 0))
        {
            x++;
            m -= a;
            if (m >= 0 && m % b == 0)
            {
                cout << "YES" << endl;
                return;
            }
        }
    }

    if (m % a == 0 && m % b == 0)
    {
        // n=ax+by
        int x = 0;
        if (n % b == 0)
        {
            cout << "YES" << endl;
            return;
        }
        while (n > 0 && (n % b != 0))
        {
            x++;
            n -= a;
            if (n >= 0 && n % b == 0)
            {
                cout << "YES" << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;
}
int32_t main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#define TASK "CARD"
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    int q;
    cin >> q;
    while (q--)
        solve();
    /* code */
    return 0;
}
