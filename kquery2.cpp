#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 1, maxn = 3e4 + 1;
int fen[200][N], a[maxn], cnt[N][200];
void update(int id, int p, int val)
{
    while (id < 200)
    {
        int tmp = p;
        while (p > 0)
        {
            fen[id][p] += val;
            p -= (p & (-p));
        }
        p = tmp;
        id += id & (-id);
    }
}

int get(int id, int p)
{
    int res = 0;
    while (id > 0)
    {
        int tmp = p;
        while (p < N)
        {
            res += fen[id][p];
            p += (p & (-p));
        }
        p = tmp;
        id -= id & (-id);
    }
    return res;
}

int32_t main()
{
    int n;
    cin >> n;
    int m = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(i / m + (i % m != 0), a[i], 1);
        // update_cnt(a[i], i / m + (i % m != 0), 1);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 0)
        {
            int i, v;
            cin >> i >> v;
            update(i / m + (i % m != 0), a[i], -1);
            // update_cnt(a[i], i / m + (i % m != 0), -1);
            update(i / m + (i % m != 0), v, 1);
            // update_cnt(v, i / m + (i % m != 0), 1);
            a[i] = v;
        }
        else
        {
            int ans = 0;
            int l, r, k;
            cin >> l >> r >> k;
            int lo = l / m + (l % m != 0), hi = r / m + (r % m != 0);
            if (lo == hi)
            {
                for (int i = l; i <= r; i++)
                    ans += (a[i] > k);
            }
            else
            {
                for (int i = l; i <= lo * m; i++)
                    ans += (a[i] > k);

                for (int i = (hi - 1) * m + 1; i <= r; i++)
                    ans += (a[i] > k);

                ans += get(hi, k + 1) - get(lo - 1, k + 1);
            }
            cout << ans << endl;
        }
    }
}