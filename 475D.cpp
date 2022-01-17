#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 1;
int ST[4 * maxn];
int n, a[maxn];
unordered_map<int, int> cnt;
void update(int id, int l, int r, int i, int v)
{
    if (i < l || r < i)
    {
        return;
    }
    if (l == r)
    {
        ST[id] = v;
        return;
    }

    int mid = (l + r) / 2;
    update(id * 2, l, mid, i, v);
    update(id * 2 + 1, mid + 1, r, i, v);

    ST[id] = __gcd(ST[id * 2], ST[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return 0;
    }
    if (u <= l && r <= v)
    {
        return ST[id];
    }
    int mid = (l + r) / 2;
    return __gcd(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
void prepare()
{
    for (int i = 1; i <= n; i++)
    {
        int l = i;
        while (l > 0)
        {
            int val = get(1, 1, n, l, i);
            int lo = 1, hi = l, pos = 1;
            while (lo <= hi)
            {
                int mid = (lo + hi) / 2;
                int tmp = get(1, 1, n, mid, i);
                if (tmp >= val)
                    pos = mid, hi = mid - 1;
                else
                    lo = mid + 1;
            }
            cnt[val] += (l - pos + 1);
            l = pos - 1;
        }
        // for (int l = 1; l <= i; l++)
        // {
        //     int val = get(1, 1, n, l, i);
        //     cnt[val]++;
        // }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], update(1, 1, n, i, a[i]);
    prepare();
    // cout << cnt[110] << endl;
    int q;
    cin >> q;
    // cout << q << endl;
    while (q--)
    {
        int x;
        cin >> x;
        cout << cnt[x] << '\n';
    }
}