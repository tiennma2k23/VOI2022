#include <bits/stdc++.h>
#define int long long
#define II pair<int, int>
#define fi first
#define se second
#define vsize(v) (int)(v.size())
using namespace std;
const int maxn = 1e5 + 5;
int cnt[maxn], cnt1[maxn], b[maxn];
set<II> st;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#define TASK "orderss"
    // freopen(TASK ".inp", "r", stdin);
    // freopen(TASK ".out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        cnt[a]++;
        st.insert({a, 0ll});
    }
    vector<int> v;
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        cnt1[b[i]]++;
        if (cnt[b[i]] != 0)
        {
            auto it = st.lower_bound({b[i], 0});
            if (it == st.end() || (it != st.end() && it->fi != b[i]))
            {
                st.insert({b[i], cnt1[b[i]]});
            }
            else
            {
                II p = *it;
                st.erase(it);
                if (cnt[b[i]] != cnt1[b[i]])
                {
                    st.insert({b[i], cnt1[b[i]]});
                }
            }
        }
        if (i >= n && st.empty())
            v.push_back(i - n + 1);
        if (i >= n)
        {
            int l = i - n + 1;
            cnt1[b[l]]--;
            if (cnt[b[l]])
            {
                auto it = st.lower_bound({b[l], 0});
                if (it == st.end() || (it != st.end() && it->fi != b[l]))
                {
                    st.insert({b[l], cnt1[b[l]]});
                }
                else
                {
                    II p = *it;
                    st.erase(it);
                    if (cnt[b[l]] != cnt1[b[l]])
                    {
                        st.insert({b[l], cnt1[b[l]]});
                    }
                }
            }
        }
    }
    cout << vsize(v) << endl;
    for (auto val : v)
        cout << val << ' ';
}