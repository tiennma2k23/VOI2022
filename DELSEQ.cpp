#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 1e10, maxn = 1e5 + 5;
int a[maxn];
vector<int> v;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#define TASK "DELSEQ"
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    a[0] = -inf;
    int d = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != a[i - 1])
        {
            if (d != 0)
                v.push_back(d);
            d = 1;
        }
        else
            d++;
    }
    v.push_back(d);
    sort(v.begin(), v.end());
    int sum = 0;
    for (int i = 0; i < v.size() - 1; i++)
        sum += v[i];
    if (v[v.size() - 1] >= sum)
    {
        cout << sum + (v[v.size() - 1] - sum) << '\n';
    }
    else
    {
        cout << n / 2 + (n % 2) << '\n';
    }
    // int ans = inf;
    // vector<int> v1;
    // for (int i = 1; i <= n; i++)
    // {
    //     v1.push_back(i);
    // }
    // do
    // {
    //     int res = 0;
    //     int i = 0;
    //     while (i < v.size())
    //     {
    //         if (i == v.size() - 1)
    //             i++, res++;
    //         else
    //         {
    //             if (a[v[i]] != a[v[i + 1]])
    //                 res++, i += 2;
    //             else
    //                 res++, i++;
    //         }
    //         /* code */
    //     }
    //     ans = min(ans, res);

    // } while (next_permutation(v.begin(), v.end()));
    // cout << ans << '\n';
}