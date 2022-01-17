#include <bits/stdc++.h>
#define int long long
using namespace std;
int ans = 0;
char a[60][60];
int n;
void solve(int x, int y)
{
    if (x < n)
    {
        if (a[x + 1][y] != a[x][y])
        {
            swap(a[x + 1][y], a[x][y]);
            int cnt1 = 0, cnt2 = 0;
            for (int i = 1; i <= n; i++)
            {
                cnt1 = 0;
                for (int j = 1; j <= n; j++)
                {
                    if (a[i][j] == a[i][j - 1])
                        cnt1++;
                    else
                        cnt1 = 1;
                    ans = max(ans, cnt1);
                }
            }
            for (int j = 1; j <= n; j++)
            {
                cnt2 = 0;
                for (int i = 1; i <= n; i++)
                {
                    if (a[i - 1][j] == a[i][j])
                        cnt2++;
                    else
                        cnt2 = 1;
                    ans = max(ans, cnt2);
                }
            }
            swap(a[x + 1][y], a[x][y]);
        }
    }
    if (x > 1)
    {
        if (a[x - 1][y] != a[x][y])
        {
            swap(a[x - 1][y], a[x][y]);
            int cnt1 = 0, cnt2 = 0;
            for (int i = 1; i <= n; i++)
            {
                cnt1 = 0;
                for (int j = 1; j <= n; j++)
                {
                    if (a[i][j] == a[i][j - 1])
                        cnt1++;
                    else
                        cnt1 = 1;
                    ans = max(ans, cnt1);
                }
            }
            for (int j = 1; j <= n; j++)
            {
                cnt2 = 0;
                for (int i = 1; i <= n; i++)
                {
                    if (a[i - 1][j] == a[i][j])
                        cnt2++;
                    else
                        cnt2 = 1;
                    ans = max(ans, cnt2);
                }
            }
            swap(a[x - 1][y], a[x][y]);
        }
    }

    if (y > 1)
    {
        if (a[x][y - 1] != a[x][y])
        {
            swap(a[x][y - 1], a[x][y]);
            int cnt1 = 0, cnt2 = 0;
            for (int i = 1; i <= n; i++)
            {
                cnt1 = 0;
                for (int j = 1; j <= n; j++)
                {
                    if (a[i][j] == a[i][j - 1])
                        cnt1++;
                    else
                        cnt1 = 1;
                    ans = max(ans, cnt1);
                }
            }
            for (int j = 1; j <= n; j++)
            {
                cnt2 = 0;
                for (int i = 1; i <= n; i++)
                {
                    if (a[i - 1][j] == a[i][j])
                        cnt2++;
                    else
                        cnt2 = 1;
                    ans = max(ans, cnt2);
                }
            }
            swap(a[x][y - 1], a[x][y]);
        }
    }

    if (y < n)
    {
        if (a[x][y + 1] != a[x][y])
        {
            swap(a[x][y + 1], a[x][y]);
            int cnt1 = 0, cnt2 = 0;
            for (int i = 1; i <= n; i++)
            {
                cnt1 = 0;
                for (int j = 1; j <= n; j++)
                {
                    if (a[i][j] == a[i][j - 1])
                        cnt1++;
                    else
                        cnt1 = 1;
                    ans = max(ans, cnt1);
                }
            }
            for (int j = 1; j <= n; j++)
            {
                cnt2 = 0;
                for (int i = 1; i <= n; i++)
                {
                    if (a[i - 1][j] == a[i][j])
                        cnt2++;
                    else
                        cnt2 = 1;
                    ans = max(ans, cnt2);
                }
            }
            swap(a[x][y + 1], a[x][y]);
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("CANDY.inp", "r", stdin);
    freopen("CANDY.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            solve(i, j);
        }
    cout << ans << endl;
}