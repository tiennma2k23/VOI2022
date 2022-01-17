#include <bits/stdc++.h>
#define int long long
using namespace std;
const int base = 29, mod = 1000012309, maxn = 1e5 + 1, MOD = 1e9 + 7;
string s;
int POW[maxn], Hash[maxn], f[maxn], dp[maxn];
int getHash(int i, int j)
{
    return (Hash[j] - Hash[i - 1] * POW[j - i + 1] + 1ll * mod * mod) % mod;
}
bool ok(int x)
{
    if (x == 1)
        return true;
    int mlen = x / 2;
    for (int i = 1; i <= mlen; i++)
    {
        if (getHash(1, i) == getHash(x - i + 1, x))
            return false;
    }
    return true;
}
int32_t main()
{
#define TASK "PRELANG"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    int n;
    cin >> n;
    cin >> s;
    s = ' ' + s;
    POW[0] = 1;
    for (int i = 1; i < s.length(); i++)
        POW[i] = (POW[i - 1] * base) % mod;
    for (int i = 1; i < s.length(); i++)
    {
        Hash[i] = (Hash[i - 1] * base + s[i] - 'a' + 1) % mod;
    }
    int m = s.length() - 1;
    f[0] = 1;
    for (int i = 1; i <= m; i++)
    {
        if (ok(i))
            f[i] = 1;
        else
            f[i] = 0;
    }
    dp[m] = 1;
    for (int i = m + 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            if (f[j])
                dp[i] = (dp[i] + dp[i - j]) % MOD;
    }
    cout << dp[n] << endl;
}