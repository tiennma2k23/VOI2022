#include <bits/stdc++.h>
#define int long long
#define II pair<int, int>
#define fi first
#define se second
using namespace std;
const int maxn = 2e3 + 1, maxm = 3e5 + 1, inf = 1e14 + 1;
int sum[maxn], a[maxn], s[maxm], Log[maxn];

struct NNodes
{
    int _max, _min;
};
NNodes st[maxn][13];
int n, m;
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
        st[i][0]._min = sum[i], st[i][0]._max = sum[i];
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

void sub1()
{
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + a[i];
    }
    init();
    for (int i = 1; i <= m; i++)
    {
        int k = s[i];
        int l = 1, r = n, ans = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            bool ok = false;
            int minn = get_min(1, mid);
            if (minn + k >= 0)
                ok = true;
            minn = get_min(n - mid + 1, n);
            minn -= sum[n - mid];
            if (minn + k >= 0)
                ok = true;
            if (ok)
                l = mid + 1, ans = mid;
            else
                r = mid - 1;
        }
        cout << ans << ' ';
    }
}
const int N = 1048580;
int fen[N];
void update(int pos, int val)
{
    while (pos > 0)
    {
        fen[pos] = max(fen[pos], val);
        pos -= (pos & (-pos));
    }
}
int get(int pos)
{
    int res = 0;
    while (pos < N)
    {
        res = max(res, fen[pos]);
        pos += (pos & (-pos));
    }
    return res;
}
void sub2()
{
    // set<int> st;
    vector<int> v;
    vector<II> vec;
    int sz = 1 << n;
    for (int mask = 0; mask < sz; mask++)
    {
        int minn = inf, sum = 0;
        for (int j = 1; j <= n; j++)
        {
            int i = j - 1;
            if (mask & (1 << i))
            {
                sum += a[j];
                minn = min(minn, sum);
            }
        }
        v.push_back(minn);
        vec.push_back({minn, __builtin_popcount(mask)});
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (auto val : vec)
    {
        int pos = lower_bound(v.begin(), v.end(), val.fi) - v.begin() + 1;
        update(pos, val.se);
    }

    for (int i = 1; i <= m; i++)
    {
        int pos = lower_bound(v.begin(), v.end(), -s[i]) - v.begin() + 1;
        cout << get(pos) << ' ';
    }
}
void sub4()
{
    for (int i = 1; i <= m; i++)
    {
        int curr = s[i];
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int j = 1; j <= n; j++)
        {
            curr += a[j];
            pq.push(a[j]);
            if (!pq.empty() && curr < 0)
            {
                curr -= pq.top();
                pq.pop();
            }
        }
        cout << pq.size() << " ";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int tmp = i;
        while (tmp > 1)
            tmp /= 2, Log[i]++;
    }
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = 1; j <= m; j++)
        cin >> s[j];
    int c1 = 0, c2 = 0;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] <= a[i - 1])
            c1++;
        if (a[i] >= a[i - 1])
            c2++;
    }
    if (c1 == n - 1 || c2 == n - 1)
        sub1();
    else if (n <= 20)
        sub2();
    else
        sub4();
}