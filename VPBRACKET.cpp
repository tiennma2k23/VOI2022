#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 1, inf = 1e9 + 1;
int st[4 * maxn], a[maxn];
void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    st[id] = min(st[id * 2], st[id * 2 + 1]);
}
int get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return inf;
    }
    if (u <= l && r <= v)
    {
        return st[id];
    }
    int mid = (l + r) / 2;
    return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#define TASK "VPBRACKET"
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        if (ch == ')')
            a[i] = a[i - 1] - 1;
        else
            a[i] = a[i - 1] + 1;
    }
    for (int i = 0; i < 4 * maxn; i++)
        st[i] = inf;
    build(1, 1, n);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        if ((a[l] - a[l - 1] == 1) && (a[r - 1] - a[r] == 1))
        {
            if (a[r] - a[l - 1] == 0)
            {
                int tmp = get(1, 1, n, l, r);
                if (tmp >= a[l - 1])
                    cout << "YES" << '\n';
                else
                    cout << "NO" << '\n';
            }
            else
                cout << "NO" << '\n';
        }
        else
            cout << "NO" << '\n';
    }
}