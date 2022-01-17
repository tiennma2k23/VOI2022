#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int t[maxn];
int32_t main()
{
    int n, hh;
    cin >> n >> hh;
    while (n--)
    {
        int l, r;
        cin >> l >> r;
        t[l]++, t[r + 1]--;
    }
    int ans = 0;
    for (int i = 1; i <= hh; i++)
        t[i] += t[i - 1];
    for (int i = 0; i <= hh; i++)
        ans = max(ans, t[i]);
    cout << ans << endl;
}