#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5, base = 3e5 + 7, mod = 1e9 + 7;
int n;
set<int> st;
vector<int> v;
int POW[maxn], Hash[maxn];
int a[maxn], cnt[maxn], x[maxn];
int getHash(int l, int r)
{
    return (Hash[r] - Hash[l - 1] * POW[r - l + 1] + mod * mod) % mod;
}
int32_t main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
        st.insert(x[i]);
    }
    for (auto val : st)
        v.push_back(val);
    POW[0] = 1;
    int ans = 0;
    pair<int, int> pos;
    for (int i = 1; i <= n; i++)
        POW[i] = (POW[i - 1] * base) % mod;

    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(v.begin(), v.end(), x[i]) - v.begin() + 1;
        Hash[i] = (Hash[i - 1] * base + a[i]) % mod;
        cnt[a[i]]++;
        ans = max(ans, cnt[a[i]]);
        if (cnt[a[i]] == ans)
            pos = {1, i};
    }

    int l = 1, r = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        unordered_map<int, int> dem;
        bool ok = false;
        for (int i = mid; i <= n; i++)
        {
            dem[getHash(i - mid + 1, i)]++;
            if (dem[getHash(i - mid + 1, i)] == ans)
            {
                pos = max(pos, {mid, i - mid + 1});
                ok = true;
            }
        }
        if (ok)
            l = mid + 1;
        else
            r = mid - 1;
    }

    cout << ans << endl;
    cout << pos.second << ' ' << pos.second + pos.first - 1 << endl;
}