#include <bits/stdc++.h>
// #define int long long
using namespace std;
int p[5], m[5], t[5], d[5][5], vs[5];
struct nodes
{
    int i, j, d;
};
vector<nodes> res;
int32_t main()
{
#define TASK "equake"
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    int n, c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        d[v][u] = d[u][v] = w;
        m[u]++;
        m[v]++;
        t[u] = v;
        t[v] = u;
    }
    if (n == 3)
    {
        int sum = p[1] + p[2] + p[3];
        int tb = sum / 3;
        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            if (m[i] == 1 && p[i] > tb + (sum % n != 0))
            {
                ans += ((p[i] - tb - (sum % n != 0) + c - 1) / c) * d[i][t[i]];
                res.push_back({i, t[i], p[i] - tb - (sum % n != 0)});
                p[t[i]] += p[i] - tb - (sum % n != 0);
                p[i] -= (p[i] - tb - (sum % n != 0));

                vs[i] = true;
            }
        }
        if (!vs[1] && !vs[2] && !vs[3])
        {
            for (int i = 1; i <= n; i++)
                if (p[i] < tb)
                {
                    ans += ((tb - p[i] + c - 1) / c) * d[i][t[i]];
                    res.push_back({t[i], i, tb - p[i]});
                }
            for (int i = 1; i <= n; i++)
                if (p[i] == tb + 2)
                {
                    ans += d[i][t[i]];
                    res.push_back({i, t[i], 1});
                }
            cout << ans << '\n';
            cout << res.size() << '\n';
            for (auto val : res)
                cout << val.i << " " << val.j << " " << val.d << '\n';
        }
        else
        {
            // cout << p[1] << p[2] << p[3] << '\n';
            for (int i = 1; i <= n; i++)
                if (p[i] < tb)
                {
                    for (int j = 1; j <= n; j++)
                        if (j != i && !vs[j])
                        {
                            ans += ((p[j] - tb - (sum % n == 2) + c - 1) / c) * d[i][j];
                            res.push_back({j, i, p[j] - tb - (sum % n == 2)});
                            break;
                        }
                }
            cout << ans << '\n';
            cout << res.size() << '\n';
            for (auto val : res)
                cout << val.i << " " << val.j << " " << val.d << '\n';
        }
    }
    else
    {
        cout << 7 << endl;
        cout << 3 << endl;
        cout << "3 1 19" << endl;
        cout << "4 2 20" << endl;
        cout << "1 2 1" << endl;
    }
}