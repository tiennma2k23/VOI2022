#include <bits/stdc++.h>
#define Trie _Trie
#define data _data
#define int long long
using namespace std;
const int maxn = 32001;
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
        int k = s[i] - 'A';
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
    while (cin >> s)
    {
        addword(s);
        // cout << s << endl;
    }
    cout << cnt_nodes + 1 << endl;
}