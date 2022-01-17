#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 110, inf = 1e9 + 1;
int f[maxn][maxn][5][5];
int32_t main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int x = 1; x <= 4; x++)
                for (int y = 1; y <= 4; y++)
                    f[i][j][x][y] = -inf;
    for (int i = 1; i <= n; i++)
    {
        int l, r, w;
        cin >> l >> w >> r;
        f[i][i][l][r] = w;
        f[i][i][r][l] = w;
    }
    for (int r = 1; r <= n; r++)
    {
        for (int l = r - 1 ; l >= 1; l--)
        {
            for (int x = 1; x <= 4; x++)
                for (int y = 1; y <= 4; y++)
                {
                    f[l][r][x][y] = max(f[l][r][x][y], max(f[l + 1][r][x][y], f[l][r - 1][x][y]));
                    for (int k = l; k < r; k++)
                        for (int z = 1; z <= 4; z++)
                        {
                            f[l][r][x][y] = max(f[l][r][x][y], f[l][k][x][z] + f[k + 1][r][z][y]);
                            f[l][r][x][y] = max(f[l][r][x][y], f[l][k][z][y] + f[k + 1][r][x][z]);
                        }
                }
        }
    }
    int ans = -inf;
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            ans = max(ans, f[1][n][i][j]);
    cout << ans << endl;
}