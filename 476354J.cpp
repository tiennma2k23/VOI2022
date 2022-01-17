#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 1, inf = 1e9 + 1;
int a[maxn], cnt[maxn];
int32_t main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (q--)
    {
        int k;
        cin >> k;
        int l = 1, dem = 0;
        int ans = 0, sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += a[i];
            while (sum > k)
            {
                sum -= a[l];
                l++;
            }
            ans += (i - l + 1);
        }
        cout << ans << endl;
    }
}