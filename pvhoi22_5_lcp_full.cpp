#include <bits/stdc++.h>
// #define int long long
using namespace std;
const int maxn = 4e6 + 1;
const long long inf = 1e14;
int nT, rt = 0, n, k;
struct nodes
{
    int child[26], cnt, par, dep, stop;
    vector<long long> dp;
} Trie[maxn];

int addnodes()
{
    nT++;
    for (int i = 0; i < 26; i++)
        Trie[nT].child[i] = -1;
    return nT;
}
void addWord(string s)
{
    int r = rt;
    for (int k = 0; k < s.length(); k++)
    {
        int i = s[k] - 'a';
        if (Trie[r].child[i] == -1)
        {
            Trie[r].child[i] = addnodes();
            Trie[nT].par = r;
            Trie[nT].dep = Trie[r].dep + 1;
        }
        r = Trie[r].child[i];
    }
    Trie[r].stop++;
    Trie[r].cnt++;
    while (r != rt)
    {
        r = Trie[r].par;
        Trie[r].cnt++;
    }
}
long long ans = 0;
void dfs(int u)
{
    Trie[u].dp.assign(Trie[u].cnt + 1, -inf);
    for (int i = 0; i <= Trie[u].stop; i++)
        Trie[u].dp[i] = 1ll * (i * (i - 1) / 2) * Trie[u].dep;
    int sc = Trie[u].stop;
    for (int i = 0; i < 26; i++)
    {
        int v = Trie[u].child[i];
        if (v == -1)
            continue;
        dfs(v);
        for (int j = sc; j >= 0; j--)
        {
            for (int j1 = Trie[v].cnt; j1 >= 0; j1--)
            {
                Trie[u].dp[j + j1] = max(Trie[u].dp[j + j1], Trie[u].dp[j] + Trie[v].dp[j1] + 1ll * j * j1 * Trie[u].dep);
            }
        }
        sc += Trie[v].cnt;
    }
    if (Trie[u].dp.size() > k && Trie[u].dp[k] >= 0)
        ans = max(ans, Trie[u].dp[k]);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < 26; i++)
        Trie[0].child[i] = -1;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        addWord(s);
    }
    dfs(0);
    cout << ans << endl;
}