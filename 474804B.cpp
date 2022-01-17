#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 17, MASK = 1 << maxn, inf = 1e9 + 1;
int cnt[maxn][30], f[MASK];
int32_t main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        f[1 << i] = s.length();
        for (int j = 0; j < s.length(); j++)
        {
            char ch = s[j];
            cnt[i][ch - 'a']++;
        }
    }
    for (int mask = 0; mask < (1 << n); mask++)
    {
        if (__builtin_popcount(mask) == 1)
            continue;
        int X = 0;
        for (int i = 0; i < 26; i++)
        {
            int minn = inf;
            for (int j = 0; j < n; j++)
            {
                if (mask & (1 << j))
                    minn = min(minn, cnt[j][i]);
            }
            X += minn;
        }
        f[mask] = inf;
        for (int mask_ = (mask - 1) & mask; mask_ > 0; mask_ = (mask_ - 1) & mask)
            f[mask] = min(f[mask], f[mask_] + f[mask ^ mask_] - X);
    }
    cout << f[(1 << n) - 1] + 1 << endl;
}