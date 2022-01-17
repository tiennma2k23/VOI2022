#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 1;
int zero;
int cnt1[31][31], par[maxn], cnt[31], a[maxn];
void update(int x, int val)
{
    for (int i = 0; i <= 30; ++i)
        cnt[i] += val * ((x >> i) & 1);
    for (int i = 0; i <= 30; ++i)
        for (int j = i + 1; j <= 30; ++j)
            if (((x >> i) & 1) && ((x >> j) & 1))
                cnt1[i][j] += val;

    if (x == 0)
        zero += val;
}
int find(int u)
{
    return (par[u] < 0 ? u : par[u] = find(par[u]));
}
void join(int u, int v)
{
    u = find(u), v = find(v);
    if (u == v)
        return;
    if (par[u] < par[v])
        swap(u, v);
    par[u] += par[v];
    par[v] = u;
}
int calc()
{
    for (int i = 0; i <= 30; ++i)
        par[i] = -1;

    for (int i = 0; i <= 30; ++i)
        for (int j = i + 1; j <= 30; ++j)
            if (cnt1[i][j])
                join(i, j);

    int ans = 0;
    for (int i = 0; i <= 30; ++i)
        if (cnt[i] && par[i] < 0)
            ans++;
    return ans + zero;
}
int32_t main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(a[i], 1);
    }
    int q;
    cin >> q;
    while (q--)
    {
        char ch;
        cin >> ch;
        if (ch == '!')
        {
            int x, y;
            cin >> x >> y;
            update(a[x], -1);
            a[x] = y;
            update(a[x], 1);
        }
        else
            cout << calc() << endl;
    }
    /* code */
    return 0;
}
