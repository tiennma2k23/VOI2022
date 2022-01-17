#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 1;
int pos[maxn];
int32_t main()
{
    int n, cnt = 0;
    set<int> st;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        pos[a] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        int b;
        cin >> b;
        while (!st.empty() && (*st.rbegin()) > pos[b])
        {
            cnt++;
            st.erase(st.find(*st.rbegin()));
        }
        st.insert(pos[b]);
    }
    cout << cnt << endl;
}