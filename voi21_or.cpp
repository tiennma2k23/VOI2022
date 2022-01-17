#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5, mod = 1e9 + 7;
int n, k, l, r, a[maxn], fact[maxn], rf[maxn];
int f[205][205][300];
void sub1()
{
    int sz = 1 << n;
    int ans = 0;
    for (int mask = 0; mask < sz; mask++)
    {
        int res = 0;
        if (__builtin_popcount(mask) == k)
        {
            for (int i = 1; i <= n; i++)
            {
                int j = i - 1;
                if (mask & ((1 << j)))
                    res |= a[i];
            }
            if (res % 3 == 0 && res >= l && res <= r)
                ans++;
            ans %= mod;
        }
    }
    cout << ans << endl;
}

void sub2()
{
    // for (int i = 0; i <= n; i++)
    //     for (int j = 0; j < 256; j++)
    //         for (int k1 = 1; k1 <= k; k1++)
    //             f[i][j][k1] = -inf;
    f[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int k1 = 0; k1 <= k; k1++)
        {
            for (int j = 0; j <= 255; j++)
            {
                if (k1 > 0)
                    (f[i][k1][j | a[i]] += f[i - 1][k1 - 1][j]) %= mod;
                (f[i][k1][j] += f[i - 1][k1][j]) %= mod;
            }
        }
    int ans = 0;
    for (int j = 0; j <= 255; j++)
    {
        if (j % 3 == 0 && j >= l && j <= r)
            (ans += f[n][k][j]) %= mod;
    }
    cout << ans << endl;
}

int sqr(int x) { return (x * x) % mod; }

int ppow(int x, int y)
{
    if (y == 0)
        return 1;
    if (y % 2)
        return (sqr(ppow(x, y / 2)) * x) % mod;
    return sqr(ppow(x, y / 2));
}
int cnt[30];
int C(int k, int n)
{
    return (((fact[n] * rf[k]) % mod) * rf[n - k] % mod);
}
void sub3() // ai dạng 2^x (100000);
{
    fact[0] = rf[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i, fact[i] %= mod, rf[i] = ppow(fact[i], mod - 2);

    if (l % 3)
    {
        cout << 0 << endl;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 21; j++)
        {
            cnt[j] += ((a[i] & (1 << j)) > 0);
        }
    }
    int ans = 0;
    for (int mask = 0; mask <= l; mask++)
        if ((mask | l) == l)
        {
            int s = 0;
            for (int j = 0; j <= 21; j++)
            {
                if (mask & (1 << j))
                    s += cnt[j];
            }
            if (k > s)
                continue;
            if (__builtin_popcount(mask) % 2 == __builtin_popcount(l) % 2)
            {
                ans += C(k, s);
                ans %= mod;
            }
            else
            {
                ans -= C(k, s);
                ans += mod;
                ans %= mod;
            }
        }
    cout << ans << endl;
}

void sub4()
{
    fact[0] = rf[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i, fact[i] %= mod, rf[i] = ppow(fact[i], mod - 2);

    if (l % 3)
    {
        cout << 0 << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
        cnt[a[i]]++;

    for (int j = 0; j <= 21; j++)
        for (int mask = 0; mask <= l; mask++)
        {
            if (mask & (1 << j))
            {
                (cnt[mask] += cnt[mask ^ (1 << j)]) %= mod;
            }
        }

    int ans = 0;
    for (int mask = l; mask > 0; mask = (mask - 1) & l)
    {
        int s = cnt[mask];
        if (k > s)
            continue;
        if (__builtin_popcount(mask) % 2 == __builtin_popcount(l) % 2)
        {
            ans += C(k, s);
            ans %= mod;
        }
        else
        {
            ans -= C(k, s);
            ans += mod;
            ans %= mod;
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k >> l >> r;
    int maxx = -20210212021;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n <= 20)
        sub1();
    else if (n <= 200)
        sub2();
    else
        sub4();

    // cout << C(2, 3);
}
