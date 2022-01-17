#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
const int maxn = 1e5 + 123;
int t, n, ans[maxn], cahchs[maxn];
vector<pair<int, int>> gr[maxn];
void dfs(int u, int p)
{
    for (auto val : gr[u])
    {
        if (val.fi == p)
            continue;
        if (!cahchs[u])
        {
            ans[val.se] = 2;
            cahchs[u] = 1;
            cahchs[val.fi] = 1;
        }
        else
            ans[val.se] = 3;
        dfs(val.fi, u);
    }
}
void solve()
{
    cin >> n;
    int ck = 1;
    for (int i = 1; i <= n; i++)
        gr[i].clear();
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        gr[a].push_back({b, i});
        gr[b].push_back({a, i});
    }
    for (int i = 1; i <= n; i++)
    {
        if (gr[i].size() >= 3)
            ck = 0;
    }

    for (int i = 0; i <= n; i++)
        cahchs[i] = 0;
    if (!ck)
    {
        cout << "-1" << '\n';
        return;
    }
    dfs(1, 0);
    for (int i = 1; i < n; i++)
        cout << ans[i] << " ";
    cout << '\n';
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int q;
    cin >> q;
    while (q--)
    {
        solve();
    }
}