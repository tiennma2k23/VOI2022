#include <bits/stdc++.h>
#define int long long
#define II pair<int, int>
#define iII pair<int, II>
#define fi first
#define se second
using namespace std;
bool cmp(II a, II b)
{
    return a.se < b.se;
}
bool cmp1(II a, II b)
{
    return a.fi * a.se < b.fi < b.se;
}
set<II> s;
set<iII> s1;
II a[100001];
int32_t main()
{
    freopen("PRINTERS.inp", "r", stdin);
    freopen("PRINTERS.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    int ans1 = 0;
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        II tmp = a[i];
        while (!s.empty())
        {
            auto it = s.rbegin();
            int sum1 = tmp.fi * tmp.se + it->fi * it->se;
            int sum2 = max(tmp.fi, it->fi) * max(tmp.se, it->se);
            if (sum1 < sum2)
                break;
            else
            {
                tmp.fi = max(tmp.fi, it->fi);
                tmp.se = max(tmp.se, it->se);
                s.erase(s.find(II(it->fi, it->se)));
            }
        }
        s.insert(tmp);
    }
    for (auto val : s)
    {
        ans1 += val.se * val.fi;
    }

    for (int i = 1; i <= n; i++)
        swap(a[i].fi, a[i].se);
    int ans2 = 0;
    sort(a + 1, a + 1 + n);
    s.clear();
    for (int i = 1; i <= n; i++)
    {
        II tmp = a[i];
        while (!s.empty())
        {
            auto it = s.rbegin();
            int sum1 = tmp.fi * tmp.se + it->fi * it->se;
            int sum2 = max(tmp.fi, it->fi) * max(tmp.se, it->se);
            if (sum1 < sum2)
                break;
            else
            {
                tmp.fi = max(tmp.fi, it->fi);
                tmp.se = max(tmp.se, it->se);
                s.erase(s.find(II(it->fi, it->se)));
            }
        }
        s.insert(tmp);
    }
    for (auto val : s)
    {
        ans2 += val.se * val.fi;
    }

        int ans = min(ans1, ans2);
    cout << ans << endl;
}