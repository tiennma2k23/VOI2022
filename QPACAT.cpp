#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6 + 5, X = 1e6, N = 1e3 + 5;
const ll MOD = 1e9 + 3, base = 31;
bool cmp(string s, string s1)
{
    return s.size() < s1.size();
}
string s[N];
ll POW[maxn];
ll hs[N][N];
string s1;
ll H1[maxn];
map<ll, int> ok, ok2;
void init(int i)
{
    s[i] = ' ' + s[i];
    int len = s[i].size() - 1;
    auto &Hash = hs[i];
    for (int j = 1; j <= len; j++)
        Hash[j] = (Hash[j - 1] * base + s[i][j] - 'a' + 1) % MOD;
}
ll getHash(int i, int j, int id)
{
    auto &Hash = hs[id];
    if (i > j)
        return 0;
    if (i == 0 && j == 0)
        return 0;
    return (Hash[j] - Hash[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}

ll getH1(int i, int j)
{
    if (i > j)
        return 0;
    if (i == 0 && j == 0)
        return 0;
    return (H1[j] - H1[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}
// int getH2(int i, int j)
// {
//     if (i > j)
//         return 0;
//     if (i == 0 && j == 0)
//         return 0;
//     return (H2[j] - H2[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
// }
void prepare()
{
    int len = s1.length();
    s1 = ' ' + s1;
    for (int j = 1; j <= len; j++)
        H1[j] = (H1[j - 1] * base + s1[j] - 'a' + 1) % MOD;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#define TASK "QPACAT"
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    int n, m;
    POW[0] = 1;
    for (int i = 1; i <= X; i++)
        POW[i] = (POW[i - 1] * base) % MOD;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    sort(s + 1, s + 1 + n, cmp);
    ok[0] = true;
    for (int i = 1; i <= n; i++)
    {
        string ss = s[i];
        reverse(s[i].begin(), s[i].end());
        init(i);
        // cout << s[i] << '\n';
        int len = s[i].length() - 1;
        ok2[getHash(1, len, i)] = true;
        // if (getHash(1, len, i) == 2)
        //     cout << s[i] << '\n';

        s[i] = ss;
        init(i);
        ss = s[i];

        ss.erase(0, 1);
        reverse(ss.begin(), ss.end());

        ss = ' ' + ss;
        string s1 = "", s2 = "";
        for (int j = 1; j <= len; j++)
        {
            s1 += s[i][j];
            s2 = ss[len - j + 1] + s2;
            if (s1 == s2)
            {
                ok[getHash(j + 1, len, i)] = true;
                // cout << j + 1 << '\n';
            }
        }
        // cout << '\n';
    }

    while (m--)
    {
        cin >> s1;
        string s2 = s1;
        reverse(s1.begin(), s1.end());
        prepare();
        // cout << s1 << '\n';
        // cout << getH1(1, s1.length() - 1) << '\n';
        if (ok[getH1(1, s1.length() - 1)])
        {
            cout << "YES" << '\n';
        }
        else
        {
            s1 = s2;
            // s1 = ' ' + s1;
            prepare();
            bool ck = false;
            reverse(s2.begin(), s2.end());
            s2 = ' ' + s2;
            int len = s1.length() - 1;
            string ss1 = "", ss2 = "";
            if (ok2[getH1(1, len)])
            {
                cout << "YES" << '\n';
            }
            else
            {
                for (int i = len; i >= 1; i--)
                {
                    ss1 = s1[i] + ss1;
                    ss2 = ss2 + s2[len - i + 1];
                    if (ss1 == ss2)
                    {
                        if (ok2[getH1(1, i - 1)])
                        {
                            // cout << getH1(1, i - 1) << '\n';
                            ck = true;
                            // cout << i - 1 << '\n';
                            break;
                        }
                        // cout << s1 << ' ' << 1 << ' ' << i - 1 << '\n';
                    }
                }
                if (ck)
                    cout << "YES" << '\n';
                else
                    cout << "NO" << '\n';
            }
        }
    }
}