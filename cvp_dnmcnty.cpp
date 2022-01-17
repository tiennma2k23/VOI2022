#include <bits/stdc++.h>
#define int long long
#define II pair<int, int>
#define fi first
#define se second
using namespace std;
const int maxn = 2e5 + 1, inf = 1e9 + 1;
int n, m, k;
set<int> gr[maxn];
set<II> bridge;
namespace sub1
{
    int vs[maxn];
    int cnt = 0;
    void dfs(int u)
    {
        vs[u] = true;
        for (auto v : gr[u])
            if (!vs[v])
                dfs(v);
    }

    void dfs()
    {
        for (int i = 1; i <= n; i++)
            if (vs[i] == 0)
            {
                cnt++;
                dfs(i);
            }
    }

    void reset()
    {
        bridge.clear();
        cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            vs[i] = 0;
        }
    }

    void solve()
    {
        reset();
        dfs();
        cout << cnt << ' ';
        for (int i = 1; i <= k; i++)
        {
            int type, u, v;
            cin >> type >> u >> v;
            if (type == 1)
            {
                gr[u].insert(v);
                gr[v].insert(u);
                reset();
                dfs();
                cout << cnt << ' ';
            }
            else
            {
                auto it = gr[u].find(v);
                if (it == gr[u].end())
                {
                    cout << cnt << ' ';
                    continue;
                }
                else
                {
                    gr[u].erase(gr[u].find(v));
                    gr[v].erase(gr[v].find(u));
                    reset();
                    dfs();
                    cout << cnt << ' ';
                }
            }
        }
    }
}
namespace sub2
{
    int num[maxn], low[maxn], parent[maxn];
    int step = 0, cnt = 0;
    void dfs(int u)
    {
        num[u] = ++step;
        low[u] = inf;

        for (int v : gr[u])
            if (v == parent[u])
                continue;
            else if (num[v] > 0)
                low[u] = min(low[u], num[v]);
            else
            {
                parent[v] = u;
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
    }

    void dfs()
    {
        for (int i = 1; i <= n; i++)
            if (num[i] == 0)
            {
                parent[i] = -1;
                cnt++;
                dfs(i);
            }
    }

    void reset()
    {
        cnt = 0;
        step = 0;
        for (int i = 1; i <= n; i++)
        {
            num[i] = 0;
        }
    }
    void findbridge()
    {
        for (int v = 1; v <= n; v++)
        {
            int u = parent[v];
            if (u == -1)
                continue;
            if (low[v] >= num[v])
                bridge.insert(II(min(u, v), max(u, v)));
        }
    }
    void solve()
    {
        reset();
        dfs();
        cout << cnt << ' ';
        for (int i = 1; i <= k; i++)
        {
            int type, u, v;
            cin >> type >> u >> v;
            if (type == 1)
            {
                gr[u].insert(v);
                gr[v].insert(u);
                reset();
                dfs();
                findbridge();
                cout << cnt << ' ';
            }
            else
            {
                auto it = gr[u].find(v);
                if (it == gr[u].end())
                {
                    cout << cnt << ' ';
                    continue;
                }
                else
                {
                    if (bridge.find(II(min(u, v), max(u, v))) != bridge.end())
                    {
                        cnt++;
                        bridge.erase(bridge.find(II(min(u, v), max(u, v))));
                    }
                    gr[u].erase(gr[u].find(v));
                    gr[v].erase(gr[v].find(u));
                    // reset();
                    // dfs();
                    cout << cnt << ' ';
                }
            }
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        gr[u].insert(v);
        gr[v].insert(u);
    }
    if (n <= 5000 && m <= 5000 && k <= 5000)
        sub1::solve();
    else
        sub2::solve();
}