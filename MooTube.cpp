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
#include <bits/stdc++.h>
#pragma region
#pragma endregion
using namespace std;
const int maxn = 2e5 + 1;
int par[maxn], sz[maxn], ans[maxn];
struct edge
{
    int u, v, w;
};
edge a[maxn];
bool cmp(edge x, edge y)
{
    return x.w > y.w;
}
struct query
{
    int k, u, id; /* data */
};
query b[maxn];
bool cmp2(query x, query y)
{
    return x.k > y.k;
}
int _find(int u)
{
    if (u == par[u])
        return u;
    else
        return (par[u] = _find(par[u]));
}
void join(int u, int v)
{
    u = _find(u), v = _find(v);
    if (u == v)
        return;
    if (sz[u] > sz[v])
        swap(u, v);
    sz[u] += sz[v];
    par[v] = u;
}
int32_t main()
{
#define TASK "mootube"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        par[i] = i, sz[i] = 1;
    for (int i = 1; i < n; i++)
    {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= q; i++)
    {
        cin >> b[i].k >> b[i].u;
        b[i].id = i;
    }
    sort(b + 1, b + 1 + q, cmp2);
    int l = 1;
    for (int i = 1; i <= q; i++)
    {
        if (b[i].k != b[i - 1].k)
        {
            while (l <= n && a[l].w >= b[i].k)
            {
                join(a[l].u, a[l].v);
                l++;
            }
        }
        int rt = _find(b[i].u);
        ans[b[i].id] = sz[rt] - 1;
    }
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
}