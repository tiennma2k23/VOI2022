#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> II;
const int N = 1e3 + 3, M = 1e6 + 5, base = 31;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int n, m, root = 0, nNode = 0;
string s, t;
ll Hash[2][M], Pow[M];
map<ll, int> mp0, mp1;

inline ll get1(int l, int r)
{
    return (Hash[0][r] - Hash[0][l - 1] * Pow[r - l + 1] + MOD * MOD) % MOD;
}

inline ll get2(int l, int r)
{
    return (Hash[1][l] - Hash[1][r + 1] * Pow[r - l + 1] + MOD * MOD) % MOD;
}

int main()
{
    freopen("QPACAT.inp", "r", stdin);
    freopen("QPACAT.ans", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Pow[0] = 1;
    for (int i = 1; i < M; i++)
        Pow[i] = Pow[i - 1] * base % MOD;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        int len = s.size();
        reverse(s.begin(), s.end());
        s = ' ' + s;
        for (int j = 0; j <= len + 1; j++)
            Hash[0][j] = Hash[1][j] = 0;
        for (int j = 1; j <= len; j++)
            Hash[0][j] = (Hash[0][j - 1] * base + (s[j] - 'a' + 1)) % MOD;
        for (int j = len; j >= 1; j--)
            Hash[1][j] = (Hash[1][j + 1] * base + (s[j] - 'a' + 1)) % MOD;
        mp0[Hash[0][len]] = true;
        mp1[Hash[0][len]] = true;
        for (int j = len; j > 1; j--)
            if (get1(j, len) == get2(j, len))
                mp0[get1(1, j - 1)] = true;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> t;
        int len = t.size();
        t = ' ' + t;
        for (int j = 0; j <= len + 1; j++)
            Hash[0][j] = Hash[1][j] = 0;

        for (int j = 1; j <= len; j++)
            Hash[0][j] = (Hash[0][j - 1] * base + (t[j] - 'a' + 1)) % MOD;
        for (int j = len; j >= 1; j--)
            Hash[1][j] = (Hash[1][j + 1] * base + (t[j] - 'a' + 1)) % MOD;

        int r = 0, flag = false;
        if (mp0.find(Hash[0][len]) != mp0.end())
            flag = true;
        else
        {
            for (int j = 1; j < len; j++)
            {
                if (get1(j + 1, len) == get2(j + 1, len))
                    flag |= (mp1.find(get1(1, j)) != mp1.end());
            }
        }
        if (flag)
            cout << "YES"
                 << "\n";
        else
            cout << "NO"
                 << "\n";
    }
    return 0;
}