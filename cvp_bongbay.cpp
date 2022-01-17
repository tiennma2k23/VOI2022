#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 3e5 + 1, inf = 1e9;
struct nodes
{
    int t, w, cl;
};
nodes a[maxn];
bool cmp(nodes x, nodes y)
{
    return x.t < y.t;
}

priority_queue<int, vector<int>, greater<int>> pq;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt, ww;
    int n;
    cin >> n;
    n--;
    cin >> tt >> ww;
    for (int i = 1; i <= n; i++)
        cin >> a[i].t >> a[i].w, a[i].cl = a[i].w - a[i].t + 1;
    sort(a + 1, a + 1 + n, cmp);
    int l = n;
    while (l >= 1 && a[l].t > tt)
        pq.push(a[l].cl), l--;
    int ans = pq.size();
    while (!pq.empty())
    {
        if (pq.size())
        {
            tt -= pq.top();
            pq.pop();
        }
        if (tt < 0)
            break;
        // if (tt > ww)
        // break;
        while (l >= 1 && a[l].t > tt)
            pq.push(a[l].cl), l--;
        int sz = pq.size();
        ans = min(ans, sz);
    }
    cout << ans + 1 << endl;
}