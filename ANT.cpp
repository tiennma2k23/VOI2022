#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 1;
int x[maxn], y[maxn], _x[maxn], _y[maxn];
set<int> stx, sty, grx[maxn], gry[maxn];
vector<int> vx, vy;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("ANT.inp", "r", stdin);
    freopen("ANT.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
        stx.insert(x[i]);
        sty.insert(y[i]);
    }
    for (auto val : stx)
        vx.push_back(val);
    for (auto val : sty)
        vy.push_back(val);
    for (int i = 1; i <= n; i++)
    {
        int posx = lower_bound(vx.begin(), vx.end(), x[i]) - vx.begin() + 1;
        int posy = lower_bound(vy.begin(), vy.end(), y[i]) - vy.begin() + 1;
        _x[posx] = x[i];
        _y[posy] = y[i];
        grx[posx].insert(posy);
        gry[posy].insert(posx);
    }
    int xx = 0, yy = 0;
    while (m--)
    {
        char ch;
        cin >> ch;
        if (ch == 'D')
        {
            int posx = lower_bound(vx.begin(), vx.end(), xx) - vx.begin() + 1;
            int posy = lower_bound(vy.begin(), vy.end(), yy) - vy.begin() + 1;
            auto it = grx[posx].lower_bound(posy);
            it--;
            int _yy = *it;
            yy = _y[_yy];
            // gry[_yy].erase(gry[_yy].find(posx));
            // grx[posx].erase(it);
        }
        else if (ch == 'U')
        {
            int posx = lower_bound(vx.begin(), vx.end(), xx) - vx.begin() + 1;
            int posy = lower_bound(vy.begin(), vy.end(), yy) - vy.begin() + 1;
            auto it = grx[posx].upper_bound(posy);
            // it--;
            int _yy = *it;
            yy = _y[_yy];
            // gry[_yy].erase(gry[_yy].find(posx));
            // grx[posx].erase(it);
        }
        else if (ch == 'L')
        {
            int posx = lower_bound(vx.begin(), vx.end(), xx) - vx.begin() + 1;
            int posy = lower_bound(vy.begin(), vy.end(), yy) - vy.begin() + 1;
            auto it = gry[posy].lower_bound(posx);
            it--;
            int _xx = *it;
            xx = _x[_xx];
            // grx[_xx].erase(grx[_xx].find(posy));
            // gry[posy].erase(it);
        }
        else
        {
            int posx = lower_bound(vx.begin(), vx.end(), xx) - vx.begin() + 1;
            int posy = lower_bound(vy.begin(), vy.end(), yy) - vy.begin() + 1;
            auto it = gry[posy].upper_bound(posx);
            // it--;
            int _xx = *it;
            xx = _x[_xx];
            // grx[_xx].erase(grx[_xx].find(posy));
            // gry[posy].erase(it);
        }
        // cout << ch << endl;
    }
    cout << xx << ' ' << yy << endl;
}
// 10 6
// 0 0
// 1 1
// 2 1
// 0 2
// -1 2
// -1 3
// 2 3
// 2 4
// 4 3
// 2 -1
// ULURDL