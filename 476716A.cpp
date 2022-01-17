#include <bits/stdc++.h>
#define int long long
using namespace std;
map<int, int> mp;
int32_t main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int u, v, w;
            cin >> u >> v >> w;
            while (u != v)
            {
                if (u < v)
                    swap(u, v);
                mp[u] += w;
                u /= 2;
            }
        }
        else
        {
            int u, v, ans = 0;
            cin >> u >> v;
            while (u != v)
            {
                if (u < v)
                    swap(u, v);
                ans += mp[u];
                u /= 2;
            }
            cout << ans << endl;
        }
    }
}