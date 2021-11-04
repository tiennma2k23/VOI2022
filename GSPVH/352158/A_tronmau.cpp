//https://gspvh21.contest.codeforces.com/group/ABXsSubxJG/contest/352158/problem/A
#include <bits/stdc++.h>
#define int long long
using namespace std;
map<string, int> pos;
int32_t main()
{
#define TASK "color"
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    string co[6] = {"Red", "Orange", "Yellow", "Green", "Blue", "Violet"};
    pos["Red"] = 0;
    pos["Orange"] = 1;
    pos["Yellow"] = 2;
    pos["Green"] = 3;
    pos["Blue"] = 4;
    pos["Violet"] = 5;
    string s, s1;
    cin >> s >> s1;
    int tmp = abs(pos[s] - pos[s1]);
    if (pos[s] < pos[s1])
        swap(s, s1);
    if (tmp == 0)
        cout << "Same" << endl;
    else if (tmp == 1 || tmp == 5)
        cout << "Adjacent" << endl;
    else if (tmp == 2 || tmp == 4)
    {
        if (tmp == 4)
        {
            if (pos[s] == 5)
                cout << co[0] << endl;
            else
                cout << co[5] << endl;
        }
        else
        {
            int p = min(pos[s], pos[s1]) + 1;
            cout << co[p] << endl;
        }
    }
    else if (tmp == 3)
    {
        cout << "Complementary" << endl;
    }
}