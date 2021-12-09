#include <bits/stdc++.h>
#define int long long
#define data _data
using namespace std;
const int maxn = 5e6 + 1, inf = 1e18, M = 1e9;
unordered_map<int, int> ok;
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
    Trie[0].cnt += val;
}
int P_th(int k)
{
    int r = rt, res = 0;
    if (Trie[r].cnt < k)
        return -inf;
    // cout << " " << Trie[r].cnt << endl;
    k = Trie[r].cnt - k + 1;
    for (int i = 31; i >= 0; i--)
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
int count_nhohon(int x)
{
    int r = rt, res = 0;
    for (int i = 31; i >= 0; i--)
    {
        int t = (x >> i) & 1;
        if (t && Trie[r].child[0] != -1)
        {
            res += Trie[Trie[r].child[0]].cnt;
        }
        if (Trie[r].child[t] == -1)
            return res;
        r = Trie[r].child[t];
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
    int q;
    cin >> q;
    while (q--)
    {
        char ch;
        int num;
        cin >> ch >> num;
        if (ch == 'I')
        {
            num += M;
            if (!ok[num])
                ok[num] = 1, addNum(num, 1);
        }

        else if (ch == 'D')
        {
            num += M;
            if (ok[num])
                ok[num] = 0,
                addNum(num, -1);
        }

        else if (ch == 'K')
        {
            int ans = P_th(num);
            if (ans == -inf)
                cout << "invalid" << '\n';
            else
                cout << ans - M << '\n';
        }
        else
        {
            cout << count_nhohon(num + M) << '\n';
        }
    }
}