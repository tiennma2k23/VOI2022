#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 1, inf = 1e15 + 1;
int sumx[maxn], x[maxn], sumy[maxn], y[maxn];
int n;

int calc(int pos)
{
    int res = 0;
    for (int i = 1; i <= n; i++)
        res += max(abs(x[i] - x[pos]), abs(y[i] - y[pos]));
    return res;
}

int32_t main()
{
    vector<int> v, vx, vy;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
        vx.push_back(x[i]);
        vy.push_back(y[i]);
    }
    vx.push_back(-inf), vy.push_back(-inf);
    sort(vx.begin(), vx.end()), sort(vy.begin(), vy.end());
    for (int i = 1; i < vx.size(); i++)
        sumx[i] = sumx[i - 1] + vx[i];
    for (int i = 1; i < vy.size(); i++)
        sumy[i] = sumy[i - 1] + vy[i];
    int ans = inf;
    vector<int> pos;
    for (int i = 1; i <= n; i++)
    {
        int res = 0;
        int posx = upper_bound(vx.begin(), vx.end(), x[i]) - vx.begin() - 1;
        res += posx * x[i] - sumx[posx] + (sumx[vx.size() - 1] - sumx[posx]) - (vx.size() - 1 - posx) * x[i];
        int posy = upper_bound(vy.begin(), vy.end(), y[i]) - vy.begin() - 1;
        res += posy * y[i] - sumy[posy] + (sumy[vy.size() - 1] - sumy[posy]) - (vy.size() - 1 - posy) * y[i];
        if (ans > res)
        {
            pos.clear();
            pos.push_back(i);
            ans = res;
        }
        else if (ans == res)
            pos.push_back(i);
        // cout << res << endl;
    }
    ans = inf;
    for (auto val : pos)
        ans = min(ans, calc(val));
    cout << ans << endl;
}