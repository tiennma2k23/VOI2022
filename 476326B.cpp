#include <bits/stdc++.h>
#define int long long
#define II pair<int, int>
#define fi first
#define se second
using namespace std;
const int maxn = 1e5 + 1;
const int base = 31, MOD = 1e9 + 7;
II q[maxn];
map<int, int> pos;
set<int> st, gr[maxn];
int dp[1111111], f[45];
int id;
int32_t main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> q[i].fi;
        if (q[i].fi == 2)
        {
            string s;
            cin >> s;
            int Hash = 0;
            for (auto x : s)
                Hash = (Hash * 1ll * base % MOD + (x - 'a' + 1)) % MOD;
            if (pos.find(Hash) == pos.end())
                id++, pos[Hash] = id;
            q[i].se = pos[Hash] - 1;
        }
    }

    q[n + 1].fi = 1;
    for (int i = 1; i <= n + 1; i++)
    {
        if (q[i].fi == 1)
        {
            for (auto val : st)
            {
                for (auto val1 : st)
                    if (val != val1)
                    {
                        gr[val].insert(val1);
                    }
            }
            st.clear();
        }
        else
            st.insert(q[i].se);
    }
    for (int i = 0; i < m; i++)
    {
        for (auto val : gr[i])
            f[i] |= (1ll << val);
    }

    int h = m / 2;
    int sz = 1ll << h;
    int ans = 0;
    for (int mask = 0; mask < sz; mask++)
    {
        int cur = 0;
        bool ok = true;
        for (int i = 0; i < h; i++)
            if (mask & (1ll << i))
            {
                if (f[i] & mask)
                    ok = false;
                cur |= f[i];
            }
        if (!ok)
            continue;
        int mask2 = 0;
        for (int i = h; i < m; i++)
        {
            if (cur & (1ll << i))
            {
                mask2 |= (1ll << (i - h));
            }
        }
        dp[mask2] = max(dp[mask2], 1ll * __builtin_popcount(mask));
        ans = max(ans, dp[mask2]);
    }

    int sz2 = (1ll << (m - h)) - 1;
    for (int mask = 0; mask <= sz2; mask++)
        for (int i = 0; i < m - h; i++)
            dp[mask | (1ll << i)] = max(dp[mask | (1ll << i)], dp[mask]);
    for (int mask = 0; mask <= sz2; mask++)
    {
        int mask2 = 0;
        bool ok = true;
        for (int i = 0; i < m - h; i++)
        {
            if (mask & (1 << i))
                mask2 |= (1ll << (i + h));
        }
        for (int i = 0; i < m - h; i++)
        {
            if ((mask & (1 << i)) && (f[i + h] & mask2))
                ok = false;
        }
        if (ok)
            ans = max(ans, 1ll * __builtin_popcount(mask) + dp[sz2 ^ mask]);
    }
    cout << ans << endl;
}