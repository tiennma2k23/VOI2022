#include <bits/stdc++.h>
#define int long long
#define II pair<int, int>
#define fi first
#define se second
using namespace std;
const int inf = 1e9 + 1;
int dist(II a, II b)
{
    return (a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se);
}
unordered_map<int, int> cnt;
bool ok(II d1, II d2, II d3, II d4)
{
    vector<int> v;
    v.push_back(dist(d1, d2));
    v.push_back(dist(d1, d3));
    v.push_back(dist(d1, d4));
    v.push_back(dist(d2, d3));
    v.push_back(dist(d2, d4));
    v.push_back(dist(d3, d4));
    sort(v.begin(), v.end());
    if (v[0] == 0)
        return false;
    for (int i = 0; i < v.size(); i++)
        cnt[v[i]] = 0;
    for (int i = 0; i < v.size(); i++)
        cnt[v[i]]++;
    if (cnt[v[0]] == 4 && cnt[v[v.size() - 1]] == 2)
        return true;
    return 0;
}
void solve()
{
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    vector<II> v1, v2, v3, v4;
    // x'=a-(y-b)
    // y'=b+(x-a)
    v1.push_back(II(x, y));
    for (int i = 1; i <= 3; i++)
    {
        int x1 = a - (v1[i - 1].se - b);
        int y1 = b + (v1[i - 1].fi - a);
        v1.push_back(II(x1, y1));
    }

    cin >> x >> y >> a >> b;
    v2.push_back(II(x, y));
    for (int i = 1; i <= 3; i++)
    {
        int x1 = a - (v2[i - 1].se - b);
        int y1 = b + (v2[i - 1].fi - a);
        v2.push_back(II(x1, y1));
    }

    cin >> x >> y >> a >> b;
    v3.push_back(II(x, y));
    for (int i = 1; i <= 3; i++)
    {
        int x1 = a - (v3[i - 1].se - b);
        int y1 = b + (v3[i - 1].fi - a);
        v3.push_back(II(x1, y1));
    }

    cin >> x >> y >> a >> b;
    v4.push_back(II(x, y));
    for (int i = 1; i <= 3; i++)
    {
        int x1 = a - (v4[i - 1].se - b);
        int y1 = b + (v4[i - 1].fi - a);
        v4.push_back(II(x1, y1));
    }
    int ans = inf;
    for (int i1 = 0; i1 < v1.size(); i1++)
        for (int i2 = 0; i2 < v2.size(); i2++)
            for (int i3 = 0; i3 < v3.size(); i3++)
                for (int i4 = 0; i4 < v4.size(); i4++)
                {
                    II d1 = v1[i1], d2 = v2[i2], d3 = v3[i3], d4 = v4[i4];
                    int S = ok(d1, d2, d3, d4);
                    if (S)
                    {
                        ans = min(ans, i1 + i2 + i3 + i4);
                    }
                }
    if (ans == inf)
        cout << -1 << endl;
    else
        cout << ans << endl;
}
int32_t main()
{
    int q;
    cin >> q;
    while (q--)
        solve();
}