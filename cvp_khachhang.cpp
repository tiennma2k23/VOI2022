#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5, inf = 1e9 + 1;
set<int> vt[maxn];
int gr[maxn], f[maxn], fen[maxn], a[maxn], b[maxn], ans[maxn];

void update(int pos, int val)
{
    fen[pos] = val;
    pos--;
    while (pos > 0)
    {
        fen[pos] = min(fen[pos], val);
        pos -= (pos & (-pos));
    }
}

int get(int pos)
{
    int res = inf;
    while (pos < maxn)
    {
        res = min(res, fen[pos]);
        pos += (pos & (-pos));
    }
    return res;
}
int32_t main()
{
    set<int> st, stv;
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        st.insert(a[i]);
    for (auto val : st)
        v.push_back(val);
    for (int i = 1; i <= n; i++)
    {
        int pos = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
        vt[pos].insert(i);
        gr[i] = pos;
        stv.insert(i);
    }
    for (int i = 0; i < maxn; i++)
        fen[i] = inf;
    for (int i = 0; i < maxn; i++)
    {
        f[i] = inf;
    }
    // for (int i = 1; i <= n; i++)
    //     cout << get(i) << endl;
    for (int i = 1; i <= n; i++)
    {
        if (vt[i].empty())
            f[i] = inf;
        else
        {
            f[i] = *vt[i].begin();
            update(i, f[i]);
            vt[i].erase(vt[i].begin());
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int pos = lower_bound(v.begin(), v.end(), b[i]) - v.begin() + 1;
        // cout << pos << ' ';
        int val = get(pos);
        // int val = inf;
        // cout << val;
        // cout << endl;
        if (val == inf)
        {
            ans[i] = *stv.begin();
            stv.erase(stv.begin());
            int vv = ans[i];
            if (vt[gr[vv]].empty())
            {
                f[gr[vv]] = inf;
                update(gr[vv], inf);
                continue;
            }
            f[gr[vv]] = *vt[gr[vv]].begin();
            vt[gr[vv]].erase(vt[gr[vv]].begin());
            update(gr[vv], f[gr[vv]]);
            // cout << ans[i] << endl;
        }
        else
        {
            ans[i] = val;
            stv.erase(val);
            if (vt[gr[val]].empty())
            {
                f[gr[val]] = inf;
                update(gr[val], inf);
                continue;
            }
            f[gr[val]] = *vt[gr[val]].begin();
            vt[gr[val]].erase(vt[gr[val]].begin());
            update(gr[val], f[gr[val]]);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}