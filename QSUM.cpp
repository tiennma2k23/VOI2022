#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 1;
int a[maxn], fen[maxn];
void update(int p, int val)
{
    int tmp = p;
    while (tmp < maxn)
    {
        fen[tmp] += val;
        tmp += (tmp & (-tmp));
    }
}
int get(int p)
{
    int tmp = p, res = 0;
    while (tmp)
    {
        res += fen[tmp];
        tmp -= (tmp & (-tmp));
    }
    return res;
}
int32_t main()
{
    // freopen("input", "r", stdin);
    // freopen("output", "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(i, a[i]);
    }
    while (q--)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
        {
            update(l, r - a[l]);
            a[l] = r;
        }
        else
            cout << get(r) - get(l - 1) << endl;
    }
}