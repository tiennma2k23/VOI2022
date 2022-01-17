#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 1, maxn = 2 * N;
int sum[N], fen[maxn];
void update(int p, int val)
{
    p += N;
    while (p < maxn)
    {
        fen[p] += val;
        p += (p & (-p));
    }
}
int get(int p)
{
    p += N;
    int res = 0;
    while (p > 0)
    {
        res += fen[p];
        p -= p & (-p);
    }
    return res;
}
int32_t main()
{
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (a >= x)
            sum[i] = sum[i - 1] + 1;
        else
            sum[i] = sum[i - 1];
    }
    update(0, 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += get(2 * sum[i] - i);
        update(2 * sum[i] - i, 1);
    }
    cout << ans << endl;
}