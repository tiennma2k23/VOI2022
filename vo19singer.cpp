#include <bits/stdc++.h>
const int mod = 998244353;
using namespace std;
int pre[6421];
int f[6421][6421];
int sumd[6421][6421];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, d, t;
	cin >> n >> d >> t;
	d--;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
		{
			if (i == 0)
			{
				if (j == t)
					f[i][j] = 1;
				else
					f[i][j] = 0;
			}
			else
			{
				f[i][j] = pre[j];
				if ((i >= d) and (j < n))
					f[i][j] += sumd[i - d][j + 1];
				f[i][j] %= mod;
			}
			pre[j] += f[i][j];
			pre[j] %= mod;
			if (i >= d - 1)
				pre[j] -= f[i - d + 1][j];
			pre[j] += mod;
			pre[j] %= mod;
			sumd[i][j] = f[i][j];
			if ((j < n) and (i))
			{
				sumd[i][j] += sumd[i - 1][j + 1];
				sumd[i][j] %= mod;
			}
		}
	cout << (f[n][0] * 2) % mod << endl;
}