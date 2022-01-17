#include <bits/stdc++.h>
#define int long long
#define II pair<int, int>
#define SI pair<string, int>
#define data _data
#define fi first
#define se second
using namespace std;
const int maxn = 5e5 + 5;
struct data
{
    set<int> pos;
    int par;
    int child[26];
};
data Trie[maxn];
int cnt_nodes;
int rt;
int addnodes()
{
    cnt_nodes++;
    for (int i = 0; i < 26; i++)
        Trie[cnt_nodes].child[i] = 0;
    Trie[cnt_nodes].par = 0;
    // Trie[cnt_nodes].pos;
    return cnt_nodes;
}
void addword(string s, int pos)
{
    int r = rt;
    for (int i = 0; i < s.length(); i++)
    {
        int k = s[i] - 'a';
        int l;
        if (!Trie[r].child[k])
        {
            l = addnodes();
            Trie[r].child[k] = l;
            Trie[l].par = r;
        }
        r = Trie[r].child[k];
    }
    Trie[r].pos.insert(pos);
    while (r != rt)
    {
        r = Trie[r].par;
        Trie[r].pos.insert(pos);
        // cout << r << " ";
    }
}

void delword(string s, int pos)
{
    int r = rt;
    for (int i = 0; i < s.length(); i++)
    {
        int k = s[i] - 'a';
        r = Trie[r].child[k];
    }
    if (Trie[r].pos.find(pos) != Trie[r].pos.end())
        Trie[r].pos.erase(Trie[r].pos.find(pos));
    while (r != rt)
    {
        r = Trie[r].par;
        if (Trie[r].pos.find(pos) != Trie[r].pos.end())
            Trie[r].pos.erase(Trie[r].pos.find(pos));
    }
}

int findprefix(string s)
{
    int r = rt;
    for (int i = 0; i < s.length(); i++)
    {
        int k = s[i] - 'a';
        if (Trie[r].child[k] == 0)
            return 0;
        r = Trie[r].child[k];
    }
    if (Trie[r].pos.size())
        return (*Trie[r].pos.begin());
    return 0;
}
bool cmp(SI a, SI b)
{
    if (a.fi.length() != b.fi.length())
        return (a.fi).length() > b.fi.length();
    return a < b;
}
SI a[maxn];
int32_t main()
{
#define TASK "PREFPASS"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    int n;
    cin >> n;
    n *= 2;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    vector<II> res;
    for (int i = 1; i <= n; i++)
    {
        int pos = findprefix(a[i].fi);
        if (pos == 0)
        {
            addword(a[i].fi, i);
        }
        else
        {
            res.push_back(II(a[i].se, a[pos].se));
            delword(a[pos].fi, pos);
        }
    }
    for (auto val : res)
        cout << val.fi << ' ' << val.se << endl;
}