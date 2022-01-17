#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 1, mod = 1e9 + 7;
int n, i, j, k, u, v;
int col[maxn], son[maxn], nxt[maxn];
int f[maxn], g[maxn];

void dfs(int x)
{
    if (col[x] == 0)
        f[x] = 1;
    else
        g[x] = 1;
    for (int i = son[x]; i; i = nxt[i])
    {
        dfs(i);
        g[x] = (g[x] * (f[i] + g[i]) % mod + f[x] * g[i]) % mod;
        f[x] = f[x] * (f[i] + g[i]) % mod;
    }
}

int32_t main()
{
    int n;
    cin >> n;
    for (i = 2; i <= n; i++)
    {
        int u;
        cin >> u;
        ++u;
        nxt[i] = son[u];
        son[u] = i;
    }
    for (i = 1; i <= n; i++)
        cin >> col[i];
    dfs(1);
    cout << g[1] << endl;
}