#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 1;

int i, par[mxN], cnt[mxN], res[mxN];
map<int, int> mp[mxN];

int findp(int x)
{
    return (!(~par[x]) ? x : par[x] = findp(par[x]));
}

bool unite(int x, int y)
{
    x = findp(x);
    y = findp(y);
    if (x == y)
    {
        return false;
    }

    if (mp[x].size() < mp[y].size())
    {
        swap(x, y);
    }

    auto &X = mp[x];
    auto &Y = mp[y];
    par[y] = x;
    for (auto &z : Y)
    {
        auto it = X.find(z.first);
        if ((X[z.first] += z.second) == cnt[z.first] && it != X.end())
        {
            res[z.first] = i;
        }
    }

    Y.clear();

    return true;
}

int n, m, q;

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> q;
    memset(par, -1, sizeof(par));
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        x--;
        cnt[x]++;
        mp[i][x] = 1;
    }

    memset(res, -1, sizeof(res));
    for (int i = 0; i < m; i++)
    {
        if (cnt[i] == 1)
        {
            res[i] = 0;
        }
    }

    int x, y;
    for (i = 1; i <= q; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        unite(x, y);
    }

    for (int i = 0; i < m; i++)
    {
        cout << res[i] << "\n";
    }

    return 0;
}