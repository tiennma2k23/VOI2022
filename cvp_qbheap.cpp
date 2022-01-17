#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen("input", "r", stdin);
    // freopen("output", "w", stdout);
    priority_queue<int> pq;
    char ch;
    while (cin >> ch)
    {
        if (ch == '-')
        {
            if (pq.size())
            {
                int val = pq.top();
                while (!pq.empty() && pq.top() == val)
                    pq.pop();
            }
        }
        else if (ch == '+')
        {
            int num;
            cin >> num;
            pq.push(num);
        }
    }
    cout << pq.size() << '\n';
    while (!pq.empty())
    {
        cout << pq.top() << ' ';
        pq.pop();
    }
}