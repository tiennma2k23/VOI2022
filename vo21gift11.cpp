#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 1, mod = 998244353;
int n;
int a[maxn];
void sub1()
{
    vector<int> v;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        v.push_back(i);
    do
    {
        /* code */
        int s = 0;
        for (auto val : v)
        {
            int tmp = a[val];
            vector<int> v1;
            while (tmp > 0)
            {
                v1.push_back(tmp % 10);
                tmp /= 10;
            }
            for (int i = v1.size() - 1; i >= 0; i--)
                s = s * 10 + v1[i], s %= 11;
            v1.clear();
        }
        if (s == 0)
            ans++;
        ans %= mod;
    } while (next_permutation(v.begin(), v.end()));
    cout << ans << endl;
}
void sub2()
{
    int ans = 0;
    vector<int> v;
    for (int i = 1; i <= n; i++)
        v.push_back(i);
    int s = 0;
    for (auto val : v)
    {
        int tmp = a[val];
        vector<int> v1;
        while (tmp > 0)
        {
            v1.push_back(tmp % 10);
            tmp /= 10;
        }
        for (int i = v1.size() - 1; i >= 0; i--)
            s = s * 10 + v1[i], s %= 11;
    }
    if (s == 0)
        ans++;
    for (int i = 1; i <= n; i++)
        ans *= i, ans %= mod;
    cout << ans << endl;
}
void solve()
{
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        int tmp = a[i];
        int cnt = 0;
        while (tmp > 0)
            cnt++;
        res = res + (cnt % 2 == 0);
    }
    if (n <= 9)
    {
        sub1();
        return;
    }
    if (res == n)
    {
        sub2();
        return;
    }
}
int32_t main()
{
    int q;
    cin >> q;
    while (q--)
    {
        solve();
    }
}