#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5, inf = 1e9 + 1;
int a[maxn], le[maxn], ri[maxn], Log[maxn];
int n;
struct nodes
{
    int _max, _min;
};
nodes st[maxn][40];
void init()
{
    // int len = 0, tmp = 1;
    // while (tmp * 2 <= n)
    // {
    //     tmp *= 2;
    //     len++;
    // }
    for (int i = 1; i <= n; i++)
    {
        st[i][0]._min = a[i], st[i][0]._max = a[i];
    }
    int K = Log[n];
    for (int j = 1; j <= K; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            st[i][j]._min = min(st[i][j - 1]._min, st[i + (1 << (j - 1))][j - 1]._min);
            st[i][j]._max = max(st[i][j - 1]._max, st[i + (1 << (j - 1))][j - 1]._max);
        }
}
int get_max(int l, int r)
{
    int len = Log[r - l + 1];
    // cout << len << endl;
    return max(st[l][len]._max, st[r - (1 << len) + 1][len]._max);
}

int get_min(int l, int r)
{
    int len = Log[r - l + 1];
    return min(st[l][len]._min, st[r - (1 << len) + 1][len]._min);
}
int32_t main()
{
    // freopen("input", "r", stdin);
    // freopen("output", "w", stdout);
    int k;
    cin >> n >> k;
    if (k < 0)
    {
        cout << n + 1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        int tmp = i;
        while (tmp > 1)
            tmp /= 2, Log[i]++;
    }
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    k = abs(k);
    init();
    for (int i = 1; i <= n; i++)
    {
        int l = 1, r = i;
        le[i] = le[i - 1];
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int maxx = get_max(mid, i), minn = get_min(mid, i);
            if (maxx - minn <= k)
            {
                le[i] = max(le[i], i - mid + 1);
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
    }
    for (int i = n; i >= 1; i--)
    {
        int l = i, r = n;
        ri[i] = ri[i + 1];
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int maxx = get_max(i, mid), minn = get_min(i, mid);
            if (maxx - minn <= k)
            {
                ri[i] = max(ri[i], mid - i + 1), l = mid + 1;
            }
            else
                r = mid - 1;
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans = max(ans, le[i] + ri[i + 1]);
        ans = max(ans, le[i]);
    }
    cout << ans << endl;
}