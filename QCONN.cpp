#include <bits/stdc++.h>
#define int long long
#define II pair<int, int>
#define iII pair<int, II>
#define x first
#define y second
using namespace std;
const int maxn = 1e3 + 1, inf = 1e18 + 1;
II b[maxn];
int rt[maxn], n, q;
struct nodes
{
    int c, w;
    vector<int> vec;
} a[10];

bool cmp(nodes x, nodes y)
{
    if (x.w == y.w)
        return x.c > y.c;
    return x.w < y.w;
}
int root(int u)
{
    if (u == rt[u])
        return u;
    return (rt[u] = root(rt[u]));
}

bool join(int u, int v)
{
    u = root(u);
    v = root(v);
    if (u == v)
        return false;
    rt[u] = v;
    return true;
}

bool chec(int u, int v)
{
    u = root(u);
    v = root(v);
    if (u == v)
        return false;
    return true;
}
int dist(II a, II b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
vector<iII> v;
int calc(int x)
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
        rt[i] = i;
    for (int i = 0; i < q; i++)
    {
        if (x & (1 << i))
        {
            int j = i + 1, res = 0;
            for (int i1 = 2; i1 <= a[j].c; i1++)

                if (join(a[j].vec[i1], a[j].vec[i1 - 1]))
                {
                    res += dist(b[a[j].vec[i1]], b[a[j].vec[i1 - 1]]);
                }

            ans += min(a[j].w, res);
        }
    }

    for (auto val : v)
    {
        if (join(val.y.x, val.y.y))
            ans += val.x;
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> a[i].c >> a[i].w;
        a[i].vec.resize(a[i].c + 1);
        for (int j = 1; j <= a[i].c; j++)
            cin >> a[i].vec[j];
    }
    sort(a + 1, a + 1 + q, cmp);
    for (int i = 1; i <= n; i++)
        cin >> b[i].x >> b[i].y;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            v.push_back(iII(dist(b[i], b[j]), II(i, j)));
        }
    }
    sort(v.begin(), v.end());
    int ans = inf, sz = 1 << q;
    for (int mask = 0; mask < sz; mask++)
    {
        ans = min(ans, calc(mask));
        // cout << ans << ' ' << mask << ' ' << calc(mask) << endl;
    }

    cout << ans << endl;
}