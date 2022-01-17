#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-10;

struct Point
{
    double x, y;
};
Point symmetry(Point x, Point a)
{
    return {x.x * 2 - a.x, x.y * 2 - a.y};
}
Point circumcenter(Point x, Point a, Point b)
{
    double a1 = b.x - a.x, b1 = b.y - a.y, c1 = (a1 * a1 + b1 * b1) / 2.0;
    double a2 = x.x - a.x, b2 = x.y - a.y, c2 = (a2 * a2 + b2 * b2) / 2.0;
    double d = a1 * b2 - a2 * b1;
    // cout << d << '\n';
    return {a.x + (c1 * b2 - c2 * b1) / d, a.y + (a1 * c2 - a2 * c1) / d};
}
double sqr(double x) { return x * x; }
double dist(Point a, Point b)
{
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}

double CCW(Point p, Point p1, Point p2)
{
    return ((p.x - p1.x) * (p.y - p2.y) - (p.y - p1.y) * (p.x - p2.x));
}

bool equal(double a, double b)
{
    return (abs(a - b) <= EPS);
}

bool check(Point a, Point b, Point c, Point d)
{
    double t1 = CCW(a, b, c), t2 = CCW(b, c, d), t3 = CCW(c, d, a), t4 = CCW(d, a, b);
    if (t1 * t2 <= 1e-5 || t2 * t3 <= 1e-5 || t3 * t4 <= 1e-5 || t4 * t1 <= 1e-5)
        return false;
    return true;
}

bool ok(Point k, Point l, Point m)
{
    if (CCW(k, l, m) == 0)
        return false;
    Point b = circumcenter(k, symmetry(l, m), l), a = symmetry(k, b), c = symmetry(l, b), d = symmetry(m, c);
    if (!equal(dist(a, b), dist(b, c)) || !equal(dist(b, c), dist(c, d)))
        return false;
    if (!check(a, b, c, d))
        return false;
    cout << "YES" << '\n';
    cout << fixed;
    cout << setprecision(9) << a.x << ' ' << a.y << ' ' << b.x << ' ' << b.y << ' ' << c.x << ' ' << c.y << ' ' << d.x << ' ' << d.y << '\n';
    return true;
}
void solve()
{
    Point a[4];
    vector<int> v;
    for (int i = 1; i <= 3; i++)
        cin >> a[i].x >> a[i].y, v.push_back(i);
    do
    {
        if (ok(a[v[0]], a[v[1]], a[v[2]]))
            return;
    } while (next_permutation(v.begin(), v.end()));
    cout << "NO" << '\n';
    cout << '\n';
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt;
    cin >> tt;
    // cout << tt << '\n';
    while (tt--)
        solve();
}