#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 1, inf = 1e9 + 1;
int fen[4 * maxn];
vector<int> v;
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
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k, q;
    cin >> n >> k >> q;
    while (n--)
    {
        int l, r;
        
        cin >> l >> r;
        // cout << l << ' ' << r << endl;
        update(1, 1, maxn - 1, l, r, 1);
    }
    for (int i = 1; i < maxn; i++)
    {
        if (get(1, 1, maxn - 1, i, i) >= k)
            v.push_back(i);
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int pos1 = lower_bound(v.begin(), v.end(), l) - v.begin();
        int pos2 = upper_bound(v.begin(), v.end(), r) - v.begin();
        cout << pos2 - pos1 << endl;
    }
}
