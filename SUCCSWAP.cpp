#include <bits/stdc++.h>
#define int long long
using namespace std;
set<int> pos[30];
const int maxn = 1e6 + 1;
int fen[maxn];
void update(int p, int val)
{
    while (p > 0)
    {
        fen[p] += val;
        p -= p & (-p);
    }
}
int get(int p)
{
    int res = 0;
    p++;
    while (p < maxn)
    {
        res += fen[p];
        p += p & (-p);
    }
    return res;
}
int32_t main()
{
#define TASK "succswap"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        pos[ch - 'A'].insert(i);
    }
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        int p = *pos[ch - 'A'].begin();
        // cout << p << endl;
        pos[ch - 'A'].erase(pos[ch - 'A'].begin());
        ans += get(p);
        update(p, 1);
    }
    cout << ans << endl;
}