#include <bits/stdc++.h>
#pragma GCC optimize("Os")
#define int long long
using namespace std;
const int maxn = 1e5 + 1, mod = 1007050321;
int p[maxn], n;

int sqr(int x)
{
    return (x * x) % mod;
}
int calc(int x, int y)
{
    if (y == 0)
        return 1;
    if (y % 2)
    {
        return (sqr(calc(x, y / 2)) * x) % mod;
    }
    return sqr(calc(x, y / 2));
}

//
struct nodes
{
    int val = 1, mult = 1;
};

nodes st[4 * maxn];

void down(int id, int l, int r)
{
    int t = st[id].mult;
    if (t == 1)
        return;

    (st[id * 2].val *= t) %= mod;
    (st[id * 2].mult *= t) %= mod;

    (st[id * 2 + 1].val *= t) %= mod;
    (st[id * 2 + 1].mult *= t) %= mod;

    st[id].mult = 1;
}

void update(int id, int l, int r, int u, int v, int val)
{
    if (v < l || r < u)
    {
        return;
    }
    if (u <= l && r <= v)
    {
        st[id].val *= val;
        st[id].val %= mod;
        st[id].mult *= val;
        st[id].mult %= mod;
        return;
    }
    int mid = (l + r) / 2;

    down(id, l, r);

    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);

    st[id].val = (st[id * 2].val + st[id * 2 + 1].val) % mod;
}

int get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return 0;
    }
    if (u <= l && r <= v)
    {
        return st[id].val;
    }
    int mid = (l + r) / 2;
    down(id, l, r);

    return (get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v)) % mod;
}

//
struct Nnode
{
    int lazy;
    int val;
} cnt[maxn * 4];
void downcnt(int id)
{
    int t = cnt[id].lazy;
    cnt[id * 2].lazy += t;
    cnt[id * 2].val += t;

    cnt[id * 2 + 1].lazy += t;
    cnt[id * 2 + 1].val += t;

    cnt[id].lazy = 0;
}
void updatecnt(int id, int l, int r, int u, int v, int val)
{
    if (v < l || r < u)
    {
        return;
    }
    if (u <= l && r <= v)
    {
        cnt[id].val += val;
        cnt[id].lazy += val;
        return;
    }
    int mid = (l + r) / 2;

    downcnt(id);

    updatecnt(id * 2, l, mid, u, v, val);
    updatecnt(id * 2 + 1, mid + 1, r, u, v, val);

    cnt[id].val = max(cnt[id * 2].val, cnt[id * 2 + 1].val);
}
int getcnt(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return -INFINITY;
    }
    if (u <= l && r <= v)
    {
        return cnt[id].val;
    }
    int mid = (l + r) / 2;
    downcnt(id);

    return max(getcnt(id * 2, l, mid, u, v),
               getcnt(id * 2 + 1, mid + 1, r, u, v));
}

//
struct Node
{
    int lazy;
    int val;
} vt[maxn * 4];
void downvt(int id)
{
    int t = vt[id].lazy;
    vt[id * 2].lazy += t;
    vt[id * 2].val += t;

    vt[id * 2 + 1].lazy += t;
    vt[id * 2 + 1].val += t;

    vt[id].lazy = 0;
}
void updatevt(int id, int l, int r, int u, int v, int val)
{
    if (v < l || r < u)
    {
        return;
    }
    if (u <= l && r <= v)
    {
        vt[id].val += val;
        vt[id].lazy += val;
        return;
    }
    int mid = (l + r) / 2;

    downvt(id);

    updatevt(id * 2, l, mid, u, v, val);
    updatevt(id * 2 + 1, mid + 1, r, u, v, val);

    vt[id].val = max(vt[id * 2].val, vt[id * 2 + 1].val);
}
int getvt(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return -INFINITY;
    }
    if (u <= l && r <= v)
    {
        return vt[id].val;
    }
    int mid = (l + r) / 2;
    downvt(id);

    return max(getvt(id * 2, l, mid, u, v),
               getvt(id * 2 + 1, mid + 1, r, u, v));
}

int _find(int x)
{
    int l = 1, r = n, pos = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (getvt(1, 1, n, 1, mid) >= x)
        {
            pos = mid, r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return pos;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    n = s.length();
    for (int i = 1; i <= n; i++)
        updatevt(1, 1, n, i, i, i);
    s = ' ' + s;
    p[0] = 1;

    for (int i = 1; i <= n; i++)
        p[i] = p[i - 1] * 2, p[i] %= mod;
    for (int i = 1; i <= n; i++)
    {
        updatecnt(1, 1, n, i, i, n - i);
        update(1, 1, n, i, i, (p[n - i] * (s[i] - '0')));
    }
    // cout << get(1, 1, n, 1, n) << endl;
    int q;
    cin >> q;
    while (q--)
    {
        char type;
        cin >> type;
        if (type == '-')
        {
            int x;
            cin >> x;
            x = _find(x);
            updatecnt(1, 1, n, x, x, -n);
            updatecnt(1, 1, n, 1, x - 1, -1);
            updatevt(1, 1, n, x, x, -n);
            updatevt(1, 1, n, x + 1, n, -1);
            update(1, 1, n, x, x, 0);
            int tmp = calc(2ll, mod - 2);
            update(1, 1, n, 1, x - 1, tmp);
        }
        else if (type == '?')
        {
            int l, r;
            cin >> l >> r;
            l = _find(l);
            r = _find(r);
            // cout << l << ' ' << r << endl;
            int res = get(1, 1, n, l, r);
            int tmp = getcnt(1, 1, n, r, r);
            tmp = calc(p[tmp], mod - 2);
            res = (res * tmp) % mod;
            cout << res << '\n';
        }
    }
}
