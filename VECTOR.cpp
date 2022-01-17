#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
vector<int> v;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#define TASK "VECTOR"
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    int q;
    cin >> q;
    while (q--)
    {
        int typ;
        cin >> typ;
        if (typ == 1)
        {
            int u;
            cin >> u;
            v.push_back(u);
        }
        else if (typ == 2)
        {
            if (v.size())
                v.pop_back();
        }
        else
        {
            int u;
            cin >> u;
            if (v.size() < u || u <= 0)
                cout << -1 << endl;
            else
                cout << v[u - 1] << endl;
        }
    }
}