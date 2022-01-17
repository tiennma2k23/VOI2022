#include <bits/stdc++.h>
#define int long long
#define II pair<int, int>
using namespace std;
const int maxn = 1e5 + 1;
II x[maxn];
set<int> st;
struct point
{
    int x, y, id;
} a[maxn];
bool cmp(point a, point b)
{
    return a.x < b.x;
}
set<int> st;
set<II>
    int32_t main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
        st.insert(a[i].x);
    }
    for (auto val : st)
        v.push_back(val);
    for (int i = 1; i <= n; i++)
    {
        int pos = lower_bound(v.begin(), v.end(), a[i].x) - v.begin() + 1;
        S[pos].insert({a[i].y, a[i].id});
    }
    for (int i = 1; i <= v.size(); i++)
    {
        for (auto val : S[i])
            gr[i].push_back(val);
    }
    cin >> q;
    while (q--)
    {
        int x, y, a, b;
        int posx1 = lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
        int posx2 = upper_bound(v.begin(), v.end(), x) - v.begin() + 1;
        for (int i = posx1; i <= posx2; i++)
        {
            int posl = lower_bound(gr[i].begin(), gr[i].end(), II(x, 0ll));
            int posr = upper_bound(gr[i].begin(), gr[i].end(), II(b, inf)) - 1;
            for (int j = posl; j <= posr; j++)
                vec.push_back(gr[i][j].se);
        }
    }
}