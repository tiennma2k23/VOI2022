#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
vector<int> v;
const int maxn = 1e5 + 1;
int a[maxn], ans[maxn];
struct nodes
{
    int l, r, id;
} query[maxn];

bool cmp(nodes a, nodes b)
{
    if (a.r != b.r)
        return a.r < b.r;
    return a.l < b.l;
}
deque<int> dq;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#define TASK "dqueue"
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> query[i].l >> query[i].r;
        query[i].id = i;
    }
    sort(query + 1, query + 1 + q, cmp);
    int r = 1;
    for (int i = 1; i <= q; i++)
    {
        while (r <= query[i].r)
        {
            while (dq.size() && a[dq.back()] >= a[r])
            {
                dq.pop_back();
            }
            dq.push_back(r);
            r++;
        }
        while (dq.front() < query[i].l && dq.size())
            dq.pop_front();
        ans[query[i].id] = a[dq.front()];
    }
    for (int i = 1; i <= q; i++)
        cout << ans[i] << endl;
}