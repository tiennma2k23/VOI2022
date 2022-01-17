#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 1;
int num[maxn], low[maxn], out[maxn], in[maxn], up[maxn][21];
vector<int> gr[maxn];
int n, m, cnt;
void tarjan(int u, int p)
{
    in[u] = ++cnt;
    num[u] = ++num[0];
    low[u] = n + 1;
    up[u][0] = p;
    for (int i = 1; i <= 20; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (auto v : gr[u])
    {
        if (v == p)
            continue;
        if (num[v])
            low[u] = min(low[u], num[v]);
        else
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }
    }
    out[u] = ++cnt;
}

bool ok(int v, int u)
{
    return in[u] <= in[v] && out[v] <= out[u];
}

int findpar(int p, int v)
{
    for (int i = 20; i >= 0; i--)
    {
        int u = up[v][i];
        if (u > 0 && u != p && ok(u, p))
            v = u;
    }
    return v;
}

void solve()
{
    int type;
    cin >> type;
    if (type == 1)
    {
        int a, b, g1, g2;
        cin >> a >> b >> g1 >> g2;
        if (num[g1] > num[g2])
            swap(g1, g2);
        if (up[g2][0] != g1)
        {
            cout << "yes" << endl;
            return;
        }
        if (low[g2] <= num[g1])
        {
            cout << "yes" << endl;
            return;
        }
        if (ok(a, g2) == ok(b, g2))
        {
            cout << "yes" << endl;
            return;
        }
        cout << "no" << endl;
    }
    else
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (num[a] > num[b])
            swap(a, b);
        if (up[b][0] == a)
        {
            cout << "yes" << endl;
            return;
        }
        if (ok(b, a))
        {
            if (ok(c, a) && ok(b, c))
            {
                b = findpar(c, b);
                if (low[b] < num[c])
                {
                    cout << "yes" << endl;
                    return;
                }
                cout << "no" << endl;
                return;
            }
            cout << "yes" << endl;
            return;
        }
        if (ok(c, a) || ok(c, b))
        {
            cout << "yes" << endl;
            return;
        }
        if (ok(a, c) && ok(b, c))
        {
            a = findpar(c, a);
            b = findpar(c, b);
            if (a == b)
            {
                cout << "yes" << endl;
                return;
            }
            if (low[a] < num[c] && low[b] < num[c])
            {
                cout << "yes" << endl;
                return;
            }
            cout << "no" << endl;
            return;
        }
        if (ok(a, c) || ok(b, c))
        {
            if (ok(b, c))
                swap(a, b);
            a = findpar(c, a);
            if (low[a] < num[c])
            {
                cout << "yes" << endl;
                return;
            }
            cout << "no" << endl;
            return;
        }
        cout << "yes" << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    tarjan(1, 0);
    int q;
    cin >> q;
    while (q--)
    {
        solve();
    }
}