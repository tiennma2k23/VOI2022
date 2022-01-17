// fi là vị trí xa nhất từ i -> fi toàn 1
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define int long long
using namespace std;
const int maxn = 3e5 + 1, inf = 1e9 + 1;
int n;
struct Node
{
    int lazy = -1;
    int val;
} status[maxn * 4];

void down_status(int id, int l, int r)
{
    int t = status[id].lazy;
    if (t == -1)
        return;
    int mid = (l + r) / 2;
    status[id * 2].lazy = t;
    status[id * 2].val = t * (mid - l + 1);

    status[id * 2 + 1].lazy = t;
    status[id * 2 + 1].val = t * (r - mid);

    status[id].lazy = -1;
}

void update_status(int id, int l, int r, int u, int v, int val)
{
    if (v < l || r < u)
    {
        return;
    }
    if (u <= l && r <= v)
    {
        status[id].val = val * (r - l + 1);
        status[id].lazy = val;
        return;
    }
    int mid = (l + r) / 2;

    down_status(id, l, r);

    update_status(id * 2, l, mid, u, v, val);
    update_status(id * 2 + 1, mid + 1, r, u, v, val);

    status[id].val = status[id * 2].val + status[id * 2 + 1].val;
}

int get_status(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return 0;
    }
    if (u <= l && r <= v)
    {
        return status[id].val;
    }
    int mid = (l + r) / 2;
    down_status(id, l, r);

    return get_status(id * 2, l, mid, u, v) + get_status(id * 2 + 1, mid + 1, r, u, v);
}

struct Rnodes
{
    int lazy = -1;
    int val;
} R[maxn * 4];

void down_R(int id, int l, int r)
{
    int t = R[id].lazy;
    if (t == -1)
        return;
    int mid = (l + r) / 2;
    R[id * 2].lazy = t;
    R[id * 2].val = t * (mid - l + 1);

    R[id * 2 + 1].lazy = t;
    R[id * 2 + 1].val = t * (r - mid);

    R[id].lazy = -1;
}

void update_R(int id, int l, int r, int u, int v, int val)
{
    if (v < l || r < u)
    {
        return;
    }
    if (u <= l && r <= v)
    {
        R[id].val = val * (r - l + 1);
        R[id].lazy = val;
        return;
    }
    int mid = (l + r) / 2;

    down_R(id, l, r);

    update_R(id * 2, l, mid, u, v, val);
    update_R(id * 2 + 1, mid + 1, r, u, v, val);

    R[id].val = R[id * 2].val + R[id * 2 + 1].val;
}

int get_R(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return 0;
    }
    if (u <= l && r <= v)
    {
        return R[id].val;
    }
    int mid = (l + r) / 2;
    down_R(id, l, r);

    return get_R(id * 2, l, mid, u, v) + get_R(id * 2 + 1, mid + 1, r, u, v);
}

struct leftnodes
{
    int lazy = -1;
    int val = inf;
} Left[maxn * 4];

void down_left(int id, int l, int r)
{
    int t = Left[id].lazy;
    if (t == -1)
        return;
    int mid = (l + r) / 2;
    Left[id * 2].lazy = t;
    Left[id * 2].val = t;

    Left[id * 2 + 1].lazy = t;
    Left[id * 2 + 1].val = t;

    Left[id].lazy = -1;
}

void update_left(int id, int l, int r, int u, int v, int val)
{
    if (v < l || r < u)
    {
        return;
    }
    if (u <= l && r <= v)
    {
        Left[id].val = val;
        Left[id].lazy = val;
        return;
    }
    int mid = (l + r) / 2;

    down_left(id, l, r);

    update_left(id * 2, l, mid, u, v, val);
    update_left(id * 2 + 1, mid + 1, r, u, v, val);

    Left[id].val = min(Left[id * 2].val, Left[id * 2 + 1].val);
}

int get_left(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return inf;
    }
    if (u <= l && r <= v)
    {
        return Left[id].val;
    }
    int mid = (l + r) / 2;
    down_left(id, l, r);

    return min(get_left(id * 2, l, mid, u, v), get_left(id * 2 + 1, mid + 1, r, u, v));
}

struct rightnodes
{
    int lazy = -1;
    int val = -inf;
} Right[maxn * 4];

void down_right(int id, int l, int r)
{
    int t = Right[id].lazy;
    if (t == -1)
        return;
    int mid = (l + r) / 2;
    Right[id * 2].lazy = t;
    Right[id * 2].val = t;

    Right[id * 2 + 1].lazy = t;
    Right[id * 2 + 1].val = t;

    Right[id].lazy = -1;
}

