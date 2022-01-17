#include <bits/stdc++.h>
// #define int long long
#define fi first
#define se second
#define endl '\n'
#define II pair<long long, long long>
using namespace std;

const long long maxn = 1e5 + 123;
const long long inf = 1e18;

long long x[maxn], _[maxn], _________b[maxn], ______________[maxn], d[maxn], h[maxn];
vector<long long> _r[maxn];
vector<vector<tuple<long long, long long, long long>>> gr[maxn];
vector<long long> f[maxn];

void solve()
{
    int n, m, k;
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> x[i];
    }
    for (int i = 1; i <= m; i++)
        _r[i].clear();

    vector<II> _______;
    _______.push_back({1, 1});
    _______.push_back({m, n});
    _r[1].push_back(1);
    _r[m].push_back(n);
    for (int i = 1; i <= k; i++)
    {
        cin >> _[i] >> _________b[i] >> ______________[i] >> d[i] >> h[i];
        _r[_[i]].push_back(_________b[i]);
        _r[______________[i]].push_back(d[i]);
        _______.push_back({_[i], _________b[i]});
        _______.push_back({______________[i], d[i]});
    }
    sort(_______.begin(), _______.end());
    _______.resize(unique(_______.begin(), _______.end()) - _______.begin());

    for (int i = 1; i <= m; i++)
    {
        sort(_r[i].begin(), _r[i].end());
        _r[i].resize(unique(_r[i].begin(), _r[i].end()) - _r[i].begin());
        gr[i].clear();
        gr[i].resize(_r[i].size());
        f[i].clear();
        f[i].assign(int(_r[i].size()), -inf);
    }

    for (int i = 1; i <= k; i++)
    {
        int it = lower_bound(_r[_[i]].begin(), _r[_[i]].end(), _________b[i]) - _r[_[i]].begin();
        int it2 = lower_bound(_r[______________[i]].begin(), _r[______________[i]].end(), d[i]) - _r[______________[i]].begin();
        gr[_[i]][it].push_back({______________[i], it2, h[i]});
    }

    f[1][0] = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= int(_r[i].size()) - 1; ++j)
            if (f[i][j - 1] != -inf)
                f[i][j] = max(f[i][j], f[i][j - 1] - 1ll * x[i] * (_r[i][j] - _r[i][j - 1]));
        for (int j = int(_r[i].size()) - 2; j >= 0; --j)
            if (f[i][j + 1] != -inf)
                f[i][j] = max(f[i][j], f[i][j + 1] - 1ll * x[i] * (_r[i][j + 1] - _r[i][j]));

        for (int j = 0; j <= int(_r[i].size()) - 1; ++j)
        {
            if (f[i][j] != -inf)
            {
                int to0, to1, to2;
                for (auto val : gr[i][j])
                {
                    tie(to0, to1, to2) = val;
                    f[to0][to1] = max(f[to0][to1], f[i][j] + to2);
                }
            }
        }
    }

    int sz = _r[m].size();
    if (f[m][sz - 1] != -inf)
        cout << -f[m][sz - 1] << endl;
    else
        cout << "NO ESCAPE" << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}