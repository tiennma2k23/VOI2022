#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, inf = 1e9 + 1;
vector<int> v;
int a[maxn], fen[maxn];
void update(int pos, int val)
{
    while (pos < maxn)
    {
        fen[pos] = max(fen[pos], val);
        pos += (pos & (-pos));
    }
}
int get(int pos)
{
    int res = -inf;
    while (pos > 0)
    {
        res = max(res, fen[pos]);
        pos -= (pos & (-pos));
    }
    return res;
}
int32_t main()
{
    int n, S;
    set<int> st;
    cin >> n >> S;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
        st.insert(sum);
    }
    for (auto val : st)
    {
        v.push_back(val);
    }
    for (int i = 1; i < maxn; i++)
        fen[i] = -inf;
    int ans = inf;
    sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
        int tmp = sum - S;
        int pos = upper_bound(v.begin(), v.end(), tmp) - v.begin();
        int tt = get(pos);
        if (sum >= S)
            ans = min(ans, i);
        if (tt != -inf)
            ans = min(ans, i - tt);
        pos = lower_bound(v.begin(), v.end(), sum) - v.begin() + 1;
        update(pos, i);
    }
    if (ans == inf)
        cout << 0;
    else
        cout << ans;
    cout << endl;
}