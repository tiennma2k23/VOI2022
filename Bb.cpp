#include <bits/stdc++.h>
#define II pair<int, int>
#define fi first
#define se second
using namespace std;
const int maxn = 1e5 + 1;
II a[maxn];
bool cmp(II a, II b)
{
    return a.se < b.se;
}
int32_t main()
{
    int q;
    cin >> q;
    while (q--)
    {
        set<int> st;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i].fi >> a[i].se;
        sort(a + 1, a + 1 + n, cmp);
        for (int i = 1; i <= n; i++)
        {
            st.insert(i);
        }
        for (int i = 1; i <= n; i++)
        {
            auto it = st.lower_bound(a[i].fi);
            st.erase(it);
            cout << a[i].fi << ' ' << a[i].se << ' ' << *it << endl;
        }
        cout << endl;
    }
}