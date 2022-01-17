#include <bits/stdc++.h>
// #define ll long long
using namespace std;
const int maxn = 5001, inf = 1e9 + 1;
int n, m;
int okc[maxn][maxn], okr[maxn][maxn];
namespace sub4
{
    // không thể ghép âm với dương,0 với khác 0 nên các TH có thể xảy ra là
    //  + i, j toàn 0 or cùng âm or cùng dương + i, j toàn 0->ok[i][j] = true;
    //  + i, j toàn âm hoặc toàn dương chỉ tồn tại 1 k duy nhất để get_sum(i, k) = get_sum(k + 1, j);
    int r[maxn], c[maxn];
    int sumr[maxn], sumc[maxn];
    int fc[maxn], fr[maxn], Log[maxn];
    struct nodes
    {
        int _min, _max;
    } stc[maxn][20], str[maxn][20];
    int get_sumr(int i, int j) { return sumr[j] - sumr[i - 1]; }
    int get_sumc(int i, int j) { return sumc[j] - sumc[i - 1]; }
    void init_sparsetable()
    {
        for (int i = 1; i <= m; i++)
        {
            str[i][0]._min = r[i], str[i][0]._max = r[i];
        }
        int K = Log[m];
        for (int j = 1; j <= K; j++)
            for (int i = 1; i + (1 << j) - 1 <= m; i++)
            {
                str[i][j]._min = min(str[i][j - 1]._min, str[i + (1 << (j - 1))][j - 1]._min);
                str[i][j]._max = max(str[i][j - 1]._max, str[i + (1 << (j - 1))][j - 1]._max);
            }

        for (int i = 1; i <= n; i++)
        {
            stc[i][0]._min = c[i], stc[i][0]._max = c[i];
        }

        K = Log[n];
        for (int j = 1; j <= K; j++)
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
            {
                stc[i][j]._min = min(stc[i][j - 1]._min, stc[i + (1 << (j - 1))][j - 1]._min);
                stc[i][j]._max = max(stc[i][j - 1]._max, stc[i + (1 << (j - 1))][j - 1]._max);
            }
    }
    nodes getr(int r, int l)
    {
        int len = Log[r - l + 1];
        // cout << len << endl;
        int maxx = max(str[l][len]._max, str[r - (1 << len) + 1][len]._max);
        int minn = min(str[l][len]._min, str[r - (1 << len) + 1][len]._min);
        return {minn, maxx};
    }
    nodes getc(int r, int l)
    {
        int len = Log[r - l + 1];
        // cout << len << endl;
        int maxx = max(stc[l][len]._max, stc[r - (1 << len) + 1][len]._max);
        int minn = min(stc[l][len]._min, stc[r - (1 << len) + 1][len]._min);
        return {minn, maxx};
    }
    bool checkr(int i, int j)
    {
        if (okr[i][j] != -1)
            return okr[i][j];
        if (i > j)
            return false;
        if (i == j)
        {
            okr[i][j] = 1;
            return 1;
        }
        // for (int k = i; k < j; k++)
        // {
        //     if (checkr(i, k) && checkr(k + 1, j) && get_sumr(i, k) == get_sumr(k + 1, j))
        //     {
        //         okr[i][j] = 1;
        //         return 1;
        //     }
        // }
        nodes tmp = getr(i, j);
        if (tmp._min == 0 && tmp._max == 0)
        {
            okr[i][j] = 1;
            return 1;
        }
        else if (tmp._min > 0 && tmp._max > 0)
        {
            int l = i, r = j, k = -1;
            int sum = get_sumr(i, j);
            while (l <= r)
            {
                int mid = (l + r) / 2;
                int s_mid = get_sumr(i, mid);
                if (s_mid * 2 <= sum)
                    k = mid, l = mid + 1;
                else
                    r = mid - 1;
            }
            if (k != -1 && get_sumr(i, k) == get_sumr(k + 1, j))
            {
                if (checkr(i, k) && checkr(k + 1, j))
                {
                    okr[i][j] = 1;
                    return 1;
                }
            }
        }
        else if (tmp._min < 0 && tmp._max < 0)
        {
            int l = i, r = j, k = -1;
            int sum = get_sumr(i, j);
            while (l <= r)
            {
                int mid = (l + r) / 2;
                int s_mid = get_sumr(i, mid);
                if (s_mid * 2 >= sum)
                    k = mid, l = mid + 1;
                else
                    r = mid - 1;
            }
            if (k != -1 && get_sumr(i, k) == get_sumr(k + 1, j))
            {
                if (checkr(i, k) && checkr(k + 1, j))
                {
                    okr[i][j] = 1;
                    return 1;
                }
            }
        }
        okr[i][j] = 0;
        return 0;
    }

