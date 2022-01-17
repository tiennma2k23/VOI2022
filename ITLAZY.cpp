#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 1, inf = (1ll << 31) - 1;
struct Node
{
    int lazy = -inf;
    int val;
} st[maxn * 4];
void down(int id, int l, int r)
{
    int t = st[id].lazy;
    if (t == -inf)
        return;
    int mid = (l + r) / 2;
    st[id * 2].lazy = t;
    st[id * 2].val = t * (mid - l + 1);

    st[id * 2 + 1].lazy = t;
    st[id * 2 + 1].val = t * (r - mid);

    st[id].lazy = -inf;
}
void update(int id, int l, int r, int u, int v, int val)
{
    if (v < l || r < u)
    {
        return;
    }
    if (u <= l && r <= v)
    {
        st[id].val = val * (r - l + 1);
        st[id].lazy = val;
        return;
    }
    int mid = (l + r) / 2;

    down(id, l, r);

    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);

    st[id].val = (st[id * 2].val + st[id * 2 + 1].val);
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

    return (get(id * 2, l, mid, u, v) +
            get(id * 2 + 1, mid + 1, r, u, v));
}
int32_t main()
{
    int n;
    cin >> n;
    n++;
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 0)
        {
            int l, r, x;
            cin >> l >> r >> x;
            l++, r++;
            update(1, 1, n, l, r, x);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l++;
            r++;
            cout << get(1, 1, n, l, r) << endl;
        }
    }
}