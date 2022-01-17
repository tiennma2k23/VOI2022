#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#define TASK "DEQUEEZ"
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    deque<int> dq;
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
            dq.push_front(u);
        }
        else if (typ == 2)
        {
            int u;
            cin >> u;
            dq.push_back(u);
        }
        else if (typ == 3)
        {
            if (dq.size())
                dq.pop_front();
        }
        else if (typ == 4)
        {
            if (dq.size())
                dq.pop_back();
        }
        else if (typ == 5)
        {
            if (dq.size())
                cout << dq.front() << endl;
            else
                cout << -1 << endl;
        }
        else if (typ == 6)
        {
            if (dq.size())
                cout << dq.back() << endl;
            else
                cout << -1 << endl;
        }
    }
}