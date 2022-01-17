#include <bits/stdc++.h>
using namespace std;

string sub(string a, string b)
{
    string ans;
    while (a.length() < b.length())
        a = '0' + a;
    while (b.length() < a.length())
        b = '0' + b;
    if (a < b)
        ans += '-', swap(a, b);
    int borrow = 0;
    string c = "";
    for (int i = a.length() - 1; i >= 0; i--)
    {
        int s = a[i] - b[i] - borrow;
        if (s < 0)
        {
            s += 10;
            borrow = 1;
        }
        else
            borrow = 0;
        c = char(s + '0') + c;
    }
    while (c.length() > 1 && c[0] == '0')
        c.erase(0, 1);
    ans += c;
    return ans;
}

int32_t main(int argc, char const *argv[])
{
#define TASK "DIFSHIFT"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    vector<string> v, v1;
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    s += s;
    t += t;
    s = ' ' + s, t = ' ' + t;
    for (int i = n; i < 2 * n; i++)
    {
        string st = "";
        for (int j = n - 1; j >= 0; j--)
        {
            st += s[i - j];
        }
        if (st[0] != '0')
            v.push_back(st);
    }

    for (int i = m; i < 2 * m; i++)
    {
        string st = "";
        for (int j = m - 1; j >= 0; j--)
        {
            st += t[i - j];
        }
        if (st[0] != '0')
            v1.push_back(st);
    }

    sort(v.begin(), v.end()), sort(v1.begin(), v1.end());
    string ans = sub(v[v.size() - 1], v1[0]);
    // cout << v1[0] << endl;
    cout << ans << endl;
    /* code */
    return 0;
}
