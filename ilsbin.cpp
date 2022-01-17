#include <bits/stdc++.h>
#define int long long
#define II pair<int, int>
#define se second
#define fi first
using namespace std;
const int maxn = 1e4 + 1, N = 5001;
struct nodes
{
    int u, v;
    string st;
} query[maxn];

int col[maxn]; //, adj[N][N];
vector<int> gr[maxn];
set<int> s;
vector<int> v;
int rt[maxn];

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
    // gr[u].push_back(v);
    // gr[v].push_back(u);
    /*adj[u][v] = true;
    adj[v][u] = true;*/
    return true;
}

bool isBipartite()
{
    for (int i = 1; i <= v.size(); i++)
        col[i] = -1;
    queue<II> q;
    for (int i = 1; i <= v.size(); i++)
    {
        if (col[i] == -1)
        {
            q.push(II(i, 0));
            col[i] = 0;
            while (!q.empty())
            {
                II p = q.front();
                q.pop();
                int v = p.fi, c = p.se;
                for (auto j : gr[v])
                {
                    if (col[j] == c)
                        return false;
                    if (col[j] == -1)
                    {
                        if (c)
                            col[j] = 0;
                        else
                            col[j] = 1;
                        q.push(II(j, col[j]));
                    }
                }
            }
        }
    }
    return true;
}

bool ok(int key)
{
    for (int i = 1; i <= v.size(); i++)
        rt[i] = i, gr[i].clear();
    /*for (int i = 1; i <= v.size(); i++)
        for (int j = 1; j <= v.size(); j++)
            adj[i][j] = false;*/
    for (int i = 1; i <= key; i++)
    {
        if (query[i].st == "even")
        {
            int uu = lower_bound(v.begin(), v.end(), query[i].u) - v.begin() + 1;
            int vv = lower_bound(v.begin(), v.end(), query[i].v) - v.begin() + 1;
            join(uu, vv);
        }
    }
    for (int i = 1; i <= key; i++)
    {
        if (query[i].st == "odd")
        {
            int uu = lower_bound(v.begin(), v.end(), query[i].u) - v.begin() + 1;
            int vv = lower_bound(v.begin(), v.end(), query[i].v) - v.begin() + 1;
            uu = root(uu);
            vv = root(vv);
            if (uu == vv)
                return false;
            /*if (adj[uu][vv])
                return false;*/
            gr[uu].push_back(vv);
            gr[vv].push_back(uu);
        }
    }
    // return true;
    bool ans = isBipartite();
    return ans;
}
int32_t main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> query[i].u >> query[i].v >> query[i].st;
        query[i].u--;
        s.insert(query[i].u);
        s.insert(query[i].v);
    }
    for (auto val : s)
        v.push_back(val);
    int ans = 0;
    int l = 1, r = m;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (ok(mid))
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    cout << ans << endl;
}