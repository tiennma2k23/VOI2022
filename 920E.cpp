#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 1;
vector<int> gr[maxn];
set<int> unvisit;
int vs[maxn];
int sz;
void dfs(int u)
{
    sz++;
    vs[u] = true;
    unvisit.erase(unvisit.find(u));
    auto it = unvisit.begin();
    while (it != unvisit.end())
    {
        int v = *it;
        if (!binary_search(gr[u].begin(), gr[u].end(), v))
            dfs(v);
        it = unvisit.upper_bound(v);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> vec;
    int n, m, cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        unvisit.insert(i);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        sort(gr[i].begin(), gr[i].end());
    for (int i = 1; i <= n; i++)
        if (!vs[i])
        {
            cnt++;
            sz = 0;
            dfs(i);
            vec.push_back(sz);
        }
    cout << cnt << endl;
    sort(vec.begin(), vec.end());
    for (auto val : vec)
        cout << val << ' ';
}