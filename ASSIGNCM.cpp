#include <bits/stdc++.h>
// #define int long long
using namespace std;
stack<int> s[200005];
int cnt;
map<string, int> id;
int32_t main()
{
#define TASK "ASSIGNCM"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    for (int i = 1; i <= 200000; i++)
        s[i].push(0);
    string st;
    while (cin >> st)
    {
        if (st == "{")
        {
            for (int i = 1; i <= cnt; i++)
                s[i].push(s[i].top());
            continue;
        }

        else if (st == "}")
        {
            for (int i = 1; i <= cnt; i++)
                if (s[i].size())
                    s[i].pop();
            for (int i = 1; i <= cnt; i++)
                if (s[i].empty())
                    s[i].push(0);
            continue;
        }

        int pos;
        for (int i = 0; i < st.length(); i++)
        {
            if (st[i] == '=')
                pos = i;
        }

        if (st[pos + 1] >= '0' && st[pos + 1] <= '9' || st[pos + 1] == '-')
        {
            string ss;
            for (int i = 0; i < pos; i++)
                ss += st[i];
            int num = 0;
            bool ok = false;
            if (st[pos + 1] == '-')
                ok = true, pos++;

            for (int i = pos + 1; i < st.length(); i++)
                num = num * 10 + st[i] - '0';
            if (ok)
                num = -num;
            int pos = id[ss];
            if (!pos)
            {
                cnt++;
                id[ss] = cnt;
                pos = cnt;
                s[cnt].pop();
                s[cnt].push(num);
            }
            else
            {
                if (s[pos].size())
                    s[pos].pop();
                s[pos].push(num);
            }
        }

        else
        {
            string var1 = "", var2 = "";
            for (int i = 0; i < pos; i++)
                var1 += st[i];
            for (int i = pos + 1; i < st.length(); i++)
                var2 += st[i];
            int pos1 = id[var1], pos2 = id[var2];
            if (!pos2)
            {
                cnt++;
                pos2 = cnt;
                id[var2] = cnt;
                // s[cnt].push(0);
                if (!pos1)
                {
                    cnt++;
                    id[var1] = cnt;
                    pos1 = cnt;
                    s[cnt].push(0);
                }
                else
                {

                    if (s[pos1].size())
                        s[pos1].pop();
                    s[pos1].push(0);
                }
            }
            else
            {
                int val = 0;
                if (s[pos2].size())
                    val = s[pos2].top();
                if (!pos1)
                {
                    cnt++;
                    pos1 = cnt;
                    id[var1] = cnt;
                    s[cnt].push(val);
                }
                else
                {

                    if (s[pos1].size())
                        s[pos1].pop();
                    s[pos1].push(val);
                }
            }
            cout << s[pos1].top() << '\n';
        }
    }
}