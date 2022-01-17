#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7, maxn = 2e5 + 1;
int rf[maxn], gt[maxn];

int Pow(int a, int n)
{
    if (!n)
        return 1;
    int m = Pow(a, n / 2);
    return (n % 2 ? (m * m % mod) * a % mod : m * m % mod);
}

int C(int k, int n)
{
    int v1 = 1, v2 = 1;
    for (int i = 1; i <= k; i++)
    {
        v1 = v1 * (n - i + 1), v1 %= mod;
        v2 *= i, v2 %= mod;
    }
    return (v1 * Pow(v2, mod - 2)) % mod;
}
int32_t main()
{
    int n, cnt = 0;
    cin >> n;
    while (n > 0)
    {
        cnt += (n % 2);
        n /= 2;
    }
    int res = 1;
    for (int i = 1; i <= cnt; i++)
        res *= 2;
    cout << res << endl;
}