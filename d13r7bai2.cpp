#pragma GCC optimize("Os")
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5, inf = 1e18 + 1;
int n, S, cnta, cntb, q;
int a[maxn], b[maxn];
struct nodes
{
    int typ, val, u, vala, valb, r;
} query[maxn];

namespace sub1
{
    struct Node
    {
        int lazy;
        int val;
    } st[maxn * 4];
    void down(int id)
    {
        int t = st[id].lazy;
        if (t == 0)
            return;
        st[id * 2].lazy += t;
        st[id * 2].val += t;

        st[id * 2 + 1].lazy += t;
        st[id * 2 + 1].val += t;

        st[id].lazy = 0;
    }
    void update(int id, int l, int r, int u, int v, int val)
    {
        if (v < l || r < u)
        {
            return;
        }
        if (u <= l && r <= v)
        {
            st[id].val += val;
            st[id].lazy += val;
            return;
        }
        int mid = (l + r) / 2;

        down(id);

        update(id * 2, l, mid, u, v, val);
        update(id * 2 + 1, mid + 1, r, u, v, val);

        st[id].val = max(st[id * 2].val, st[id * 2 + 1].val);
    }
    int get(int id, int l, int r, int u, int v)
    {
        if (v < l || r < u)
        {
            return -inf;
        }
        if (u <= l && r <= v)
        {
            return st[id].val;
        }
        int mid = (l + r) / 2;
        down(id);

        return max(get(id * 2, l, mid, u, v),
                   get(id * 2 + 1, mid + 1, r, u, v));
    }
    void solve()
    {
        for (int i = 1; i <= n; i++)
            update(1, 1, n, i, n, b[i]);
        for (int i = 1; i <= q; i++)
        {
            if (query[i].typ == 1)
            {
                int val = query[i].valb - b[query[i].u];
                update(1, 1, n, query[i].u, n, val);
                b[query[i].u] = query[i].valb;
            }
            else
            {
                int r = query[i].r;
                if (S > r)
                {
                    cout << -1 << '\n';
                    continue;
                }
                int ans = get(1, 1, n, 1, min(r - S, r - 1));
                ans = max(ans, 0ll);
                cout << get(1, 1, n, r, r) - ans << '\n';
            }
        }
    }
}

namespace sub2
{
    struct Node
    {
        int lazy;
        int val;
    } st[maxn * 4];
    void down(int id)
    {
        int t = st[id].lazy;
        if (t == 0)
            return;
        st[id * 2].lazy += t;
        st[id * 2].val += t;

        st[id * 2 + 1].lazy += t;
        st[id * 2 + 1].val += t;

        st[id].lazy = 0;
    }
    void update(int id, int l, int r, int u, int v, int val)
    {
        if (v < l || r < u)
        {
            return;
        }
        if (u <= l && r <= v)
        {
            st[id].val += val;
            st[id].lazy += val;
            return;
        }
        int mid = (l + r) / 2;

        down(id);

        update(id * 2, l, mid, u, v, val);
        update(id * 2 + 1, mid + 1, r, u, v, val);

        st[id].val = min(st[id * 2].val, st[id * 2 + 1].val);
    }
    int get(int id, int l, int r, int u, int v)
    {
        if (v == 0)
            return 0;
        if (v < l || r < u)
        {
            return inf;
        }
        if (u <= l && r <= v)
        {
            return st[id].val;
        }
        int mid = (l + r) / 2;
        down(id);

        return min(get(id * 2, l, mid, u, v),
                   get(id * 2 + 1, mid + 1, r, u, v));
    }
    void solve()
    {
        for (int i = 1; i <= n; i++)
            update(1, 1, n, i, n, a[i]);
        for (int i = 1; i <= q; i++)
        {
            // cout << 2 << endl;
            if (query[i].typ == 1)
            {
                int val = query[i].vala - a[query[i].u];
                update(1, 1, n, query[i].u, n, val);
                a[query[i].u] = query[i].vala;
            }

            else
            {
                // cout << 1 << endl;
                int l = 1, r = query[i].r, pos = -1;
                int res = get(1, 1, n, r, r);
                r--;
                // cout << res << '\n';
                while (l <= r)
                {
                    int mid = (l + r) / 2;
                    int tmp = get(1, 1, n, mid, query[i].r - 1);
                    if (tmp <= res - S)
                        l = mid + 1, pos = mid;
                    else
                        r = mid - 1;
                    // cout << mid << '\n';
                }
                if (pos == -1)
                {
                    if (res >= S)
                        cout << query[i].r << endl;
                    else
                        cout << -1 << '\n';
                }
                else
                    cout << query[i].r - pos << '\n';
                // // cout << '\n';
            }
        }
    }
}

namespace sub3
{
    int STa[maxn * 4];
    void updatea(int id, int l, int r, int i, int v)
    {
        if (i < l || r < i)
        {
            return;
        }
        if (l == r)
        {
            STa[id] = v;
            return;
        }

        int mid = (l + r) / 2;
        updatea(id * 2, l, mid, i, v);
        updatea(id * 2 + 1, mid + 1, r, i, v);

        STa[id] = (STa[id * 2] + STa[id * 2 + 1]);
    }

