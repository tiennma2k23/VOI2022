#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 7, Q = 2e5 + 7;
struct Query
{
    int u, v, k, id;
    bool operator<(const Query &q) const
    {
        return k < q.k;
    }
};

int ans[Q], n, q, bit[N];
pair<int, int> a[N];
Query query[Q];

void enter()
{
    scanf("%d", &n);
    scanf("%d", &q);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    for (int i = 1; i <= q; ++i)
    {
        Query &q = query[i];
        scanf("%d%d%d", &q.u, &q.v, &q.k);
        q.id = i;
    }
}

void increase(int v)
{
    for (; v <= n; v += v & -v)
        ++bit[v];
}

int sum(int v)
{
    int res = 0;
    for (; v != 0; v -= v & -v)
        res += bit[v];
    return res;
}

void solve()
{
    sort(query + 1, query + q + 1);
    sort(a + 1, a + n + 1);
    int pos = n;
    for (int i = q; i >= 1; --i)
    {
        Query &q = query[i];
        while (a[pos].first > q.k)
            increase(a[pos--].second);
        ans[q.id] = sum(q.v) - sum(q.u - 1);
    }
}

void print()
{
    for (int i = 1; i <= q; ++i)
        printf("%d\n", ans[i]);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#define TASK "VPKQUERY"
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    enter();
    solve();
    print();
    return 0;
}