#include <bits/stdc++.h>
#define data _dl
#define Trie _Trie
using namespace std;
const int maxn = 3e5 + 1, mod = 1337377;
int f[maxn];
struct data
{
    int stop;      // số từ kết thúc bằng nodes này
    int cnt;       //   so từ di qua nodes này
    int par;       //cha
    int child[26]; //con
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
    Trie[cnt_nodes].cnt = Trie[cnt_nodes].stop = 0;
    return cnt_nodes;
}
void addword(string s)
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
    Trie[r].stop++;
    while (r != rt)
    {
        Trie[r].cnt++;
        r = Trie[r].par;
        // cout << r << " ";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen("input", "r", stdin);
    // freopen("output", "w", stdout);
    string s;
    cin >> s;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s1;
        cin >> s1;
        addword(s1);
    }
    int len = s.length();
    s = ' ' + s;
    f[0] = 1;
    for (int i = 1; i <= len; i++)
    {
        int r = rt;
        for (int j = i; j <= i + 99 && j < s.size(); j++)
        {
            int c = s[j] - 'a';
            r = Trie[r].child[c];
            if (r == 0)
                break;
            if (Trie[r].stop != 0)
                f[j] = (f[j] + f[i - 1]) % mod;
        }
    }
    cout << f[len] << endl;
}