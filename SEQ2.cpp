#include <bits/stdc++.h>
using namespace std;
set<int> st;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        st.insert(a);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x;
            cin >> x;
            st.insert(x);
        }
        else if (type == 2)
        {
            int x;
            cin >> x;
            st.erase(st.find(x));
        }
        else if (type == 3)
        {
            int x;
            cin >> x;
            auto it = st.upper_bound(x);
            if (it != st.end())
            {
                int val = *it;
                cout << val << endl;
            }
            else
                cout << "No" << endl;
        }
        else if (type == 4)
        {
            int x;
            cin >> x;
            auto it = st.lower_bound(x);
            if (it != st.begin())
            {
                it--;
                int val = *it;
                cout << val << endl;
            }
            else
                cout << "No" << endl;
        }
        else if (type == 5)
        {
            auto it = st.begin(), it1 = st.end();
            it1--;
            int val = *it;
            cout << val << ' ';
            val = *it1;
            cout << val << endl;
        }
    }
}