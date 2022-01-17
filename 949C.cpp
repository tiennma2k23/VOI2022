#include <bits/stdc++.h>
#pragma endregion
#pragma region
#define int long long
using namespace std;
const int maxn = 1e5 + 1, inf = 1e9 + 1;
vector<int> gr[maxn], _v[maxn];
int id, cnt, low[maxn], num[maxn], pos[maxn], a[maxn], out[maxn];
stack<int> st;
void tarjan(int u)
{

    low[u] = num[u] = ++id;
    st.push(u);
    for (auto v : gr[u])
    {
        if (num[v])
            low[u] = min(low[u], num[v]);
        else
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
    }

    if (num[u] == low[u])
    {
        int v = 0;
        ++cnt;
        do
        {
            v = st.top();
            st.pop();
            low[v] = num[v] = inf;
            _v[cnt].push_back(v);
            pos[v] = cnt;
        } while (v != u);
    }
}
int32_t main(int argc, char const *argv[])
{
    /* code */
    int n, m, h;
    cin >> n >> m >> h;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        if ((a[u] + 1) % h == a[v])
            gr[u].push_back(v);
        if ((a[v] + 1) % h == a[u])
            gr[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int &j : gr[i])
            if (pos[i] != pos[j])
            {
                ++out[pos[i]];
            }
    }

    int ans = 0;
    int res = inf;
    for (int i = 1; i <= cnt; i++)
    {
        if (out[i] == 0)
        {
            if (res > _v[i].size())
                res = _v[i].size(), ans = i;
        }
    }
    for (int i = 1; i <= n; i++)
        if (!num[i])
            tarjan(i);
    for (int i = 1; i <= n; i++)
    {
        for (auto j : gr[i])
            if (pos[i] != pos[j])
            {
                ++out[pos[i]];
            }
    }

    for (int i = 1; i <= cnt; i++)
    {
        if (out[i] == 0)
        {
            if (res > _v[i].size())
                res = _v[i].size(), ans = i;
        }
    }
    cout << _v[ans].size() << endl;
    for (auto val : _v[ans])
        cout << val << ' ';
    return 0;
}
