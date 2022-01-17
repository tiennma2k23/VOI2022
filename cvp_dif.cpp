#include <bits/stdc++.h>
using namespace std;
multiset<int> st, st1;
int32_t main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (i == 1)
            cout << 0 << endl;
        else
        {
            auto it = st.lower_bound(a);
            if (it == st.begin())
            {
                st1.insert(abs(*it - a));
            }
            else if (it == st.end())
            {
                auto it1 = it;
                it1--;
                st1.insert(abs(*it1 - a));
            }
            else
            {
                auto it1 = it;
                it1--;
                st1.erase(st1.find(abs(*it1 - *it)));
                st1.insert(abs(*it1 - a));
                st1.insert(abs(*it - a));
            }
            cout << *st1.rbegin() << endl;
        }
        st.insert(a);
    }
}