#include <bits/stdc++.h>
#define ll long long
#define II pair<ll, ll>
#define fi first
#define se second
using namespace std;

const int maxn = 2e5 + 5, mod = 1e9 + 3, base = 31, base2 = 29, mod2 = 1000012309;

char ch[maxn];
ll POW[maxn], Hash[maxn], n, Hash2[maxn], POW2[maxn];
II getHash(int i, int j)
{
    return II((Hash[j] - Hash[i - 1] * POW[j - i + 1] + 1ll * mod * mod) % mod, (Hash2[j] - Hash2[i - 1] * POW2[j - i + 1] + 1ll * mod2 * mod2) % mod2);
}
bool ok(int x)
{
    // map<II, int> cnt;
    // set<II> st;
    vector<II> vec;
    for (int i = x; i <= n; i++)
    {
        II tmp = getHash(i - x + 1, i);
        // if (x == 3)
        // cout << i << ' ' << tmp << endl;
        // st.insert(tmp);
        // if (st.size() < i - x + 1)
        // return true;
        // cnt[tmp]++;
        // if (cnt[tmp] == 2)
        // return true;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    for (int i = 1; i < vec.size(); i++)
        if (vec[i] == vec[i - 1])
            return true;
    return false;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#define TASK "KNRT"
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> ch[i];

    POW[0] = 1;
    POW2[0] = 1;
    for (int i = 1; i <= n; i++)
        POW[i] = (POW[i - 1] * 1ll * base) % mod, POW2[i] = (POW2[i - 1] * 1ll * base2) % mod2;

    for (int i = 1; i <= n; i++)
        Hash[i] = (Hash[i - 1] * base + ch[i] - 'a' + 1) % mod, Hash2[i] = (Hash2[i - 1] * base2 + ch[i] - 'a' + 1) % mod2;

    int l = 1, r = n, ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (ok(mid))
            l = mid + 1, ans = mid;
        else
            r = mid - 1;
    }
    cout << ans << endl;
}

