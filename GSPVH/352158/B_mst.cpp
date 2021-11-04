#include <bits/stdc++.h>
#define fi first
#define se second
#define u fi.fi
#define v fi.se
#define w se.fi
#define id se.se
#define II pair<int, int>
#define pp pair<II, II>
using namespace std;
// struct nodes
// {
//     int u, v, w, id;
// };
const int maxn = 5e5 + 1;
pp g[maxn];
int rt[maxn];
vector<int> st;
bool cmp(pp a, pp b)
{
    return a.w < b.w;
}

int find(int x)
{
    if (rt[x] == x)
        return x;
    else
        return (rt[x] = find(rt[x]));
}

void join(int _u, int _v)
{
    _u = find(_u);
    _v = find(_v);
    if (_u == _v)
        return;
    rt[_v] = _u;
}

int32_t main()
{
    freopen("mst.inp", "r", stdin);
    freopen("mst.out", "w", stdout);

    int sbt;
    scanf("%ld", &sbt);
    int n, m;
    scanf("%ld %ld", &n, &m);
    //printf("%ld ", m);
    for (int i = 1; i <= n; i++)
        rt[i] = i;
    for (int i = 1; i <= m; i++)
    {
        scanf("%ld %ld %ld", &g[i].u, &g[i].v, &g[i].w);
        g[i].id = i;
    }
    sort(g + 1, g + 1 + m, cmp);
    for (int i = 1; i <= m; i++)
    {
        if (find(g[i].u) == find(g[i].v))
            continue;
        st.push_back(g[i].id);
        join(g[i].u, g[i].v);
    }
    for (auto val : st)
        printf("%ld ", val);
}