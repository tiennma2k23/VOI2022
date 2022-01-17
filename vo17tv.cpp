#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k;
const int maxn = 1e5 + 1, mod = 1000000003, base = 31;
int _pow[maxn];
vector<int> hashs[maxn];
void init()
{
    _pow[0] = 1;
    for (int i = 1; i < maxn; i++)
        _pow[i] = (_pow[i - 1] * base) % mod;
}
void hashing(int id, string s)
{
    hashs[id].resize(s.size() + 5);
    for (int i = 1; i < s.length(); i++)
        hashs[id][i] = (hashs[id][i - 1] * base + s[i] - 'A' + 1) % mod;
}
int getHash(int id, int i, int j)
{
    return (hashs[id][j] - hashs[id][i - 1] * _pow[j - i + 1] + mod * mod) % mod;
}
string s[maxn];
bool ok(int len)
{
    vector<int> v;
    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        set<int> st;
        for (int j = 1; j < s[i].length(); j++)
        {
            if (j + len - 1 < s[i].length())
                st.insert(getHash(i, j, j + len - 1));
        }
        for (auto val : st)
            v.push_back(val);
        st.clear();
    }
    sort(v.begin(), v.end());
    int cnt = 1;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] != v[i - 1])
            cnt = 1;
        else
            cnt++;
        res = max(res, cnt);
    }
    return (res >= k);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    cin >> n >> k;
    int maxx = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        int len = s[i].length();
        s[i] = ' ' + s[i];
        hashing(i, s[i]);
        maxx = max(maxx, len);
    }
    int ans = 0;
    int l = 1, r = maxx;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (ok(mid))
            l = mid + 1, ans = mid;
        else
            r = mid - 1;
    }
    cout << ans << endl;
}