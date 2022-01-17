#include <bits/stdc++.h>
#define ll long long
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int a[100001];
int32_t main(int argc, char const *argv[])
{
    /* code */
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        ll ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i], pq.push(a[i]);
        while (pq.size() > 1)
        {
            int tmp1 = pq.top();
            pq.pop();
            int tmp2 = pq.top();
            pq.pop();
            // cout << tmp1 << " " << tmp2 << endl;
            pq.push(tmp1 + tmp2);
            ans += 1ll * (tmp1 + tmp2);
        }
        cout << ans << '\n';
        pq.pop();
    }
}
