#include <bits/stdc++.h>
#define offbit(n, i) (n ^ (1 << i))
using namespace std;
using namespace std;
const int maxn = 1e5 + 5, maxm = 35;
int n, gr[maxn], cnt, ans;
long long a[maxn], b[maxn];
int Prime[] = {2, 3, 5, 7, 11};
int fen[maxm][maxn];
void update(int id, int pos, int val)
{
    int tmp = pos;
    while (tmp < maxn)
    {
        fen[id][tmp] = max(fen[id][tmp], val);
        tmp += (tmp & (-tmp));
    }
}
int get(int id, int pos)
{
    int tmp = pos, res = 0;
    while (tmp > 0)
    {
        res = max(res, fen[id][tmp]);
        tmp -= (tmp & (-tmp));
    }
    return res;
}
int ok(int mask1, int mask2)
{
    for (int i = 0; i < 5; i++)
    {
        if ((mask2 & (1 << i)) && (mask1 & (1 << i)))
            return false;
    }
    return true;
}
set<long long> st;
void compress()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        st.insert(a[i]);
    for (auto j : st)
        b[++cnt] = j;
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(b + 1, b + cnt + 1, a[i]) - b;
}
int32_t main(int argc, char const *argv[])
{
#define TASK "coprime"
    // freopen(TASK ".inp", "r", stdin);
    // freopen(TASK ".out", "w", stdout);
    /* code */
    // int n;
    // cin >> n;
    // for (int i = 1; i <= n; i++)
    //     cin >> a[i];
    // a[0] = 1;
    // for (int i = 1; i <= n; i++)
    // {
    //     f[i] = 1;
    //     for (int j = 1; j < i; j++)
    //         if (__gcd(a[i], a[j]) == 1 && a[i] > a[j])
    //             f[i] = max(f[i], f[j] + 1);
    //     ans = max(ans, f[i]);
    // }
    // cout << ans << endl;
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int j = 0; j < 5; j++)
            gr[i] += (1 << j) * (a[i] % Prime[j] == 0);
    }
    compress();
    int sz = 1 << 5;
    for (int i = 1; i <= n; i++)
    {
        int u = gr[i];
        for (int j = 0; j < 5; j++)
            u = offbit(u, j);
        int tmp = 1;
        for (int j = u; true; j = (j - 1) & u)
        {
            tmp = max(tmp, get(j, a[i] - 1) + 1);
            if (j == 0)
                break;
        }
        // int pos = lower_bound(ve[gr[i]].begin(), ve[gr[i]].end(), a[i]) - ve[gr[i]].begin();
        update(gr[i], a[i], tmp);
        ans = max(ans, tmp);
        // cout << res << endl;
    }
    cout << ans << endl;

    return 0;
}
