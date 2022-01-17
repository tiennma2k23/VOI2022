#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 301;
char ch[maxn][maxn];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> ch[i][j];
    if (n % 2)
        cout << 'A' << '\n';
    else
        cout << 'B' << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#define TASK "GAMEBW"
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    int q;
    while (q--)
    {
        solve();
    }
}