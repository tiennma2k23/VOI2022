#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 1, inf = 1e9 + 1;
int a[maxn], cnt[maxn];
int32_t main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int l = 1, dem = 0;
    int ans = inf;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] <= k)
        {
            cnt[a[i]]++;
            if (cnt[a[i]] == 1)
                dem++;
        }
        while (dem >= k)
        {
            if (dem >= k)
                ans = min(ans, i - l + 1);
            cnt[a[l]]--;
            if (cnt[a[l]] == 0)
                dem--;
            l++;
        }
    }
    if (ans != inf)
        cout << ans;
    else
        cout << 0;
    cout << endl;
}