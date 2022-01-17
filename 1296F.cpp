#include <bits/stdc++.h>
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Os")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#define int long long
using namespace std;
const int maxn = 5001, inf = 1e6;
vector<int> pa, gr[maxn];
int edge[maxn][maxn], st, f[maxn];

int dfs(int u, int p)
{
    if (u == st)
    {
        pa.push_back(edge[u][p]);
        return 1;
    }
    for (auto v : gr[u])
    {
        if (v == p)
            continue;
        if (dfs(v, u))
        {
            pa.push_back(edge[u][v]);
            return 1;
        }
    }
    return 0;
}

struct nodes
{
    int u, v, w;
    /* data */
};
nodes q[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
        edge[u][v] = i, edge[v][u] = i;
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> q[i].u >> q[i].v >> q[i].w;
        pa.clear();
        st = q[i].v;
        int t = dfs(q[i].u, 0);
        for (auto v : pa)
            f[v] = max(f[v], q[i].w);
    }
    for (int i = 1; i < n; i++)
        if (f[i] == 0)
            f[i] = inf;
    for (int i = 1; i <= m; i++)
    {
        pa.clear();
        st = q[i].v;
        int ans = inf;
        int t = dfs(q[i].u, 0);
        for (auto v : pa)
            ans = min(ans, f[v]);
        if (ans != q[i].w)
        {
            cout << -1 << '\n';
            return 0;
        }
    }
    for (int i = 1; i < n; i++)
        cout << f[i] << ' ';
}