#include <bits/stdc++.h>
using namespace std;

const int mxB = 10;
const int hlf = 1 << 10;
const int all = 1 << 20;

vector<pair<short, char>> v[hlf];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        reverse(s.begin(), s.end());
        while (s.size() < mxB + mxB)
        {
            s += '0';
        }
        reverse(s.begin(), s.end());
        int x = 0, y = 0;
        for (int j = 0; j < mxB; j++)
        {
            (x <<= 1) |= s[j] - '0';
        }
        for (int j = mxB; j < mxB + mxB; j++)
        {
            (y <<= 1) |= s[j] - '0';
        }
        // cout << x << " " << y << "\n";

        for (int msk = 0; msk < hlf; msk++)
        {
            int w = __builtin_popcount((~(msk ^ x)) & (hlf - 1));
            v[msk].push_back({y, w});
            // cout << msk << " " << y << " " << __builtin_popcount(msk & x) << "\n";
        }
    }

    for (int i = 0; i < hlf; i++)
    {
        sort(v[i].begin(), v[i].end());
        v[i].resize(unique(v[i].begin(), v[i].end()) - v[i].begin());
    }

    int mn = 21, ans = 0;
    for (int msk = 0; msk < all; msk++)
    {
        int x = msk >> mxB, y = msk & (hlf - 1);
        int mx = -1, z, k;
        for (auto &_ : v[x])
        {
            z = _.first, k = _.second;
            mx = max(mx, k + __builtin_popcount((~(y ^ z)) & (hlf - 1)));
        }
        // cout << mn << "\n";
        if (mn > mx)
        {
            mn = mx;
            ans = x << mxB | y;
        }
    }

    for (int i = k - 1; ~i; i--)
    {
        cout << (ans >> i & 1);
    }
    cout << "\n";

    return 0;
}