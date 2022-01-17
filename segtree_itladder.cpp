#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 1, mod = 1e9 + 7;
struct nodes
{
    int val = 0, adda = 0, addb = 0, sub = 0;
};
nodes st[maxn * 4];
void down(int id, int l, int r)
{
    if (l == r)
        return;
    int t = st[id].adda;
    if (t != 0)
    {

        int mid = (l + r) / 2;

        (st[id * 2].adda += t) %= mod;
        (st[id * 2].val += t * ((mid + l) * (mid - l + 1) / 2 % mod)) % mod;

        (st[id * 2 + 1].adda += t) %= mod;
        (st[id * 2 + 1].val += t * ((mid + 1 + r) * (r - mid) / 2 % mod)) % mod;

        st[id].adda = 0;
    }

    t = st[id].addb;
    if (t != 0)
    {
        int mid = (l + r) / 2;

        (st[id * 2].addb += t) %= mod;
        (st[id * 2].val += t * (mid - l + 1)) % mod;

        (st[id * 2 + 1].addb += t) %= mod;
        (st[id * 2 + 1].val += t * (r - mid)) % mod;

        st[id].addb = 0;
    }

    t = st[id].sub;
    if (t != 0)
    {
        int mid = (l + r) / 2;

        (st[id * 2].sub += t) %= mod;
        st[id * 2].val -= (t * (mid - l + 1) % mod) % mod;
        st[id * 2].val += mod;
        st[id * 2].val %= mod;

        (st[id * 2 + 1].sub += t) %= mod;
        st[id * 2 + 1].val -= (t * (r - mid) % mod) % mod;
        st[id * 2 + 1].val += mod;
        st[id * 2 + 1].val %= mod;
        st[id].sub = 0;
    }
}
void update(int id, int l, int r, int u, int v, int a, int b)
{
    if (v < l || r < u)
    {
        return;
    }
    if (u <= l && r <= v)
    {
        (st[id].adda += a) %= mod;
        (st[id].addb += b) %= mod;
        (st[id].sub += u * a) %= mod;
        // ((st[id].val += (((r + l) * (r - l + 1) / 2 % mod) * a) % mod + ((r - l + 1) * b) % mod) += mod) %= mod;
        ((st[id].val += (((r + l) * (r - l + 1) / 2 % mod) * a) % mod - ((u * (r - l + 1) % mod) * a) % mod + ((r - l + 1) * b) % mod) += mod) %= mod;
        return;
    }
    int mid = (l + r) / 2;
    down(id, l, r);
    update(id * 2, l, mid, u, v, a, b);
    update(id * 2 + 1, mid + 1, r, u, v, a, b);
    st[id].val = (st[id * 2 + 1].val + st[id * 2].val) % mod;
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
    // freopen("input", "r", stdin);
    // freopen("output", "w", stdout);
    int n, q;
    cin >> n >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r, a, b;
            cin >> l >> r >> a >> b;
            update(1, 1, n, l, r, a, b);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << get(1, 1, n, l, r) << endl;
        }
        // for (int i = 1; i <= n; i++)
        // {
        //     cout << get(1, 1, n, i, i) << endl;
        // }
    }
}