#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 1, inf = 1e9 + 1;
int a[maxn], minl[maxn], l[maxn], r[maxn], minr[maxn];
deque<int> dq;
int32_t main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        while (dq.size() && a[dq.back()] >= a[i])
            dq.pop_back();

        dq.push_back(i);

        if (dq.front() + k <= i)
            dq.pop_front();

        if (i >= k)
            minl[i] = a[dq.front()];
        else
            minl[i] = -inf;
    }
    dq.clear();
    for (int i = n; i >= 1; i--)
    {
        while (dq.size() && a[dq.back()] >= a[i])
            dq.pop_back();

        dq.push_back(i);

        if (dq.front() - k >= i)
            dq.pop_front();

        if (i >= n - k + 1)
            minr[i] = a[dq.front()];
        else
            minr[i] = -inf;
    }
    // for (int i = 1; i <= n; i++)
    //     cout << minl[i] << ' ';
    dq.clear();
    for (int i = 1; i <= n; i++)
    {
        while (dq.size() && minr[dq.back()] <= minr[i])
            dq.pop_back();

        dq.push_back(i);

        if (dq.front() + k <= i)
            dq.pop_front();

        if (i >= k)
            l[i] = minr[dq.front()];
        else
            l[i] = -inf;
    }
    // for (int i = 1; i <= n; i++)
    //     cout << l[i] << ' ';
    dq.clear();
    for (int i = n; i >= 1; i--)
    {
        while (dq.size() && minl[dq.back()] <= minl[i])
            dq.pop_back();

        dq.push_back(i);

        if (dq.front() - k >= i)
            dq.pop_front();

        if (i <= n - k + 1)
            r[i] = minl[dq.front()];
        else
            r[i] = -inf;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cout << l[i] << ' ' << r[i] << endl;
        ans += a[i] - max(l[i], r[i]);
    }
    cout << ans << endl;
}