    bool checkc(int i, int j)
    {
        if (okc[i][j] != -1)
            return okc[i][j];
        if (i > j)
            return false;
        if (i == j)
        {
            okc[i][j] = 1;
            return 1;
        }
        // for (int k = i; k < j; k++)
        // {
        //     if (checkc(i, k) && checkc(k + 1, j) && get_sumr(i, k) == get_sumr(k + 1, j))
        //     {
        //         okc[i][j] = 1;
        //         return 1;
        //     }
        // }
        nodes tmp = getc(i, j);
        if (tmp._min == 0 && tmp._max == 0)
        {
            okc[i][j] = 1;
            return 1;
        }
        else if (tmp._min > 0 && tmp._max > 0)
        {
            int l = i, r = j, k = -1;
            int sum = get_sumc(i, j);
            while (l <= r)
            {
                int mid = (l + r) / 2;
                int s_mid = get_sumc(i, mid);
                if (s_mid * 2 <= sum)
                    k = mid, l = mid + 1;
                else
                    r = mid - 1;
            }
            if (k != -1 && get_sumc(i, k) == get_sumc(k + 1, j))
            {
                if (checkc(i, k) && checkc(k + 1, j))
                {
                    okc[i][j] = 1;
                    return 1;
                }
            }
        }
        else if (tmp._min < 0 && tmp._max < 0)
        {
            int l = i, r = j, k = -1;
            int sum = get_sumc(i, j);
            while (l <= r)
            {
                int mid = (l + r) / 2;
                int s_mid = get_sumc(i, mid);
                if (s_mid * 2 >= sum)
                    k = mid, l = mid + 1;
                else
                    r = mid - 1;
            }
            if (k != -1 && get_sumc(i, k) == get_sumc(k + 1, j))
            {
                if (checkc(i, k) && checkc(k + 1, j))
                {
                    okc[i][j] = 1;
                    return 1;
                }
            }
        }
        okc[i][j] = 0;
        return 0;
    }

    void solve()
    {
        for (int i = 1; i < maxn; i++)
        {
            int tmp = i;
            while (tmp > 1)
                tmp /= 2, Log[i]++;
        }
        int a;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
                cin >> a, r[i] += a, c[j] += a;
        }
        init_sparsetable();
        for (int i = 1; i <= m; i++)
            sumr[i] = sumr[i - 1] + r[i];
        for (int j = 1; j <= n; j++)
            sumc[j] = sumc[j - 1] + c[j];

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= m; j++)
                okr[i][j] = -1, fr[i] = inf;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                okc[i][j] = -1, fc[i] = inf;
        // calc r
        for (int i = 1; i <= m; i++)
        {
            for (int j = i; j >= 1; j--)
                if (checkr(j, i))
                    fr[i] = min(fr[j - 1] + 1, fr[i]);
        }
        // calc c
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j >= 1; j--)
                if (checkc(j, i))
                    fc[i] = min(fc[j - 1] + 1, fc[i]);
        }
        cout << fc[n] * fr[m] << endl;
        // cout << fc[n] << ' ' << fr[m] << endl;
    }

}

