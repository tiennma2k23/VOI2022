#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[110][110];
int n, m, k;
void sub1()
{
    vector<vector<int>> v;
    vector<int> vec;
    for (int i = 1; i <= n; i++)
        vec.push_back(i);
    do
    {
        /* code */
        bool ok = true;
        for (int i = 1; i < vec.size(); i++)
        {
            if (a[vec[i]][vec[i - 1]])
            {
                ok = false;
                break;
            }
        }
        if (ok)
            v.push_back(vec);
        if (v.size() > k)
            break;
    } while (next_permutation(vec.begin(), vec.end()));
    sort(v.begin(), v.end());
    for (auto val : v[k - 1])
        cout << val << ' ';
}

int findIndex(int &k, int n)
{
    if (n == 1)
        return 0;
    n--;
    int id;
    int npf = n;
    while ((n > 1) && (k / (n - 1) >= npf))
    {
        npf = npf * (n - 1);
        n--;
    }
    id = k / npf;
    k = k % npf;
    return id;
}
vector<int> findkpermutation(int n, int k)
{
    vector<int> v;
    set<int> st;
    for (int i = 1; i <= n; i++)
        st.insert(i);
    auto it = st.begin();
    k--;
    for (int i = 0; i < n; i++)
    {
        int id = findIndex(k, n - i);
        advance(it, id);
        v.push_back(*it);
        st.erase(it);
        it = st.begin();
    }
    return v;
}
void sub3()
{
    vector<int> ans = findkpermutation(n, k);
    for (auto val : ans)
        cout << val << ' ';
}

int32_t main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = true;
        a[y][x] = true;
    }
    if ((n <= 10 || k <= 10000000) && m > 0)
        sub1();
    else if (m == 0)
    {
        sub3();
    }
}