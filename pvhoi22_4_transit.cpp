
#include <bits/stdc++.h>
#define int long long
#define II pair<int, int>
using namespace std;
const int maxn = 2e3 + 1;
int n, m, q;
int d[maxn][maxn], vs[maxn], f[30];
void sub1()
{
    for (int i = 1; i <= m; i++)
    {
        vs[f[i]] = true;
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        int ans = m + 2;
        ans -= vs[x];
        ans -= vs[y];
        cout << ans << ' ';
    }
}
const int inf = 1e9 + 1;
int dist[maxn][maxn];
void dijkstra(int u, int *ddd)
{
    priority_queue<II, vector<II>, greater<II>> pq;
    for (int i = 1; i <= n; i++)
        ddd[i] = inf;
    ddd[u] = 0;
    pq.push(II(0, u));

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
            }
        }
    }
}

void sub2()
{
    vector<int> vec;
    for (int i = 1; i <= m; i++)
    {
        vec.push_back(f[i]);
    }
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        int ans = inf;
        do
        {
            int res = dist[u][vec[0]];
            res += dist[vec[m - 1]][v];
            for (int i = 1; i < vec.size(); i++)
                res += dist[vec[i - 1]][vec[i]];
            ans = min(ans, res);
            /* code */
        } while (next_permutation(vec.begin(), vec.end()));
        cout << ans << ' ';
    }
}
int dd[maxn], dd1[maxn];
bool cmp(int x, int y)
{
    if (dist[x][y] == dist[y][x])
        return dd[x] < dd[y];
    return (dist[x][y] < dist[y][x]);
}

bool cmp1(int x, int y)
{
    if (dd[x] != dd[y])
        return dd[x] < dd[y];
    return (dist[x][y] < dist[y][x]);
}

bool cmp2(int x, int y)
{
    if (dd1[x] != dd1[y])
        return dd1[x] > dd1[y];
    return (dist[x][y] < dist[y][x]);
}

bool cmp3(int x, int y)
{
    if (dist[x][y] == dist[y][x])
        return dd1[x] > dd1[y];
    return (dist[x][y] < dist[y][x]);
}
void turtle()
{
    vector<int> vec;
    for (int i = 1; i <= m; i++)
    {
        vec.push_back(f[i]);
    }
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        int ans = inf;
        for (auto val : vec)
            dd[val] = dist[u][val], dd1[val] = dist[val][v];
        sort(vec.begin(), vec.end(), cmp);
        int res = dist[u][vec[0]];
        res += dist[vec[m - 1]][v];
        for (int i = 1; i < vec.size(); i++)
            res += dist[vec[i - 1]][vec[i]];
        ans = min(ans, res);

        sort(vec.begin(), vec.end(), cmp1);
        res = dist[u][vec[0]];
        res += dist[vec[m - 1]][v];
        for (int i = 1; i < vec.size(); i++)
            res += dist[vec[i - 1]][vec[i]];
        ans = min(ans, res);

        sort(vec.begin(), vec.end(), cmp2);
        res = dist[u][vec[0]];
        res += dist[vec[m - 1]][v];
        for (int i = 1; i < vec.size(); i++)
            res += dist[vec[i - 1]][vec[i]];
        ans = min(ans, res);

        sort(vec.begin(), vec.end(), cmp3);
        res = dist[u][vec[0]];
        res += dist[vec[m - 1]][v];
        for (int i = 1; i < vec.size(); i++)
            res += dist[vec[i - 1]][vec[i]];
        ans = min(ans, res);

        cout << ans << ' ';
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> q;
    bool ok = true;
    for (int i = 1; i <= m; i++)
        cin >> f[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> d[i][j];
            if (d[i][j] > 1)
                ok = false;
        }
    for (int i = 1; i <= n; i++)
        dijkstra(i, dist[i]);
    if (ok)
        sub1();
    else if (m <= 6)
        sub2();
    else
        turtle();
}