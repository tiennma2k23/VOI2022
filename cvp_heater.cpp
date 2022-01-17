#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 10, inf = 1e15 + 1, N = 5001;
int n, k;
int a[maxn];
// namespace sub1
// {
//     void solve()
//     {
//         for (int i = 0; i <= 2 * n; i++)
//         {
//             for (int j = 0; j <= k; j++)
//                 f[i][j] = inf;
//         }
//         f[0][0] = 0;
//         for (int i = 1; i <= 2 * n; i++)
//         {
//             if (i % 2 == 0)
//             {
//                 for (int j = 1; j <= i; j++)
//                 {
//                     if (j % 2)
//                     {
//                         for (int k1 = 1; k1 <= k; k1++)
//                             f[i][k1] = min(f[i][k1], f[j - 1][k1 - 1] + t[i] - t[j]);
//                     }
//                 }
//             }
//         }
//         int ans = inf;
//         for (int i = 1; i <= k; i++)
//             ans = min(ans, f[2 * n][i]);
//         cout << ans << endl;
//     }
// }

// namespace sub2
// {
//     void solve()
//     {
//         for (int i = 0; i <= 2 * n; i++)
//         {
//             for (int j = 0; j <= k; j++)
//                 f[i][j] = inf;
//         }
//         f[0][0] = 0;
//         for (int i = 1; i <= 2 * n; i++)
//             if (i % 2 == 0)
//             {
//                 for (int k1 = 1; k1 <= k; k1++)
//                 {
//                     f[i][k1] = min(f[i][k1], f[i - 2][k1 - 1] + t[i] - t[i - 1]);
//                     f[i][k1] = min(f[i][k1], f[i - 2][k1] + t[i] - t[i - 2]);
//                 }
//             }
//         int ans = inf;
//         for (int i = 1; i <= k; i++)
//             ans = min(ans, f[2 * n][i]);
//         cout << ans << endl;
//     }
// }
namespace sub3
{
    int b[maxn];
    int ans = 0;
    void solve()
    {
        for (int i = 1; i < n; i++)
            b[i] = a[i + 1] - a[i] - 1;
        sort(b + 1, b + n, greater<int>());
        ans = a[n] - a[1] + 1;
        for (int i = 1; i < k; i++)
            ans -= b[i];
        cout << ans << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // for (int i = 1; i <= 2 * n; i++)
    // {
    //     if (i % 2)
    //         t[i] = a[i / 2 + 1];
    //     else
    //         t[i] = t[i - 1] + 1;
    // }
    // if (n <= 20)
    //     sub1::solve();
    // else if (n <= 5000)
    //     sub2::solve();
    // else
    sub3::solve();
}