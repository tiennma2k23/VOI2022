#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 1;
int n;
int a[maxn];
int st[maxn][40], Log[maxn];
unordered_map<int, int> cnt;
void init()
{
    for (int i = 1; i <= n; i++)
    {
        st[i][0] = a[i];
    }
    int K = Log[n];
    for (int j = 1; j <= K; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            st[i][j] = __gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
}
int get(int l, int r)
{
    int len = Log[r - l + 1];
    // cout << len << endl;
    return __gcd(st[l][len], st[r - (1 << len) + 1][len]);
}
void prepare()
{
    for (int i = 1; i <= n; i++)
    {
        int l = i;
        while (l > 0)
        {
            int val = get(l, i);
            int lo = 1, hi = l, pos = l;
            while (lo <= hi)
            {
                int mid = (lo + hi) / 2;
                int tmp = get(mid, i);
                if (tmp >= val)
                    pos = mid, hi = mid - 1;
                else
                    lo = mid + 1;
            }
            cnt[val] += (l - pos + 1);
            l = pos - 1;
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int tmp = i;
        while (tmp > 1)
            tmp /= 2, Log[i]++;
    }
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    init();
    prepare();
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        cout << cnt[x] << '\n';
    }
}