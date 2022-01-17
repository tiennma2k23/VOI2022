// segtree quản lí số tập hợp ghép với nhau
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 1;
int a[maxn];
struct nodes
{
    int val, lazy = -1;
} st[4 * maxn];
void down(int id, int l, int r)
{
    int t = st[id].lazy;
    if (t == -1)
        return;
    int mid = (l + r) / 2;
    st[id * 2].val = t * (mid - l + 1);
    st[id * 2 + 1].val = t * (r - mid);

    st[id * 2].lazy = t;
    st[id * 2 + 1].lazy = t;

    st[id].lazy = -1;
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
    st[id].val = st[id * 2].val + st[id * 2 + 1].val;
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
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}
int32_t main()
{
    int n, q, pos = 0, sum = 0;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        update(1, 1, sum, pos + 1, pos + a[i] - 1, 1);
        pos += a[i];
    }
    while (q--)
    {
        char type;
        cin >> type;
        if (type == 'J')
        {
            int l, r;
            cin >> l >> r;
            update(1, 1, sum, l, r - 1, 1);
        }
        else if (type == 'D')
        {
            int l, r;
            cin >> l >> r;
            update(1, 1, sum, l, r - 1, 0);
        }
        else
        {
            cout << sum - get(1, 1, sum, 1, sum) << endl;
        }
    }
}
FO7yWUHp