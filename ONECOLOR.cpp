#include <bits/stdc++.h>
#define int long long
#define II pair<int, int>
#define fi first
#define se second
using namespace std;
const int maxn = 501;
int cnt[maxn][3], vs[maxn][3];
int a[maxn][maxn], b[maxn][maxn];
int n, m;
bool ok(int x)
{
    vector<II> ans;
    queue<II> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            b[i][j] = a[i][j];

    for (int i = 1; i <= n; i++)
        cnt[i][0] = vs[i][0] = 0;
    for (int j = 1; j <= m; j++)
        cnt[j][1] = vs[j][1] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cnt[i][0] += (b[i][j] == x);
            if (cnt[i][0] > m / 2 && !vs[i][0])
            {
                q.push({i, 0ll});
                vs[i][0] = true;
            }
        }
    }

    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            cnt[j][1] += (b[i][j] == x);
            if (cnt[j][1] > n / 2 && !vs[j][1])
            {
                q.push({j, 1ll});
                vs[j][1] = true;
            }
        }
    }

    while (!q.empty())
    {
        int id = q.front().fi, typ = q.front().se;
        ans.push_back(q.front());
        q.pop();
        if (typ)
        {
            for (int i = 1; i <= n; i++)
                if (b[i][id] != x)
                {
                    b[i][id] = x;
                    cnt[i][0]++;
                    if (cnt[i][0] > m / 2 && !vs[i][0])
                        q.push({i, 0}), vs[i][0] = true;
                }
            // for (int i = 1; i <= n; i++)
            //     for (int j = 1; j <= m; j++)
            //         cout << b[i][j] << endl;
            // cout << "a" << endl;
        }
        else
        {
            for (int j = 1; j <= m; j++)
            {
                if (b[id][j] != x)
                {
                    b[id][j] = x;
                    cnt[j][1]++;
                    if (cnt[j][1] > n / 2 && !vs[j][1])
                    {
                        q.push({j, 1}), vs[j][1] = true;
                    }
                }
            }
            // for (int i = 1; i <= n; i++)
            //     for (int j = 1; j <= m; j++)
            //         cout << b[i][j] << endl;
        }
    }

    if (ans.size() <= 1000)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (b[i][j] != x)
                    return false;
        cout << ans.size() << endl;
        for (auto val : ans)
        {
            if (val.se == 0)
                cout << 'R' << ' ' << val.fi << '\n';
            else
                cout << 'C' << ' ' << val.fi << '\n';
        }
        return true;
    }
    return false;
}

int32_t main()
{
#define TASK "ONECOLOR"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    set<int> st;

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++)
    {
        unordered_map<int, int> dem;
        for (int j = 1; j <= m; j++)
        {
            dem[a[i][j]]++;
            if (dem[a[i][j]] > m / 2)
                st.insert(a[i][j]);
        }
    }
    for (int j = 1; j <= m; j++)
    {
        unordered_map<int, int> dem;
        for (int i = 1; i <= n; i++)
        {
            dem[a[i][j]]++;
            if (dem[a[i][j]] > n / 2)
                st.insert(a[i][j]);
        }
    }

    for (auto val : st)
    {
        if (ok(val))
            return 0;
    }
    cout << -1 << endl;
}