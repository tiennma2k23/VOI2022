#include <bits/stdc++.h>
#define int long long
#define data _data
using namespace std;
const int maxn = 3e5 + 3, mod = 65536;
int bit[maxn], a[maxn];
struct data
{
    int cnt;
    int child[2];
};
data Trie[maxn];
int cnt_nodes;
int rt;
void init()
{
    Trie[cnt_nodes].child[0] = Trie[cnt_nodes].child[1] = -1;
    Trie[cnt_nodes].cnt = 0;
}

void addNum(int x, int val)
{
    int r = 0;
    for (int i = 16; i >= 0; i--)
    {
        int t;
        if (x & (1 << i))
            t = 1;
        else
            t = 0;
        if (Trie[r].child[t] == -1)
        {
            Trie[r].child[t] = ++cnt_nodes;
            init();
        }
        r = Trie[r].child[t];
        Trie[r].cnt += val;
    }
}
int P_th(int k)
{
    int r = rt, res = 0;
    for (int i = 16; i >= 0; i--)
    {
        if (Trie[r].child[1] != -1 && Trie[Trie[r].child[1]].cnt >= k)
        {
            r = Trie[r].child[1];
            res |= (1 << i);
        }
        else
        {
            if (Trie[r].child[1] != -1)
                k -= Trie[Trie[r].child[1]].cnt;
            r = Trie[r].child[0];
        }
    }
    return res;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    init();
    int q;
    cin >> q;
    for (int tc = 1; tc <= q; tc++)
    {
        int sum = 0;
        int seed, mul, add, n, k;
        cnt_nodes = 0;
        init();
        cin >> seed >> mul >> add >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            if (i == 1)
                a[i] = seed;
            else
                a[i] = (a[i - 1] * mul + add) % mod;
            addNum(a[i], 1);
            if (i >= k)
            {
                int tmp = (k + 1) / 2;
                sum += P_th(k - tmp + 1);
                addNum(a[i - k + 1], -1);
            }
        }
        cout << "Case #" << tc << ": " << sum << '\n';
    }
}