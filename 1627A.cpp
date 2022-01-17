#include <bits/stdc++.h>
using namespace std;
void solve()

{
    int n, m, r, c;
    int cntB = 0, cnt1 = 0, cnt2 = 0;
    char ch;
    cin >> n >> m >> r >> c;
    bool ok = false;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> ch;
            if (ch == 'B')
                cntB++;
            if (i == r && ch == 'B')
                cnt1++;
            if (j == c && ch == 'B')
                cnt2++;
            if (i == r && j == c && ch == 'B')
                ok = true;
        }
    }
    if (ok)
        cout << 0 << endl;
    else if (cntB == 0)
        cout << -1 << endl;
    else if (cnt1 == 0 && cnt2 == 0)
    {
        cout << 2 << endl;
    }
    else
        cout << 1 << endl;
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