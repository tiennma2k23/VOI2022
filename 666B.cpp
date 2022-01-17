#include <bits/stdc++.h>
#define int long long
using namespace std;
#define II pair<int, int>
#define fi first
#define se second

const int maxn = 3e3 + 1, inf = 1e9 + 1;
vector<int> gr[maxn];
int dis[maxn][maxn], pre[maxn], suf[maxn];
int n;
vector<II> v1[maxn], v2[maxn], to[maxn], out[maxn];
void dijkstra(int s)
{
    for (int i = 1; i <= n; i++)
        dis[s][i] = inf;
    dis[s][s] = 0;
    priority_queue<II, vector<II>, greater<II>> pq;
    pq.push(II(0, s));
    while (!pq.empty())
    {
        int u = pq.top().se, du = pq.top().fi;
        pq.pop();
        if (du != dis[s][u])
            continue;
        for (auto v : gr[u])
        {
            if (dis[s][v] > du + 1)
            {
                dis[s][v] = du + 1;
                pq.push(II(dis[s][v], v));
            }
        }
    }
}
bool ok(int x, int y, int a, int b)
{
    vector<int> vec;
    vec.push_back(x);
    vec.push_back(y);
    vec.push_back(a);
    vec.push_back(b);
    sort(vec.begin(), vec.end());
    for (int i = 1; i < vec.size(); i++)
        if (vec[i] == vec[i - 1])
            return false;
    return true;
}
int32_t main()
{
    int m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
        dijkstra(i);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            if (dis[i][j] == inf)
                dis[i][j] = -inf;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // to[j] = max(to[j], dis[i][j]);
            // if (to[j] == dis[i][j])
            //     pre[j] = i;
            // out[i] = max(out[i], dis[i][j]);
            // if (out[i] == dis[i][j])
            //     suf[i] = j;
            v1[j].push_back({dis[i][j], i});
            v2[i].push_back({dis[i][j], j});
        }
    }
    for (int i = 1; i <= n; i++)
        sort(v1[i].rbegin(), v1[i].rend()), sort(v2[i].rbegin(), v2[i].rend());
    for (int i = 1; i <= n; i++)
    {
        to[i].push_back(v1[i][0]);
        for (int j = 1; j < v1[i].size(); j++)
        {
            // if (v1[i][j].fi != v1[i][j - 1].fi)
            to[i].push_back(v1[i][j]);
            if (to[i].size() == 5)
                break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        out[i].push_back(v2[i][0]);
        for (int j = 1; j < v2[i].size(); j++)
        {
            // if (v2[i][j].fi != v2[i][j - 1].fi)
            out[i].push_back(v2[i][j]);
            if (out[i].size() == 5)
                break;
        }
    }
    int ans = -inf, pos1, pos2, pos3, pos4;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            for (auto val : to[i])
                for (auto val1 : out[j])
                {
                    if (ans < val.fi + val1.fi + dis[i][j] && ok(i, j, val.se, val1.se))
                    {
                        ans = val.fi + val1.fi + dis[i][j];
                        pos1 = val.se, pos2 = i, pos3 = j, pos4 = val1.se;
                    }
                }
        }
    // cout << ans << endl;
    cout << pos1 << ' ' << pos2 << ' ' << pos3 << ' ' << pos4 << endl;
}