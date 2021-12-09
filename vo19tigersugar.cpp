#include <bits/stdc++.h>
#define xx _xx
#define yy _yy
#define int long long
// #define a x1
// #define b x2
// #define c y1
// #define d y2
using namespace std;
const int maxn = 1e5 + 1;
int a[maxn], c[maxn], b[maxn], d[maxn];
vector<int> x, y;
int n;
int _mid(int xx, int xb, int xx3)
{
    vector<int> v;
    v.push_back(xx), v.push_back(xb), v.push_back(xx3);
    sort(v.begin(), v.end());
    return v[1];
}
int calc(int xx, int yy)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (xx < a[i])
            res += a[i] - xx;
        if (xx > b[i])
            res += xx - b[i];
        if (yy < c[i])
            res += c[i] - yy;
        if (yy > d[i])
            res += yy - d[i];
        //res += min(abs(xx - a[i]), abs(xx - b[i]));
        //res += min(abs(yy - c[i]), abs(yy - d[i]));
    }
    return res;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen("input", "r", stdin);
    // freopen("output", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> c[i] >> b[i] >> d[i];
        if (a[i] > b[i])
            swap(a[i], b[i]);
        if (c[i] > d[i])
            swap(c[i], d[i]);
        x.push_back(a[i]);
        x.push_back(b[i]);
        y.push_back(c[i]);
        y.push_back(d[i]);
    }
    sort(x.begin(), x.end()), sort(y.begin(), y.end());
    int p_a = x[n], p_b = x[n - 1];
    int p_d = y[n], p_y2 = y[n - 1];
    int ans1 = calc(p_a, p_d);
    int ans2 = calc(p_b, p_y2);
    if (ans1 < ans2)
    {
        cout << ans1 << endl
             << p_a << " " << p_d << endl;
        for (int i = 0; i < n; i++)
        {
            cout << _mid(a[i], b[i], p_a) << " " << _mid(c[i], d[i], p_d) << endl;
        }
    }
    else
    {
        cout << ans2 << endl
             << p_b << " " << p_y2 << endl;
        for (int i = 0; i < n; i++)
        {
            cout << _mid(a[i], b[i], p_b) << " " << _mid(c[i], d[i], p_y2) << endl;
        }
    }
}