#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 1;
int nnext[maxn], a[maxn], f[maxn], pre[maxn], dp[maxn], maxx[maxn];
unordered_map<int, int> last;
int ST[4 * maxn];
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

    ST[id] = max(ST[id * 2], ST[id * 2 + 1]);
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
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
vector<int> v;
void trace(int i)
{
    if (dp[i] == 4)
    {
        v.push_back(a[f[i]]);
        v.push_back(a[i]);
        v.push_back(a[f[i]]);
        v.push_back(a[i]);
        return;
    }
    for (int j = f[i] - 1; j >= 0; j--)
    {
        if (dp[j] + 4 == dp[i])
        {
            trace(j);
            v.push_back(a[f[i]]);
            v.push_back(a[i]);
            v.push_back(a[f[i]]);
            v.push_back(a[i]);
            return;
        }
    }
}
int32_t main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = n; i >= 1; i--)
    {
        nnext[i] = last[a[i]];
        last[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        last[a[i]] = 0;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = last[a[i]];
        f[i] = pre[pre[pre[i]]];
        last[a[i]] = i;
    }
    // cout << f[6] << endl;
    for (int i = 1; i <= n; i++)
    {
        if (nnext[i])
        {
            update(1, 1, n, nnext[i], i);
            f[nnext[i]] = max(f[nnext[i]], get(1, 1, n, i + 1, nnext[i] - 1));
        }
    }
    // for (int i = 1; i <= n; i++)
    // cout << f[i] << ' ' << pre[i] << endl;

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (f[i])
        {
            dp[i] = maxx[f[i] - 1] + 4;
        }
        maxx[i] = max(maxx[i - 1], dp[i]);
        ans = max(ans, dp[i]);
        // cout << i << ' ' << f[i] << ' ' << dp[i] << endl;
    }
    cout << ans << endl;
    for (int i = n; i >= 1; i--)
    {
        if (dp[i] == ans)
        {
            trace(i);
            break;
        }
    }
    // reverse(v.begin(), v.end());
    for (auto val : v)
        cout << val << ' ';
}