void update_right(int id, int l, int r, int u, int v, int val)
{
    if (v < l || r < u)
    {
        return;
    }
    if (u <= l && r <= v)
    {
        Right[id].val = val;
        Right[id].lazy = val;
        return;
    }
    int mid = (l + r) / 2;

    down_right(id, l, r);

    update_right(id * 2, l, mid, u, v, val);
    update_right(id * 2 + 1, mid + 1, r, u, v, val);

    Right[id].val = max(Right[id * 2].val, Right[id * 2 + 1].val);
}

int get_right(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return -inf;
    }
    if (u <= l && r <= v)
    {
        return Right[id].val;
    }
    int mid = (l + r) / 2;
    down_right(id, l, r);

    return max(get_right(id * 2, l, mid, u, v), get_right(id * 2 + 1, mid + 1, r, u, v));
}
struct R1nodes
{
    int lazy = -1, val;
} R1[4 * maxn];
void down_R1(int id)
{
    int t = R1[id].lazy;
    if (t == -1)
        return;
    R1[id * 2].lazy = t;
    R1[id * 2].val = t;

    R1[id * 2 + 1].lazy = t;
    R1[id * 2 + 1].val = t;

    R1[id].lazy = -1;
}
void update_R1(int id, int l, int r, int u, int v, int val)
{
    if (v < l || r < u)
    {
        return;
    }
    if (u <= l && r <= v)
    {
        R1[id].val = val;
        R1[id].lazy = val;
        return;
    }
    int mid = (l + r) / 2;

    down_R1(id);

    update_R1(id * 2, l, mid, u, v, val);
    update_R1(id * 2 + 1, mid + 1, r, u, v, val);

    R1[id].val = min(R1[id * 2].val, R1[id * 2 + 1].val);
}
int get_R1(int id, int l, int r, int upper, int val)
{
    if (l > upper)
        return -1;
    if (R1[id].val >= val)
        return -1;
    if (l == r)
        return l;
    int mid = (l + r) / 2;
    down_R1(id);
    int res = -1;
    if (R1[id * 2 + 1].val < val)
    {
        res = get_R1(id * 2 + 1, mid + 1, r, upper, val);
    }
    if (res == -1)
        res = get_R1(id * 2, l, mid, upper, val);
    return res;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = ' ' + s;
    s = s + ' ';
    int l = -1, r = -1;
    for (int i = 1; i <= n; i++)
    {
        update_R(1, 1, n, i, i, i - 1);
        update_status(1, 1, n, i, i, s[i] - '0');
        if (s[i] == '1')
        {
            if (s[i - 1] != '1')
            {
                l = i;
            }
            update_left(1, 1, n, i, i, l);
            // cout << l << ' ';
        }
    }
    // cout << endl;
    for (int i = n; i >= 1; i--)
    {
        if (s[i] == '1')
        {
            if (s[i + 1] != '1')
            {
                r = i;
            }
            update_right(1, 1, n, i, i, r);
        }
    }
    for (int i = 1; i <= n; i++)
        if (s[i] == '1')
        {
            int l = get_left(1, 1, n, i, i);
            int r = get_right(1, 1, n, i, i);
            update_left(1, 1, n, l, r, l);
            update_right(1, 1, n, l, r, r);
            // update_L(1, 1, n, l, r, l - 1);
            update_R(1, 1, n, l, r, r), update_R1(1, 1, n, l, r, r);
        }
    cout << get_R(1, 1, n, 1, n) - n * (n + 1) / 2 + n << '\n';
    while (q--)
    {
        int l, r, type;
        cin >> l >> r >> type;
        update_status(1, 1, n, l, r, type);
        if (!type)
        {
            int l1 = get_left(1, 1, n, l - 1, l - 1);
            int r1 = get_right(1, 1, n, r + 1, r + 1);
            update_left(1, 1, n, l, r, inf);
            update_right(1, 1, n, l, r, -inf);
            if (l1 <= l - 1)
                update_right(1, 1, n, l1, l - 1, l - 1);
            if (r1 > r)
                update_left(1, 1, n, r + 1, r1, r + 1);
        }
        if (type)
        {
            l = min(l, get_left(1, 1, n, l - 1, l - 1));
            r = max(r, get_right(1, 1, n, r + 1, r + 1));
            update_left(1, 1, n, l, r, l);
            update_right(1, 1, n, l, r, r);
            // update_L(1, 1, n, l, r, 0);
            int pos = get_R1(1, 1, n, r, r);
            if (pos != -1 && pos >= l)
                pos = max(pos, l), update_R(1, 1, n, l, pos, r),
                update_R1(1, 1, n, l, pos, r);
        }
        cout << get_R(1, 1, n, 1, n) - n * (n + 1) / 2 + n << '\n';
    }
}