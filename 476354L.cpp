#include <bits/stdc++.h>
#define II pair<int, int>
#define int long long
#define fi first
#define se second
#define x1 sahcjds
#define y1 fkchjeklgv
#define x2 kjcfkldfsjkvlg
#define y2 kckldsjklvmfkljgv
using namespace std;
const int maxn = 3e4 + 1;
int x1[maxn], y1[maxn], x2[maxn], y2[maxn], gr[maxn], gr1[maxn];
set<int> stx, sty;
vector<int> vx, vy;
II st[4 * maxn];
int n;
struct nodes
{
    int xx1, type, yy1, yy2;
};
vector<nodes> a;
bool cmp(nodes a, nodes b)
{
    if (a.xx1 != b.xx1)
        return a.xx1 < b.xx1;
    if (a.type != b.type)
        return a.type < b.type;
    if (a.yy1 != b.yy1)
        return a.yy1 < b.yy1;
    return a.yy2 < b.yy2;
}
int ans;
void update(int id, int l, int r, int u, int v, int val)
{

    if (r <= u || v <= l)
        return;
    if (u <= l && v >= r)
    {
        st[id].fi += val;
    }
    else
    {
        int mid = (l + r) / 2;
        update(id * 2, l, mid, u, v, val);
        update(id * 2 + 1, mid, r, u, v, val);
    }
    if (st[id].fi == 0)
        st[id].se = st[id * 2].se + st[id * 2 + 1].se;
    else
        st[id].se = gr1[r] - gr1[l];
}

void sweepline()
{
    int i, y1, y2, type, len, d;
    for (i = 0; i < a.size() - 1; i++)
    {
        y1 = a[i].yy1;
        y2 = a[i].yy2;
        type = a[i].type;
        update(1, 1, maxn - 1, y1, y2, type);
        len = gr[a[i + 1].xx1] - gr[a[i].xx1];
        d = st[1].se;
        ans += len * d;
        // cout << st[1].fi << endl;
    }
}

int32_t main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        stx.insert(x1[i]), stx.insert(x2[i]);
        sty.insert(y1[i]), sty.insert(y2[i]);
    }
    for (auto val : stx)
        vx.push_back(val);
    for (auto val : sty)
        vy.push_back(val);
    for (int i = 1; i <= n; i++)
    {
        int xx1 = lower_bound(vx.begin(), vx.end(), x1[i]) - vx.begin() + 1;
        int xx2 = lower_bound(vx.begin(), vx.end(), x2[i]) - vx.begin() + 1;
        int yy1 = lower_bound(vy.begin(), vy.end(), y1[i]) - vy.begin() + 1;
        int yy2 = lower_bound(vy.begin(), vy.end(), y2[i]) - vy.begin() + 1;
        gr[xx1] = x1[i];
        gr[xx2] = x2[i];
        gr1[yy1] = y1[i];
        gr1[yy2] = y2[i];
        a.push_back({xx1, 1, yy1, yy2});
        a.push_back({xx2, -1, yy1, yy2});
    }
    sort(a.begin(), a.end(), cmp);
    sweepline();
    cout << ans << endl;
}