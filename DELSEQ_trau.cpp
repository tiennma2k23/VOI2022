#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 1e10, maxn = 1e5 + 5;
int a[maxn];
vector<int> v;
int32_t main()
{
#define TASK "DELSEQ"
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".ans", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = inf;
    vector<int> v1;
    for (int i = 1; i <= n; i++)
    {
        v1.push_back(i);
    }
    do
    {
        int res = 0;
        int i = 0;
        while (i < v1.size())
        {
            if (i == v1.size() - 1)
                i++, res++;
            else
            {
                if (a[v1[i]] != a[v1[i + 1]])
                    res++, i += 2;
                else
                    res++, i++;
            }
            /* code */
        }
        ans = min(ans, res);

    } while (next_permutation(v1.begin(), v1.end()));
    cout << ans << endl;
}