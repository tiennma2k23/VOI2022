#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    int n, uc = 0, maxx = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        uc = __gcd(uc, a);
        maxx = max(maxx, a);
    }
    int tmp = (maxx / uc) - n;
    if (tmp % 2 == 1)
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;
}