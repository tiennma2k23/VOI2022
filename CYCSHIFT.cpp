#include <bits/stdc++.h>
#define int long long
using namespace std;
const int base = 31, mod = 1e9 + 7, maxn = 4e5 + 5;
int Hash[maxn], P[maxn], H[maxn];
int n;
string s;
void init()
{
    for (int i = 1; i <= n; i++)
        Hash[i] = (Hash[i - 1] * base + s[i] - 'a' + 1) % mod;
}

int get_hash(int i, int j)
{
    return (Hash[j] - (Hash[i - 1] * P[j - i + 1] % mod) + mod) % mod;
}
bool ok(int x)
{
    string s1 = "";
    for (int i = 1; i <= x; i++)
        s1 += s[i];
    s1 += s1;
    s1 = ' ' + s1;
    for (int i = 1; i <= 2 * x; i++)
        Hash[i] = (Hash[i - 1] * base + (s1[i] - 'a' + 1)) % mod;
    vector<int> v;
    for (int i = x; i < 2 * x; i++)
        v.push_back(get_hash(i - x + 1, i));
    sort(v.begin(), v.end());
    init();
    for (int i = x; i <= n; i += x)
    {
        if (!binary_search(v.begin(), v.end(), get_hash(i - x + 1, i)))
            return false;
    }
    return true;
}
int32_t main()
{
#define TASK "CYCSHIFT"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    vector<int> res;
    cin >> s;
    n = s.length();
    s = ' ' + s;
    P[0] = 1;
    for (int i = 1; i <= maxn; i++)
        P[i] = (P[i - 1] * base) % mod;
    init();
    int ans = 0;
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
        {
            if (ok(i))
                ans++, res.push_back(i);
            if (ok(n / i) && i * i != n)
                ans++, res.push_back(n / i);
        }
    cout << ans << endl;
    sort(res.rbegin(), res.rend());
    for (auto val : res)
        cout << n / val << ' ';
}