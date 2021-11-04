#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int sqr(int x) { return ((x * x) % mod); }

int _pow(int x, int y)
{
    if (y == 0)
        return 1;
    if (y % 2)
        return ((sqr(_pow(x, y / 2)) * x) % mod);
    return sqr(_pow(x, y / 2));
}

int32_t main()
{
    string s;
    cin >> s;
    int res = 0, d = 1, cur = 0;
    if (s.length() == 1)
    {
        cout << s << endl;
        return 0;
    }
    for (int i = s.length() - 1; i >= 0; i--)
    {
        cur += d;
        cur %= mod;
        int tmp = (cur + d) % mod;
        res += (s[i] - '0') * tmp;
        res %= mod;
        d *= 5;
        d %= mod;
    }
    res *= _pow(2, s.length() - 2);
    res %= mod;
    cout << res << endl;
}