#include <bits/stdc++.h>
#define int int
#define nodes tuple<int, int, int>
using namespace std;
const int maxn = 1e5 + 1, inf = 1e9;
int n, m, d;
namespace sub1
{
    vector<int> gr[maxn];
    int w[1001][1001], vs[1001][1001], f[1001][1001];
    void solve()
    {
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v >> w[u][v];
            w[v][u] = w[u][v];
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] = inf;

        priority_queue<nodes, vector<nodes>, greater<nodes>> pq;
        pq.push(make_tuple(0, 1, 1));
        int ans = -1;
        while (pq.size())
        {
            int dis, u, last;
            tie(dis, u, last) = pq.top();
            pq.pop();
            if (u == n)
            {
                ans = dis;
                break;
            }
            if (vs[u][last])
                continue;
            vs[u][last] = 1;
            for (auto v : gr[u])
            {
                if (w[u][last] + d <= w[v][u] && dis + w[v][u] < f[v][u])
                {
                    f[v][u] = dis + w[v][u];
                    pq.push(make_tuple(f[v][u], v, u));
                }
            }
        }
        cout << ans << endl;
    }
}
namespace sub2
{
#define II pair<int, int>
    vector<II> gr[maxn];
    void solve()
    {
        while (m--)
        {
            int u, v, c;
            cin >> u >> v >> c;
            gr[u].push_back({c, v});
            gr[v].push_back({c, u});
        }
        for (int u = 1; u <= n; u++)
            sort(gr[u].begin(), gr[u].end());
        priority_queue<nodes, vector<nodes>, greater<nodes>> pq;
        pq.push(make_tuple(0, -inf, 1));
        int ans = -1;
        while (pq.size())
        {
            int dis;
            int last, u;
            tie(dis, last, u) = pq.top();
            pq.pop();
            if (u == n)
            {
                ans = dis;
                break;
            }
            while (!gr[u].empty())
            {
                int c, v;
                tie(c, v) = gr[u].back();
                if (c < last + d)
                    break;
                gr[u].pop_back();
                pq.push(make_tuple(dis + c, c, v));
            }
        }
        cout << ans << endl;
    }
}
int32_t main()
{
    // freopen("input", "r", stdin);
    // freopen("output", "w", stdout);
    cin >> n >> m >> d;
    if (m <= 1000)
        sub1::solve();
    else
        sub2::solve();
}