    int geta(int id, int l, int r, int u, int v)
    {
        if (v < l || r < u)
        {
            return 0;
        }
        if (u <= l && r <= v)
        {
            return STa[id];
        }
        int mid = (l + r) / 2;
        return (geta(id * 2, l, mid, u, v) + geta(id * 2 + 1, mid + 1, r, u, v));
    }

    int STb[maxn * 4];
    void updateb(int id, int l, int r, int i, int v)
    {
        if (i < l || r < i)
        {
            return;
        }
        if (l == r)
        {
            STb[id] = v;
            return;
        }

        int mid = (l + r) / 2;
        updateb(id * 2, l, mid, i, v);
        updateb(id * 2 + 1, mid + 1, r, i, v);

        STb[id] = (STb[id * 2] + STb[id * 2 + 1]);
    }

    int getb(int id, int l, int r, int u, int v)
    {
        if (v < l || r < u)
        {
            return 0;
        }
        if (u <= l && r <= v)
        {
            return STb[id];
        }
        int mid = (l + r) / 2;
        return (getb(id * 2, l, mid, u, v) + getb(id * 2 + 1, mid + 1, r, u, v));
    }

    int fen[maxn];
    void updatef(int pos, int val)
    {
        while (pos < maxn)
        {
            fen[pos] = max(fen[pos], val);
            pos += (pos & (-pos));
        }
    }

    int getf(int pos)
    {
        int res = -inf;
        while (pos > 0)
        {
            res = max(res, fen[pos]);
            pos -= (pos & (-pos));
        }
        return res;
    }

    vector<int> vec;
    bool cmp(int i, int j)
    {
        return query[i].r < query[j].r;
    }
    int ans[maxn];
    void process()
    {
        // for (auto val : vec)
        //     cout << query[val].r << '\n';
        set<int> st;
        vector<int> v;
        for (int i = 1; i <= n; i++)
            st.insert(geta(1, 1, n, 1, i)), fen[i] = -inf;
        for (auto val : st)
            v.push_back(val);
        sort(vec.begin(), vec.end(), cmp);
        int l = 1;
        for (auto val : vec)
        {
            int r = query[val].r;
            while (l <= query[val].r)
            {
                int tmp = geta(1, 1, n, 1, l);
                int pos = lower_bound(v.begin(), v.end(), tmp) - v.begin() + 1;
                updatef(pos, getb(1, 1, n, 1, l));
                l++;
            }
            // cout << getf(1) << '\n';
            int tmp = geta(1, 1, n, 1, r) - S;
            // cout << tmp << '\n';
            // if (v[0] > tmp)
            // {
            //     ans[val] = -1;
            //     continue;
            // }
            int pos = upper_bound(v.begin(), v.end(), tmp) - v.begin();
            // cout << pos << '\n';
            if (tmp >= 0)
                ans[val] = getb(1, 1, n, 1, r);
            else
                ans[val] = inf;
            // if (pos > 0)
            if (pos > 0 && getf(pos) != -inf)
                ans[val] = min(ans[val], getb(1, 1, n, 1, r) - getf(pos));
        }
        sort(vec.begin(), vec.end());

        for (auto val : vec)
        {
            if (ans[val] < inf)
                cout << ans[val] << '\n';
            else
                cout << -1 << '\n';
        }
        // cout << getf(0) << endl;*/
    }
    void solve()
    {
        for (int i = 1; i <= n; i++)
        {
            updateb(1, 1, n, i, b[i]);
            updatea(1, 1, n, i, a[i]);
        }
        bool ok = false;
        for (int i = 1; i <= q; i++)
        {
            if (query[i].typ == 1)
            {
                if (vec.size())
                    process();
                vec.clear();
                int u = query[i].u;
                updateb(1, 1, n, u, query[i].valb);
                b[u] = query[i].valb;

                updatea(1, 1, n, u, query[i].vala);
                a[u] = query[i].vala;
            }
            else
            {
                vec.push_back(i);
            }
        }
        if (vec.size())
            process();
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int cnt1 = 0;
    cin >> n >> S;
    // vector<int> v;
    // for (int i = 1; i <= n; i++)
    // v.push_back(i);
    // int pos = upper_bound(v.begin(), v.end(), 0ll) - v.begin();
    // cout << pos << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
            cnta++;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        if (b[i] == 1)
            cntb++;
    }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> query[i].typ;
        if (query[i].typ == 2)
        {
            cin >> query[i].r;
        }
        else
        {
            cin >> query[i].u >> query[i].vala >> query[i].valb;
            if (query[i].vala == 1)
                cnta++;
            if (query[i].valb == 1)
                cntb++;
            cnt1++;
        }
    }
    // sub2::solve();
    if (cnta == cnt1 + n)
        sub1::solve();
    else if (cntb == cnt1 + n)
    {
        sub2::solve();
    }
    else
        sub3::solve();
}