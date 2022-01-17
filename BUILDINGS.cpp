#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 1;
int a[maxn], n, L[maxn], R[maxn], cl[maxn];
int st[maxn][21], Log[maxn];
// void build(int id, int l, int r)
// {
//     if (l == r)
//     {
//         st[id] = a[l];
//         return;
//     }
//     int mid = (l + r) / 2;
//     build(id * 2, l, mid);
//     build(id * 2 + 1, mid + 1, r);
//     st[id] = max(st[id * 2], st[id * 2 + 1]);
// }
// int get(int id, int l, int r, int u, int v)
// {
//     if (v < l || r < u)
//     {
//         return 0;
//     }
//     if (u <= l && r <= v)
//     {
//         return st[id];
//     }
//     int mid = (l + r) / 2;
//     return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
// }
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
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
}
int get_max(int l, int r)
{
    int len = Log[r - l + 1];
    // cout << len << endl;
    return max(st[l][len], st[r - (1 << len) + 1][len]);
}
int find_l(int p, int val)
{
    int l = 1, r = p, pos = p;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (get_max(mid, p) <= val)
        {
            pos = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return pos;
}

int find_r(int p, int val)
{
    int l = p, r = n, pos = p;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (get_max(p, mid) <= val)
        {
            pos = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return pos;
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
    {
        cin >> a[i];
    }
    init();
    // build(1, 1, n);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        L[i] = i - 1;
        while (L[i] > 0 && a[L[i]] <= a[i])
            L[i] = L[L[i]];
    }
    for (int i = n; i >= 1; i--)
    {
        R[i] = i + 1;
        while (R[i] <= n && a[R[i]] <= a[i])
            R[i] = R[R[i]];
    }
    for (int i = 1; i <= n; i++)
    {
        sum += R[i] - L[i] - 1;
    }
    for (int i = 1; i <= n; i++)
    {
        int lo = 1, hi = L[i] - 1, pos = 0;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (get_max(mid, L[i] - 1) > a[i])
                pos = mid, lo = mid + 1;
            else
                hi = mid - 1;
        }
        cl[L[i]] += L[i] - pos;

        lo = R[i] + 1, hi = n;
        pos = n + 1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (get_max(R[i] + 1, mid) > a[i])
                pos = mid, hi = mid - 1;
            else
                lo = mid + 1;
        }
        cl[R[i]] += pos - R[i];
    }
    // cout << sum << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << sum - (R[i] - L[i] - 1) + 1 + cl[i] << '\n';
    }
}