// namespace full
// {
//     const int N = 1e6 + 1;
//     int r[N], c[N];
// #define II pair<int, int>
//     II rr[N], cc[N];
//     int fr[N], dpr[N][39], fc[N], dpc[N][39];
//     void solve()
//     {
//         for (int i = 1; i <= m; i++)
//         {
//             for (int j = 1; j <= n; j++)
//             {
//                 int x;
//                 cin >> x;
//                 r[i] += x;
//                 c[j] += x;
//             }
//         }

//         // calc r
//         for (int i = 1; i <= m; i++)
//         {
//             int tmp = 1, cnt = 0;
//             while (r[i] % tmp == 0)
//             {
//                 tmp *= 2;
//                 cnt++;
//             }
//             cnt--;
//             tmp /= 2;
//             rr[i] = II(r[i] / tmp, cnt);
//         }
//         for (int i = 1; i <= m; i++)
//             for (int j = 0; j <= 38; j++)
//                 dpr[i][j] = -1;
//         // for (int i = 1; i <= m; i++)
//         // dpr[i][rr[i].second] = i;
//         int pos = 1;
//         for (int i = 1; i <= m; i++)
//         {
//             // cout << r[i] << ' ';
//             fr[i] = fr[i - 1] + 1;
//             if (rr[i].first != rr[pos].first)
//                 pos = i;
//             for (int x = 1; x <= 38; x++)
//             {
//                 if (dpr[i - 1][x - 1] != -1 && dpr[i - 1][x - 1] >= pos)
//                 {
//                     dpr[i][x] = dpr[dpr[i - 1][x - 1]][x - 1];
//                     // cout << i << ' ' << x << ' ' << dpr[i][x] << endl;
//                     if (dpr[i][x] != -1)
//                         fr[i] = min(fr[dpr[i][x] - 1] + 1, fr[i]);
//                 }
//             }
//             dpr[i][rr[i].second] = i;
//             // cout << fr[i] << ' ';
//         }
//         // cout << endl;
//         // calc c
//         for (int i = 1; i <= n; i++)
//         {
//             int tmp = 1, cnt = 0;
//             while (c[i] % tmp == 0)
//             {
//                 tmp *= 2;
//                 cnt++;
//             }
//             cnt--;
//             tmp /= 2;
//             cc[i] = II(c[i] / tmp, cnt);
//         }

//         for (int i = 1; i <= n; i++)
//             for (int j = 0; j <= 38; j++)
//                 dpc[i][j] = -1;
//         // for (int i = 1; i <= n; i++)
//         //     dpc[i][cc[i].second] = i;
//         pos = 1;
//         for (int i = 1; i <= n; i++)
//         {
//             // cout << c[i] << ' ';
//             fc[i] = fc[i - 1] + 1;
//             if (cc[i].first != cc[pos].first)
//                 pos = i;
//             for (int x = 1; x <= 38; x++)
//             {
//                 if (dpc[i - 1][x - 1] != -1 && dpc[i - 1][x - 1] >= pos)
//                 {
//                     dpc[i][x] = dpc[dpc[i - 1][x - 1]][x - 1];
//                     if (dpc[i][x] != -1)
//                         fc[i] = min(fc[dpc[i][x] - 1] + 1, fc[i]);
//                 }
//             }
//             dpc[i][cc[i].second] = i;
//         }
//         // cout << endl;
//         cout << fc[n] * fr[m] << endl;
//     }
// }

int32_t main()
{
    cin >> m >> n;
    // ok.resize(n + 1), a.resize(m + 1), okr.resize(m + 1), okc.resize(n + 1);
    // for (int i = 0; i <= m; i++)
    // {
    //     a[i].resize(m + 1), okr[i].resize(m + 1);
    // }
    // for (int i = 0; i <= n; i++)
    // {
    //     ok[i].resize(m + 1), okc[i].resize(m + 1);
    // }
    sub4::solve();
}