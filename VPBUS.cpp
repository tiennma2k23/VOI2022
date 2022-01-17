#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 5, inf = 1e9 + 1;
int fen[maxn], f[maxn];
void update(int p, int val)
{
    while (p < maxn)
    {
        fen[p] = max(fen[p], val);
        p += (p & (-p));
        /* code */
    }
}
int get(int p)
{
    int res = 0;
    while (p > 0)
    {
        res = max(res, fen[p]);
        p -= (p & (-p));
    }
    return res;
}
struct nodes
{
    int x, y, z;
} a[maxn];
bool cmp(nodes a, nodes b)
{
    if (a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#define TASK "VPBUS"
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);

    set<int> st;
    vector<int> v;
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= k; i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].z;
        st.insert(a[i].y);
    }
    for (auto val : st)
        v.push_back(val);
    sort(a + 1, a + 1 + k, cmp);
    int ans = -inf;
    for (int i = 1; i <= k; i++)
    {
        if (a[i].x <= n && a[i].y <= m)
        {
            auto pos = lower_bound(v.begin(), v.end(), a[i].y) - v.begin() + 1;
            f[i] = get(pos) + a[i].z;
            update(pos, f[i]);
            // cout << pos << endl;
        }

        ans = max(ans, f[i]);
        // cout << a[i].x << ' ' << f[i] << endl;
    }
    cout << ans << endl;
}