#include <bits/stdc++.h>
#define int long long
#define data _data
using namespace std;
const int maxn = 3e6 + 3;
int bit[maxn];
struct data
{
    int stop;
    int cnt;
    int par;
    int sum;
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

void addNum(int x)
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
        Trie[r].cnt++;
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
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        addNum(a);
    }
    int sumxor = 0;
    while (q--)
    {
        string s;
        cin >> s;
        if (s == "FIND")
        {
            int x;
            cin >> x;
            cout << P_th(sumxor, x) << endl;
        }
        else
        {
            int x;
            cin >> x;
            sumxor ^= x;
        }
    }
    // int r = Trie[rt].child[0];
    // cout << P_th(1) << endl;
    // return 0;
}