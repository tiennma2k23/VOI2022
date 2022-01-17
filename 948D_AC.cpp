#include <bits/stdc++.h>
#define II pair<int, int>
#define fi first
#define se second
#define data _data

using namespace std;
const int maxn = 1e7 + 1;
int bit[maxn], a[maxn], b[maxn];
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
    memset(Trie[cnt_nodes].child, -1, sizeof(Trie[cnt_nodes].child));
    Trie[cnt_nodes].cnt = 0;
}

void addNum(int x, int val)
{
    int r = rt;
    for (int i = 31; i >= 0; i--)
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

int P_th(int x, int k)
{
    int r = rt, res = 0;
    for (int i = 31; i >= 0; i--)
    {
        int t;
        if (x & (1 << i))
            t = 1;
        else
            t = 0;

        if (t == 0)
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
        else
        {
            if (Trie[r].child[0] != -1 && Trie[Trie[r].child[0]].cnt >= k)
            {
                r = Trie[r].child[0];
                res |= (1 << i);
            }
            else
            {
                if (Trie[r].child[0] != -1)
                    k -= Trie[Trie[r].child[0]].cnt;
                r = Trie[r].child[1];
            }
        }
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
    init();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        addNum(b[i], 1);
    }
    for (int i = 1; i <= n; i++)
    {
        int res = P_th(a[i], n - i + 1);
        cout << res << ' ';
        int tmp = res xor a[i];
        addNum(tmp, -1);
    }
}