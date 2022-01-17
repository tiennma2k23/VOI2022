#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
unordered_map<int, int> ok;
int32_t main()
{
#define TASK "MAP"
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    while (n--)
    {
        int x;
        cin >> x;
        ok[x] = 1;
    }
    while (q--)
    {
        int x;
        cin >> x;
        cout << ok[x] << endl;
    }
}