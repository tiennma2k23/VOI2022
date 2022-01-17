#include <bits/stdc++.h>
#define int long long
#define II pair<int, int>
#define fi first
#define se second
using namespace std;
const int maxn = 2000, inf = 1e9 + 1, mod = 1e9 + 7;
int dis[maxn][maxn], cnt[maxn][maxn], n, to[maxn][maxn], ans[5555], m;
struct nodes
{
    int v, w, id;
};

vector<nodes> gr[maxn];

struct Node
{
    int u, v, w;
} a[5555];
void dijkstra(int s)
{
    for (int i = 1; i <= n; i++)
        dis[s][i] = inf;
    dis[s][s] = 0;
    cnt[s][s] = 1;
    priority_queue<II, vector<II>, greater<II>> pq;
    pq.push(II(0, s));
    while (!pq.empty())
    {
        int u = pq.top().se, du = pq.top().fi;
        pq.pop();
        if (du != dis[s][u])
            continue;
        for (auto val : gr[u])
        {
            int uv = val.w, v = val.v;
            if (dis[s][v] > du + uv)
            {
                dis[s][v] = du + uv;
                cnt[s][v] = cnt[s][u];
                pq.push(II(dis[s][v], v));
            }
            else if (dis[s][v] == du + uv)
            {
                cnt[s][v] += cnt[s][u];
                cnt[s][v] %= mod;
            }
        }
    }
}

void calc(int s)
{
    vector<II> vec;
    for (int i = 1; i <= n; i++)
        vec.push_back(II(dis[s][i], i));
    sort(vec.begin(), vec.end());
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        if (vec[i].fi == inf)
            continue;
        int u = vec[i].se;
        to[s][u] = 1;
        for (auto val : gr[u])
        {
            int v = val.v, uv = val.w;
            if (dis[s][u] + uv == dis[s][v])
                to[s][u] = (to[s][u] + to[s][v]) % mod;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int u = a[i].u, v = a[i].v, w = a[i].w;
        if (dis[s][u] + w == dis[s][v])
        {
            (ans[i] += cnt[s][u] * to[s][v] % mod) %= mod;
        }
    }
}

int32_t main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        gr[u].push_back({v, w, i});
        // gr[v].push_back({u, w, i});
        a[i] = {u, v, w};
    }
    for (int i = 1; i <= n; i++)
        dijkstra(i);
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //         cout << cnt[i][j] << ' ';
    //     cout << endl;
    // }
    for (int i = 1; i <= n; i++)
        calc(i);
    for (int i = 1; i <= m; i++)
        cout << ans[i] << endl;
}