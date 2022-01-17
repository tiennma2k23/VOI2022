#include <bits/stdc++.h>
#define Trie _Trie
#define data _data
#define int long long
using namespace std;
const int maxn = 1e6 + 1;
struct data
{
    int stop;
    int cnt;
    int par;
    int child[26];
};
data Trie[maxn];
string s[maxn];
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
int cnt[30], dem[30];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen("input", "r", stdin);
    // freopen("output", "w", stdout);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        for (int j = 0; j < s.length(); j++)
            cnt[s[j] - 'a']++;
        for (int j = 0; j < 30; j++)
            dem[j] = max(dem[j], cnt[j]), cnt[j] = 0;
        addword(s);
    }
    int ans = 0;
    for (int i = 0; i <= 29; i++)
        ans += dem[i];
    ans++;
    cout << ans << endl;
    // cout << cnt_nodes + 1 << endl;
}
