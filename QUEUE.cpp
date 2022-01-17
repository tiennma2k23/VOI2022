#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#define TASK "QUEUE"
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    queue<int> q;
    int t;
    cin >> t;
    while (t--)
    {
        int typ;
        cin >> typ;
        if (typ == 1)
        {
            int u;
            cin >> u;
            q.push(u);
        }
        else if (typ == 2)
        {
            if (!q.empty())
                q.pop();
        }
        else
        {
            if (q.empty())
                cout << -1 << endl;
            else
                cout << q.front() << endl;
        }
    }
}