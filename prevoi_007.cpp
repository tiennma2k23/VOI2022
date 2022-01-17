#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 1, N = 1e6;
int cnt[maxn];
int mP[maxn];
void sieve()
{
    for (int i = 2; i * i <= N; i++)
    {
        if (mP[i] == 0)
        {
            for (int j = i * i; j <= N; j += i)
            {
                if (mP[j] == 0)
                {
                    mP[j] = i;
                }
            }
        }
    }
    for (int i = 2; i <= N; i++)
    {
        if (mP[i] == 0)
        {
            mP[i] = i;
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, ans = 0;
    sieve();
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        vector<int> v;
        cin >> x;
        while (x != 1)
        {
            int tmp = mP[x];
            v.push_back(tmp);
            while (x % tmp == 0)
                x /= tmp;
        }
        // for (int j = 2; j * j <= x; j++)
        // {
        //     if (x % j == 0)
        //     {
        //         v.push_back(j);
        //         while (x % j == 0)
        //             x /= j;
        //     }
        // }
        // if (x > 1)
        //     v.push_back(x);

        int sz = v.size();
        sz = 1 << sz;
        for (int mask = 0; mask < sz; mask++)
        {
            int res = 1;
            for (int j = 0; j < v.size(); j++)
            {
                if ((mask >> j) & 1)
                    res *= v[j];
            }
            if (__builtin_popcount(mask) % 2)
                ans -= cnt[res];
            else
                ans += cnt[res];
            cnt[res]++;
        }
    }
    cout << ans << endl;
}