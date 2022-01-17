#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e3 + 5;
int depth[maxn], up[maxn][20];
vector<int> gr[maxn];
int n, k, a, b;
int dist[maxn][maxn], in[maxn];
int timer;
void dfs(int u, int *d, int par)
{
    in[u] = ++timer;
    for (auto v : gr[u])
        if (v != par)
        {
            d[v] = d[u] + 1;
            dfs(v, d, u);
        }
}

inline int _dist(int u, int v)
{
    return dist[u][v];
}
void sub1()
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            if (_dist(i, j) >= a && _dist(i, j) <= b)
                ans++;
        }
    cout << ans << endl;
}

void sub2()
{

    int ans = 0;
    for (int u = 1; u <= n; u++)
        for (int v = u + 1; v <= n; v++)
            for (int c = v + 1; c <= n; c++)
            {
                int kc = _dist(u, v) + _dist(u, c) + _dist(v, c);
                kc /= 2;
                // kc 3 đỉnh
                // kc--;
                // cout << u << ' ' << v << ' ' << c << ' ' << kc << endl;
                if (kc >= a && kc <= b)
                    ans++;
            }
    cout << ans << endl;
}

namespace sub3
{

    //    Cách tính lực lượng nhỏ nhất của tập đỉnh liên thông k đỉnh v1, v2, ..., vk
    //    - sắp xếp các điểm lại theo thứ tự thăm dfs
    //    - khoảng cách * 2 = _dist(v1, v2) + _dist(v2, v3) + ... + _dist(vk, v1) + 2

    bool cmp(int u, int v)
    {
        return in[u] < in[v];
    }

    void solve()
    {
        for (int i = 1; i <= n; ++i)
        {
            dfs(i, dist[i], -1);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                for (int k = j + 1; k <= n; k++)
                    for (int h = k + 1; h <= n; h++)
                    {
                        vector<int> vt = {i, j, k, h};
                        sort(vt.begin(), vt.end(), cmp);
                        vt.push_back(vt[0]);
                        int cur = 0;
                        for (int i = 0; i < vt.size() - 1; i++)
                        {
                            cur += dist[vt[i]][vt[i + 1]];
                        }
                        if (cur % 2)
                            continue;
                        cur /= 2;
                        if (cur >= a && cur <= b)
                        {
                            ans++;
                        }
                    }

        cout << ans << endl;
    }
}

int32_t main()
{
    cin >> n >> k >> a >> b;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        dfs(i, dist[i], 0);
    if (k == 2)
    {
        sub1();
    }
    else if (k == 3)
        sub2();
    else if (k == 4)
        sub3::solve();
}