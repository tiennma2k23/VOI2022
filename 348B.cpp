#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 1, inf = 1e18 + 1;
vector<int> gr[maxn];
int a[maxn], maxx = inf, sum = 0, q = 1;
void dfs(int u, int par, int d)
{
    q = q / __gcd(q, d) * d;
    if (d > sum || d < 0)
    {
        cout << sum << '\n';
        exit(0);
    }
    if (gr[u].size() == 1 && u > 1)
        maxx = min(maxx, d * a[u]);
    for (auto v : gr[u])
        if (v != par)
            dfs(v, u, d * (gr[u].size() - (u != 1)));
}
int32_t main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], sum += a[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    dfs(1, 0, 1);
    cout << sum - (maxx / q) * q << endl;
}