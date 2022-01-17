#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
const int maxn = 5000 + 1, N = 4e6 + 5, inf = 1e18;
vector<vector<int>> Hash;
string s[maxn], s1[maxn];
int POW[N];
const int base = 31, mod = 1e9 + 3, base2 = 31, mod2 = 1e9 + 7;
int n, k;
void init(int id)
{
    Hash[id].resize(s[id].size() + 5);
    for (int i = 1; i < s[id].length(); i++)
        Hash[id][i] = (Hash[id][i - 1] * base2 + s[id][i] - 'a' + 1) % mod2;
}
int getHash(int id, int i, int j)
{
    return (Hash[id][j] - Hash[id][i - 1] * POW[j - i + 1] + mod2 * mod2) % mod2;
}
bool cmp(string s1, string s2)
{
    if (s1[0] != s2[0])
        return s1 < s2;
    else
        return s1.length() > s2.length();
}
namespace sub1
{
    int f[30][5005], cnt[30][5005], sl[30];
    void solve()
    {
        sort(s1 + 1, s1 + 1 + n, cmp);
        // for (int i = 1; i <= n; i++)
        // cout << s1[i] << endl;
        int pos = 1;
        for (int i = 0; i <= 26; i++)
            for (int j = 0; j <= n; j++)
                f[i][j] = -inf;
        for (int i = 1; i <= n; i++)
        {
            if (s1[i][0] != s1[pos][0])
                pos = i;
            cnt[s1[pos][0] - 'a' + 1][i - pos + 1] = cnt[s1[pos][0] - 'a' + 1][i - pos] + (i - pos) * (s1[i].length());
            sl[s1[pos][0] - 'a' + 1] = i - pos + 1;
        }
        int ans = -inf;
        f[0][0] = 0;
        // cout << sl[1] << endl;
        for (int i = 1; i <= 27; i++)
        {
            for (int j = 0; j <= n; j++)
                f[i][j] = f[i - 1][j];
            for (int j = 1; j <= sl[i]; j++)
            {
                for (int l = 0; l <= n; l++)
                {
                    if (l + j <= k && f[i - 1][l] != -inf)
                        f[i][l + j] = max(f[i][l + j], f[i - 1][l] + cnt[i][j]);
                    else
                        break;
                }
            }
            ans = max(ans, f[i][k]);
        }
        cout << ans << endl;
    }
}

namespace sub2
{
    int to[N][27], nodes, d[N];
    void solve()
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int r = 0;
            for (int j = 0; j < s1[i].length(); j++)
            {
                int c = s1[i][j] - 'a';
                if (!to[r][c])
                    to[r][c] = ++nodes;
                r = to[r][c];
                ans += d[r];
                d[r]++;
            }
        }
        cout << ans << endl;
    }
}
namespace sub4
{
    int calc(int i, int j)
    {
        int l = 1, r = min(s1[i].length(), s1[j].length()), res = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int p1 = getHash(i, 1, mid), p2 = getHash(j, 1, mid);
            if (p1 == p2)
                l = mid + 1, res = mid;
            else
                r = mid - 1;
        }
        return res;
    }
    void solve()
    {
        int sz = 1 << n;
        int ans = -inf;
        for (int mask = 0; mask < sz; mask++)
        {
            if (__builtin_popcount(mask) == k)
            {
                vector<int> vec;
                for (int i = 0; i < n; i++)
                    if (mask & (1 << i))
                        vec.push_back(i + 1);
                int res = 0;
                for (int i = 0; i < vec.size(); i++)
                    for (int j = i + 1; j < vec.size(); j++)
                    {
                        res += calc(vec[i], vec[j]);
                    }
                ans = max(ans, res);
            }
        }
        cout << ans << endl;
    }
}
namespace sub3
{
    // int cnt1[N];
    // void solve()
    // {
    //     vector<int> v;
    //     for (int i = 1; i <= n; i++)
    //     {
    //         for (int len = 1; len <= s1[i].length(); len++)
    //         {
    //             int tmp = getHash(i, 1, len);
    //             v.push_back(tmp);
    //         }
    //     }
    //     sort(v.begin(), v.end());
    //     // for (auto val : v)
    //     // cout << val << endl;
    //     v.resize(unique(v.begin(), v.end()) - v.begin());
    //     for (int i = 1; i <= n; i++)
    //     {
    //         for (int len = 1; len <= s1[i].length(); len++)
    //         {
    //             int tmp = getHash(i, 1, len);
    //             int pos = lower_bound(v.begin(), v.end(), tmp) - v.begin();
    //             cnt1[pos]++;
    //         }
    //     }
    //     int ans = 0;
    //     for (int i = 1; i <= n; i++)
    //     {
    //         vector<int> vec;
    //         vec.push_back(s1[i].length());
    //         int tmp1 = getHash(i, 1, s1[i].length());
    //         int pos1 = lower_bound(v.begin(), v.end(), tmp1) - v.begin();
    //         for (int len = s1[i].length(); len >= 1; len--)
    //         {
    //             int tmp = getHash(i, 1, len);
    //             int pos = lower_bound(v.begin(), v.end(), tmp) - v.begin();
    //             int sl = cnt1[pos] - vec.size();
    //             // cout << len << " " << sl << endl;
    //             while (sl > 0 && vec.size() < 3)
    //             {
    //                 sl--;
    //                 vec.push_back(len);
    //                 if (vec.size() == 3)
    //                     break;
    //             }
    //             if (vec.size() == 3)
    //                 break;
    //         }
    //         int res = 0;
    //         for (int j = 0; j < vec.size(); j++)
    //             res += j * vec[j];
    //         // cout << endl;
    //         ans = max(ans, res);
    //     }
    //     cout << ans << endl;
    // }
    int calc(int i, int j)
    {
        int l = 1, r = min(s1[i].length(), s1[j].length()), res = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int p1 = getHash(i, 1, mid), p2 = getHash(j, 1, mid);
            if (p1 == p2)
                l = mid + 1, res = mid;
            else
                r = mid - 1;
        }
        return res;
    }
    void solve()
    {
        int ans = -inf;
        sort(s1 + 1, s1 + 1 + n);
        for (int i = 1; i <= n; i++)
        {
            int res = 0;
            vector<int> vec;
            vec.push_back(i);
            if (i < n)
                vec.push_back(i + 1);
            if (i < n - 1)
                vec.push_back(i + 2);
            for (int i = 0; i < vec.size(); i++)
                for (int j = i + 1; j < vec.size(); j++)
                    res += calc(i, j);
            ans = max(ans, res);
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    POW[0] = 1;
    for (int i = 1; i < N; i++)
        POW[i] = (POW[i - 1] * base2) % mod2;
    cin >> n >> k;
    // k = min(k, n);
    Hash.resize(n + 5);
    bool ok = true;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s1[i] = s[i];
        s[i] = ' ' + s[i];

        for (int j = 2; j < s[i].length(); j++)
            if (s[i][j] != s[i][j - 1])
                ok = false;
        init(i);
    }
    if (ok)
        sub1::solve();
    else if (k == n)
        sub2::solve();
    else if (n <= 20)
    {
        sub4::solve();
    }
    else if (k == 3)
        sub3::solve();
}