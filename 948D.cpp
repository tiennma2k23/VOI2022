#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 1, inf = 1e18;
int ok[maxn], a[maxn], b[maxn];
vector<int> v, v2;
bool ss(vector<int> &x, vector<int> &y)
{
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] != y[i])
            return (x[i] < y[i]);
    }
    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen("input", "r", stdin);
    // freopen("output", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        int ans = inf, pos;
        cin >> b[i];
        // for (int j = 1; j <= n; j++)
        //     if (!ok[j])
        //     {
        //         int res = a[j] xor b[i];
        //         if (res < ans)
        //             ans = res, pos = j;
        //     }
        // v.push_back(ans);
        // ok[pos] = 1;
    }
    for (int i = 1; i <= n; i++)
        ok[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        int ans = inf, pos;
        for (int j = 1; j <= n; j++)
            if (!ok[j])
            {
                int res = a[i] xor b[j];
                if (res < ans)
                    ans = res, pos = j;
            }
        v2.push_back(ans);
        ok[pos] = 1;
    }
    // if (ss(v, v2))
    // else
    for (auto val : v2)
        cout << val << " ";
}