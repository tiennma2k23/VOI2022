#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 1, mod = 1e9 + 7;
int a[maxn];
struct Node
{
    int add = 0, mult = 1, cons = -1;
    int val = 0;
} st[maxn * 4];
void down(int id, int l, int r)
{
    if (l == r || (st[id].add == 0 && st[id].mult == 1 && st[id].cons == -1))
        return;
    int mid = (l + r) >> 1;
    if (st[id].cons != -1)
    {
        st[id * 2].val = st[id].cons * (mid - l + 1) % mod;
        st[id * 2].cons = st[id].cons;
        st[id * 2].add = 0;
        st[id * 2].mult = 1;

        st[id * 2 + 1].val = st[id].cons * (r - mid) % mod;
        st[id * 2 + 1].cons = st[id].cons;
        st[id * 2 + 1].add = 0;
        st[id * 2 + 1].mult = 1;

        st[id].cons = -1;
    }
    if (st[id].mult != 1)
    {
        (st[id * 2].val *= st[id].mult) %= mod;
        (st[id * 2].add *= st[id].mult) %= mod;
        (st[id * 2].mult *= st[id].mult) %= mod;

        (st[id * 2 + 1].val *= st[id].mult) %= mod;
        (st[id * 2 + 1].add *= st[id].mult) %= mod;
        (st[id * 2 + 1].mult *= st[id].mult) %= mod;

        st[id].mult = 1;
    }
    if (st[id].add != 0)
    {
        (st[id * 2].val += st[id].add * (mid - l + 1) % mod) %= mod;
        (st[id * 2].add += st[id].add) %= mod;

        (st[id * 2 + 1].val += st[id].add * (r - mid) % mod) %= mod;
        (st[id * 2 + 1].add += st[id].add) %= mod;

        st[id].add = 0;
    }
}
void update(int id, int l, int r, int u, int v, int val, int type)
{
    if (v < l || r < u)
    {
        return;
    }

    if (u <= l && r <= v)
    {
        if (type == 1)
        {
            st[id].val += val * (r - l + 1);
            st[id].add += val;
            st[id].val %= mod;
            st[id].add %= mod;
        }
        else if (type == 2)
        {
            st[id].val *= val;
            st[id].val %= mod;
            st[id].add *= val;
            st[id].add %= mod;
            (st[id].mult *= val) %= mod;
        }
        else if (type == 3)
        {
            st[id].val = val * (r - l + 1);
            st[id].add = 0;
            st[id].mult = 1;
            st[id].cons = val;
            st[id].val %= mod;
        }
        return;
    }
    int mid = (l + r) / 2;
    down(id, l, r);

    update(id * 2, l, mid, u, v, val, type);
    update(id * 2 + 1, mid + 1, r, u, v, val, type);

    st[id].val = st[id * 2].val + st[id * 2 + 1].val;
    st[id].val %= mod;
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
int32_t main()
{
    // freopen("segtree_itmix.inp", "r", stdin);
    // freopen("segtree_itmix.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(1, 1, n, i, i, a[i], 3);
    }
    // for (int i = 1; i <= n; ++i)
    // cout << get(1, 1, n, i, i) << "\n";
    // for (int i = 1; i <= n * 4; ++i)
    //     cout << st[i].val << " " << st[i].mult << " " << st[i].cons << " " << st[i].add << "\n";
    while (q--)
    {
        int type;
        cin >> type;
        if (type <= 3)
        {
            int l, r, x;
            cin >> l >> r >> x;
            update(1, 1, n, l, r, x, type);
            // cout << get(1, 1, n, 1, n) << endl;
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << get(1, 1, n, l, r) << endl;
        }
        // if (type < 4)
        //     continue;
        // for (int i = 1; i <= n; ++i)
        //     cout << get(1, 1, n, i, i) << " ";
        // cout << "\n";
    }
}