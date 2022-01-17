#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
int fen[maxn], a[maxn];
void update(int pos, int val)
{
    while (pos > 0)
    {
        fen[pos] += val;
        pos -= (pos & (-pos));
    }
}
int get(int pos)
{
    int res = 0;
    while (pos < maxn)
    {
        res += fen[pos];
        pos += (pos & (-pos));
    }
    return res;
}

int32_t main()
{
    set<int> st;
    vector<int> v;
    int n, m;
    cin >> n >> m;
    int pre = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre += a[i];
        st.insert(pre);
    }
    st.insert(0ll);
    for (auto val : st)
        v.push_back(val);
    int pos = lower_bound(v.begin(), v.end(), 0ll) - v.begin() + 1;
    update(pos, 1);
    pre = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        pre += a[i];
        pos = lower_bound(v.begin(), v.end(), pre - m) - v.begin() + 1;
        ans += get(pos);
        pos = lower_bound(v.begin(), v.end(), pre) - v.begin() + 1;
        update(pos, 1);
    }
    cout << ans << endl;
}