#include <bits/stdc++.h>
#define int long long
using namespace std;
set<int> pos[10];
const int inf = 1e9;
int32_t main()
{
    freopen("NUMBER.inp", "r", stdin);
    freopen("NUMBER.out", "w", stdout);
    string s, ans = "";
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        pos[s[i] - '0'].insert(i);
    }
    bool ok = false;
    int cnt = 0;
    while (!ok)
    {
        cnt++;
        int tmp = -1, cs = -1, sz = inf;
        if (cnt == 1)
        {
            for (int i = 1; i <= 9; i++)
            {
                if (pos[i].size() == 0)
                {
                    ok = true;
                    cout << i;
                    return 0;
                }
                else
                {
                    sz = min(sz, 1ll * pos[i].size());
                }
            }
            vector<int> v;
            for (int i = 1; i <= 9; i++)
                if (pos[i].size() == sz)
                    v.push_back(i);
            // for (auto val : v)
            // {
            //     if (*pos[val].begin() > tmp)
            //         tmp = *pos[val].begin(), cs = val;
            // }
            tmp = *pos[v[0]].begin();
            cs = v[0];
            cout << cs;
            for (int i = 1; i <= 9; i++)
            {
                while (pos[i].size() && (*pos[i].begin() <= tmp))
                    pos[i].erase(pos[i].begin());
            }
        }
        else
        {
            for (int i = 0; i <= 9; i++)
            {
                if (pos[i].size() == 0)
                {
                    ok = true;
                    cout << i;
                    return 0;
                }
                else
                {
                    sz = min(sz, 1ll * pos[i].size());
                }
            }
            vector<int> v;
            for (int i = 0; i <= 9; i++)
                if (pos[i].size() == sz)
                    v.push_back(i);
            // for (auto val : v)
            // {
            //     if (*pos[val].begin() > tmp)
            //         tmp = *pos[val].begin(), cs = val;
            // }
            tmp = *pos[v[0]].begin();
            cs = v[0];
            cout << cs;
            for (int i = 0; i <= 9; i++)
            {
                while (pos[i].size() && (*pos[i].begin() <= tmp))
                    pos[i].erase(pos[i].begin());
            }
        }
    }
}