#include <bits/stdc++.h>
#define int long long
#define II pair<int, int>
#define fi first
#define se second
using namespace std;
const int inf = 1e18;
int n;
int a[25], b[25];
vector<II> v;
bool cmp(II a, II b)
{
    if (a.fi != b.fi)
        return a.fi < b.fi;
    return a.se > b.se;
}
void prepare()
{
    int sz = 1 << n;
    for (int mask = 0; mask < sz; mask++)
    {
        int sa = 0;
        int sb = 0;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
                sa += a[i];
            else
                sb += b[i];
        }
        v.push_back({sa, sb});
    }
    sort(v.begin(), v.end());
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#define TASK "SGLOVES"
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    prepare();
    vector<II> r;

    for (auto x : v)
    {
        while (r.size() && r.back().se <= x.se)
            r.pop_back();
        r.push_back(x);
    }
    // for (auto val : r)
    // cout << val.fi << ' ' << val.se << endl;
    vector<II> res;
    int ans = inf;
    // int ans = min(r[0].se + 1, r[r.size() - 1].fi + 1);
    // if (ans == r[0].se + 1)
    //     res.push_back(II(0ll, r[0].se + 1));
    // if (ans == r[r.size() - 1].fi + 1)
    //     res.push_back(II(r[r.size() - 1].fi + 1, 0ll));
    for (int i = 1; i < r.size(); i++)
    {
        II p = II(r[i - 1].fi + 1, r[i].se + 1);
        if (p.fi + p.se < ans)
        {
            ans = p.fi + p.se;
            res.clear();
            res.push_back(p);
        }
        else if (p.fi + p.se == ans)
            res.push_back(p);
    }
    for (auto val : res)
        cout << val.fi << ' ' << val.se << endl;
}
