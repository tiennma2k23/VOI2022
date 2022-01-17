#pragma GCC optimize("Os")
#include <bits/stdc++.h>
#define int long long
#define II pair<int, int>
#define fi first
#define se second
using namespace std;
const int maxn = 3500, N = 25 * 1e4 + 1, inf = 1e18;
int d[maxn][maxn], x[N];
int n, m, q;
vector<II> gr[N];
void dijkstra(int u, int *d)
{
    priority_queue<II, vector<II>, greater<II>> pq;
    for (int i = 1; i <= m * n; i++)
        d[i] = inf;
    d[u] = x[u];
    pq.push(II(d[u], u));

    while (pq.size())
    {
        int u = pq.top().se;
        int du = pq.top().fi;
        pq.pop();
        if (du != d[u])
            continue;

        for (int i = 0; i < gr[u].size(); i++)
        {
            int v = gr[u][i].fi;
            int uv = gr[u][i].se;
            if (d[v] > du + uv)
            {
                d[v] = du + uv;
                pq.push(II(d[v], v));
            }
        }
    }
}
int Hash(int i, int j) { return (i - 1) * n + j; }
void prepare()
{
    for (int i = 1; i <= (m * n); i++)
    {
        dijkstra(i, d[i]);
    }
}

namespace sub1
{
    void solve()
    {
        while (q--)
        {
            int x, y, u, v;
            cin >> x >> y >> u >> v;
            dijkstra(Hash(x, y), d[Hash(x, y)]);
            cout << d[Hash(x, y)][Hash(u, v)] << '\n';
        }
    }
}

namespace sub2
{
    struct nodes
    {
        int x, y, u, v, id;
    } query[300005];
    int ans[30005];
    bool cmp(nodes a, nodes b)
    {
        if (a.x != b.x)
            return a.x < b.x;
        return a.y < b.y;
    }
    int f[3][5001];
    void prepare(int x1, int y1)
    {
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] = inf;
        f[x1][y1] = x[Hash(x1, y1)];
        f[3 - x1][y1] = f[x1][y1] + x[Hash(3 - x1, y1)];

        for (int j = y1 + 1; j <= n; j++)
        {
            f[1][j] = min(f[1][j], f[1][j - 1] + x[Hash(1, j)]);
            f[1][j] = min(f[1][j], f[2][j - 1] + x[Hash(2, j)] + x[Hash(1, j)]);

            f[2][j] = min(f[2][j], f[2][j - 1] + x[Hash(2, j)]);
            f[2][j] = min(f[2][j], f[1][j - 1] + x[Hash(1, j)] + x[Hash(2, j)]);
        }
    }
    void solve()
    {
        for (int i = 1; i <= q; i++)
        {
            int x, y, u, v;
            cin >> x >> y >> u >> v;
            if (y > v)
                swap(x, u), swap(y, v);
            query[i] = {x, y, u, v, i};
        }
        sort(query + 1, query + 1 + q, cmp);
        int pos = 0;
        for (int i = 1; i <= q; i++)
        {
            if (query[i].x != query[pos].x || query[pos].y != query[i].y)
                prepare(query[i].x, query[i].y), pos = i;
            ans[query[i].id] = f[query[i].u][query[i].v];
            // cout << ans[query[i].id] << endl;
        }
        for (int i = 1; i <= q; i++)
            cout
                << ans[i] << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            int a;
            cin >> a;
            if (i < m)
                gr[Hash(i + 1, j)].push_back({Hash(i, j), a});
            if (j < n)
                gr[Hash(i, j + 1)].push_back({Hash(i, j), a});
            if (i > 1)
                gr[Hash(i - 1, j)].push_back({Hash(i, j), a});
            if (j > 1)
                gr[Hash(i, j - 1)].push_back({Hash(i, j), a});
            x[Hash(i, j)] = a;
        }

    // prepare();
    cin >> q;
    if (q <= 500)
        sub1::solve();
    else
        sub2::solve();
}