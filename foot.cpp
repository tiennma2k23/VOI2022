#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 1;
int a[maxn];
deque<int> dq;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#define TASK "FOOT"
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        while (dq.size() && a[dq.back()] >= a[i])
            dq.pop_back();

        dq.push_back(i);

        if (dq.front() + k <= i)
            dq.pop_front();

        res += a[dq.front()] * 2;
    }
    cout << res << endl;
}