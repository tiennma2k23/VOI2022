#include <bits/stdc++.h>
using namespace std;
int n, m, sx, sy, vs[1010][1010][2][3];
bool ok = false;
char ch[1010][1010];

void dfs(int x, int y, int a, int p) // đến x,y, đang đi dọc hay ngang và số lần đổi hướng
{
    if (!x || !y || x > n || y > m || vs[x][y][a][p] || p > 2 || ok || ch[x][y] == '*')
        return;
    if (ch[x][y] == 'T')
    {
        ok = 1;
        return;
    }
    vs[x][y][a][p] = 1;
    if (a)
        dfs(x + 1, y, a, p), dfs(x - 1, y, a, p);
    else
        dfs(x, y + 1, a, p), dfs(x, y - 1, a, p);
    dfs(x, y, !a, p + 1);
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> ch[i][j];
            if (ch[i][j] == 'S')
                sx = i, sy = j;
        }
    dfs(sx, sy, 0, 0);
    dfs(sx, sy, 1, 0);
    if (ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
