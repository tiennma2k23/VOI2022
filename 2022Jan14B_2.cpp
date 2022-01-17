#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vector<int> adj[1 << k];
    for (int msk = 0; msk < (1 << k); msk++)
    {
        for (int i = 0; i < k; i++)
        {
            adj[msk].push_back(msk ^ (1 << i));
        }
    }

    queue<int> q;
    string s;
    int dst[1 << k];
    memset(dst, -1, sizeof(dst));
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        int x = 0;
        for (auto &c : s)
        {
            (x <<= 1) |= c - '0';
        }
        q.push(x);
        dst[x] = 0;
    }

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        for (auto &to : adj[u])
        {
            if (!(~dst[to]))
            {
                dst[to] = dst[u] + 1;
                q.push(to);
            }
        }
    }

    int res = -1;
    for (int i = 0; i < (1 << k); i++)
    {
        if (res == -1 || dst[res] < dst[i])
        {
            res = i;
        }
    }

    for (int i = k - 1; ~i; i--)
    {
        cout << (res >> i & 1);
    }

    cout << "\n";

    return 0;
}