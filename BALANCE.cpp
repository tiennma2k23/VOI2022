#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 21;
int n, m, a[maxn], P[maxn];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    vector<int> v;
    cin >> n >> m;
    P[0] = 1;
    for (int i = 1; i <= 20; i++)
        P[i] = P[i - 1] * 3;
    // cout << P[20] << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int h = n / 2;
    for (int mask = 0; mask < P[h]; mask++)
    {
        int sum = 0;
        for (int i = 0; i < h; i++)
        {
            int tmp = (mask / P[i]) % 3;
            if (tmp == 1)
                sum += a[i];
            else if (tmp == 2)
                sum -= a[i];
        }
        v.push_back(m - sum);
    }
    int ans = 0;
    sort(v.begin(), v.end());
    for (int mask = 0; mask < P[n - h]; mask++)
    {
        int sum = 0;
        for (int i = 0; i < n - h; i++)
        {
            int tmp = (mask / P[i]) % 3;
            if (tmp == 1)
                sum += a[i + h];
            else if (tmp == 2)
                sum -= a[i + h];
        }
        int pos1 = lower_bound(v.begin(), v.end(), sum) - v.begin();
        int pos2 = upper_bound(v.begin(), v.end(), sum) - v.begin();
        ans += pos2 - pos1;
    }
    cout << ans << endl;
}