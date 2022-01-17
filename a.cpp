#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 1e9;
vector<int> v;
map<int, int> cnt;
void solve()
{
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int pos = 0;
    int t = 0;
    string s1 = "", ans = "";
    int l = 0;
    while (l < b.length())
    {
        t = 0;
        s1 = b[l] + s1;
        for (int j = 0; j < s1.length(); j++)
            t = t * 10 + s1[j] - '0';
        if (t >= a[pos] - '0')
        {
            if (t - (a[pos] - '0') >= 10)
            {
                cout << -1 << endl;
                return;
            }
            ans += char(t - (a[pos] - '0') + '0');
            pos++;
            s1 = "";
        }
        l++;
        if (pos == a.length())
            break;
    }
    while (l < b.length())
        ans += b[l], l++;
    if (pos == a.length())
    {
        reverse(ans.begin(), ans.end());

        while (ans.length() > 1 && ans[0] == '0')
            ans.erase(0, 1);
        cout << ans << endl;
    }
    else
        cout << -1 << endl;
}
int32_t main()
{

    int q;
    cin >> q;
    while (q--)
    {
        solve();
    }
}