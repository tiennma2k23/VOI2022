#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 3e5 + 5, mod = 998244353;
vector<int> gr[maxn];
int a, b, _v[maxn], p[maxn];

bool dfs(int u)
{
    if (_v[u] == 1)
        a++;
    b++;
    for (auto v : gr[u])
    {
        if (_v[v] == _v[u])
            return false;
        if (!_v[v])
        {
            _v[v] = -_v[u];
            if (!dfs(v))
                return false;
        }
    }
    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen("input", "r", stdin);
    // freopen("output", "w", stdout);

    int t;
    p[0] = 1;
    for (int i = 1; i < maxn; i++)
        p[i] = p[i - 1] * 2 % mod;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            gr[i].clear();
            _v[i] = 0;
        }
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        int ans = 1;
        for (int i = 1; i <= n; i++)
        {
            if (!_v[i])
            {
                a = b = 0;
                _v[i] = 1;
                ans = ans * dfs(i) * (p[a] + p[b - a]) % mod;
            }
        }
        cout << ans << endl;
    }
}