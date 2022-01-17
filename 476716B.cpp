#include <bits/stdc++.h>
#define int long long
#define tp tuple<int, int, int, int>
#define II pair<int, int>
#define fi first
#define se second
using namespace std;
map<tp, II> mp;
const int maxn = 2505;
II fen[maxn][maxn];
void update(int r, int c, int val, int val2)
{
    while (r < maxn)
    {
        int c1 = c;
        while (c < maxn)
        {
            fen[r][c].fi += val;
            fen[r][c].se += val2;
            c += (c & (-c));
        }
        c = c1;
        r += (r & (-r));
    }
}

II get(int r, int c)
{
    int res1 = 0, res2 = 0;
    int r1 = r;
    while (r > 0)
    {
        int c1 = c;
        while (c > 0)
        {
            res1 += fen[r][c].fi;
            c -= (c & (-c));
        }
        c = c1;
        r -= (r & (-r));
    }
    r = r1;
    while (r > 0)
    {
        int c1 = c;
        while (c > 0)
        {
            res2 += fen[r][c].se;
            c -= (c & (-c));
        }
        c = c1;
        r -= (r & (-r));
    }
    return II(res1, res2);
}
int32_t main()
{
    srand(time(NULL));
    int n, m, q;
    cin >> n >> m >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            int i = rand();
            int i2 = rand();
            update(r1, c1, i, i2);
            update(r1, c2 + 1, -i, -i2);
            update(r2 + 1, c1, -i, -i2);
            update(r2 + 1, c2 + 1, i, i2);
            mp[{r1, c1, r2, c2}] = {i, i2};
        }
        else if (type == 2)
        {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            auto val = mp[{r1, c1, r2, c2}];
            update(r1, c1, -val.fi, -val.se);
            update(r1, c2 + 1, val.fi, val.se);
            update(r2 + 1, c1, val.fi, val.se);
            update(r2 + 1, c2 + 1, -val.fi, -val.se);
        }
        else
        {
            int r1, c1, c2, r2;
            cin >> r1 >> c1 >> r2 >> c2;
            II res1 = get(r1, c1), res2 = get(r2, c2);
            if (res1 == res2)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}