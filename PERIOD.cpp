#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 1;
int p[maxn], p2[maxn];
int32_t main()
{
#define TASK "PERIOD"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    p[1] = 0;
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        int k = p[i - 1];
        while (k > 0 && s[k + 1] != s[i])
            k = p[k];
        if (s[k + 1] == s[i])
            k++;
        p[i] = k;
    }
    for (int i = 1; i <= n; i++)
    {
        if (p2[p[i]] == 0)
            p2[i] = p[i];
        else
            p2[i] = p2[p[i]];
        if (p2[i])
            ans += i - p2[i];
        // cout << p2[i] << endl;
    }
    cout << ans << endl;
}