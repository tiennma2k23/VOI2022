#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 1, inf = 1e9 + 1;
int b[maxn], a[maxn], L[maxn], R[maxn], n, q;
void solve()
{
    int l, r;
    cin >> l >> r;
    for (int i = l + 1; i <= r; i++)
    {
        b[i - l] = abs(a[i] - a[i - 1]);
    }
    b[0] = inf;
    b[r - l + 1] = inf;
    for (int i = 1; i <= r - l; i++)
    {
        L[i] = i - 1;
        while (L[i] > 0 && b[L[i]] <= b[i])
            L[i] = L[L[i]];
    }
    for (int i = r - l; i >= 1; i--)
    {
        R[i] = i + 1;
        while (R[i] <= r - l && b[R[i]] < b[i])
            R[i] = R[R[i]];
    }
    int ans = 0;
    for (int i = 1; i <= r - l; i++)
    {
        L[i]++, R[i]--;
        // cout << b[i] << ' ' << L[i] << ' ' << R[i] << endl;
        ans += b[i] * (i - L[i]) * (R[i] - i);
    }
    cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    while (q--)
        solve();
}