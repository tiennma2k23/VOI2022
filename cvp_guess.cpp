#include <bits/stdc++.h>
using namespace std;
set<int> st;
int32_t main()
{

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (st.find(a) != st.end())
            continue;
        auto it = st.lower_bound(a);
        if (it != st.begin())
        {
            auto it1 = it;
            it1--;
            int val = *it1;
            if (abs(val - a) < m)
            {
                cout << i << endl;
                return 0;
            }
        }
        if (it != st.end())
        {
            int val = *it;
            if (abs(val - a) < m)
            {
                cout << i << endl;
                return 0;
            }
        }
        st.insert(a);
    }
    cout << -1 << endl;
}