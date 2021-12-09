#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

vector<int> gr[maxn], ans[2];

int vs[maxn];

void dfs(int u, int s)
{
    vs[u] = 1;
    ans[s].push_back(u);
    for (auto v : gr[u])
    {
        if (vs[v])
            continue;
        dfs(v, 1 - s);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout.tie(nullptr);
    // freopen("input", "r", stdin);
    // freopen("output", "w", stdout);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            vs[i] = false, gr[i].clear();
        ans[0].clear(), ans[1].clear();
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        dfs(1, 0);
        int flag = ans[0].size() > ans[1].size();
        cout << ans[flag].size() << endl;
        for (auto val : ans[flag])
            cout << val << " ";
        cout << endl;
    }
}
