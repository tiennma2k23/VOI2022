#include <bits/stdc++.h>
using namespace std;
char cc[2001];
int32_t main()
{
    int m, n, p;
    cin >> m >> n >> p;
    if (m == 1)
    {
        int t = 0, cnt0 = 0, cnt9 = 0;
        for (int i = 1; i <= n; i++)
        {
            char ch;
            cin >> ch;
            cc[i] = ch;
            t = (t * 10 + ch - '0') % p;
            if (ch - '0' == 0)
                cnt0++;
            if (ch - '0' == 0)
                cnt9++;
        }
        int t1 = t;
        int minn1 = min((p - t1) / 9, cnt0);
        int cnt1 = minn1 + (p - t1 - minn1 * 9);

        t1 = t;
        int minn2 = min((t1) / 9, cnt9);
        int cnt2 = minn2 + (t1 - minn2 * 9);
        if (cnt1 <= cnt2)
        {
            int tmp = cnt1 - minn1;
            for (int i = 1; i <= n; i++)
            {
                if (tmp > 0)
                {
                    if (cc[i] > '0' && cc[i] < '9')
                        cc[i]++;
                    tmp--;
                }
                if (cnt0 > 0)
                {
                    if (cc[i] == '0')
                        cc[i] = '9';
                    cnt0--;
                }
            }
            cout << cnt1 << endl;
            for (int i = 1; i <= n; i++)
                cout << cc[i];
        }
        else
        {
            int tmp = cnt2 - minn2;
            for (int i = 1; i <= n; i++)
            {
                if (tmp > 0)
                {
                    if (cc[i] > '0' && cc[i] < '9')
                        cc[i]--;
                    tmp--;
                }
                if (cnt9 > 0)
                {
                    if (cc[i] == '9')
                        cc[i] = '0';
                    cnt9--;
                }
            }
            cout << cnt2 << endl;
            for (int i = 1; i <= n; i++)
                cout << cc[i];
        }
    }
}