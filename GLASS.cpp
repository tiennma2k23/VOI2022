#include <bits/stdc++.h>
using namespace std;
int32_t main(int argc, char const *argv[])
{
    int n, m, k;
    cin >> m >> n >> k;
    while (k--)
    {
        char type;
        int x;
        cin >> type >> x;
        if (type == 'H')
        {
            auto it = st_h.lower_bound(x);
            if (it != st_h.end())
            {
                auto it1 = it;
                if (it1 != st_h.begin())
                {
                    --it1;
                    st.erase(st.find(*it - *it1));
                    st.insert(x - *it1);
                }
                st.insert(*it - x);
            }
            else
            {
                if (it != st_h.begin())
                {
                    --it;
                    st.insert(x - *it);
                }
            }
            st_h.insert(x);
        }
        else
        {
            auto it = st_v.lower_bound(x);
            if (it != st_v.end())
            {
                auto it1 = it;
                --it1;
                st.erase(st.find(*it - *it1));
                st.insert(x - *it1);
                st.insert(*it - x);
            }
            else
            {
                if (it != st_v.begin())
                {
                    --it;
                }
            }
        }
    }
    /* code */
    return 0;
}
