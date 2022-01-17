#include <bits/stdc++.h>
#define int long long
#define II pair<int, int>
using namespace std;
const int maxn = 110;
int dist[maxn], d[maxn][maxn], pre[maxn], ok[maxn][maxn], inf = 1e9 + 1;
int n, m, k;
void dijkstra(int u, int *ddd)
{
    priority_queue<II, vector<II>, greater<II>> pq;
    for (int i = 1; i <= n; i++)
        ddd[i] = inf;
    ddd[u] = 0;
    pq.push(II(0, u));
    pre[u] = 0;
    while (pq.size())
    {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du != ddd[u])
            continue;

        for (int v = 1; v <= n; v++)
        {
            if (v == u)
                continue;
            int uv = d[u][v];
            if (ddd[v] > du + uv)
            {
                ddd[v] = du + uv;
                pq.push(II(ddd[v], v));
                pre[v] = u;
            }
        }
    }
}
int32_t main()
{

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            d[i][j] = d[j][i] = inf;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        u++, v++;
        d[u][v] = 1, d[v][u] = 1;
    }
    for (int i = 1; i <= k; i++)
    {
        dijkstra(1, dist);
        int v = n;
        int minn = inf;
        II pos;
        while (v != 0)
        {
            int u = pre[v];
            if (!ok[u][v])
            {
                // minn = d[u][v];
                pos = {u, v};
            }
            v = u;
        }
        ok[pos.first][pos.second] = ok[pos.second][pos.first] = 1;
        d[pos.first][pos.second]++, d[pos.second][pos.first]++;
    }
    dijkstra(1, dist);
    cout << dist[n] << endl;
}