#include <bits/stdc++.h>
#define int long long
#define IC pair<int, char>
using namespace std;
vector<IC> ans;
#define fi first
#define se second
int32_t main()
{
    // freopen("input", "r", stdin);
    // freopen("output", "w", stdout);
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int p;
        cin >> p;
        ans.push_back(IC(p, 'D'));
        ans.push_back(IC(p, 'D'));
        ans.push_back(IC(p, 'W'));
        ans.push_back(IC(p, 'L'));
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int q;
        cin >> q;
        ans.push_back(IC(q, 'D'));
        ans.push_back(IC(q, 'D'));
        ans.push_back(IC(q, 'D'));
        ans.push_back(IC(q, 'W'));
        ans.push_back(IC(q, 'W'));
        ans.push_back(IC(q, 'L'));
    }
    cout << ans.size() << endl;
    for (auto val : ans)
        cout << val.fi << " " << val.se << endl;
}