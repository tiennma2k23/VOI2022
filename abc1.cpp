// Problem: https://codeforces.com/group/FLVn1Sc504/contest/266446/problem/B

//                          __  __  ___  ___    _____  __       ___    _      ___
//   /\/\ /\_/\    /\/\    /__\/__\/ _ \/___\   \_   \/ _\     / __\  /_\    /   \
//  /    \_ _/    /    \  /_\ /_\ / /_)//  //    / /\/\ \     /__\// //_\  / /\ /
// / /\/\ \/ \   / /\/\ \//__//__/ ___/ \_//  /\/ /_  _\ \   / \/  \/  _  \/ /_//
// \/    \/\_/___\/    \/\__/\__/\/   \___/___\____/  \__/___\_____/\_/ \_/___,'
//          |_____|                      |_____|        |_____|

// DOTA 2 BURN_IN_ME

#include <bits/stdc++.h>
using namespace std;

#define int long long
// ????????????????????????????????????????

// -------------------------- TYPEDEF & SYNTAX ---------------------------------- //
#define ll long long
#define pll pair<ll, ll>
#define ii pair<int, int>
#define fi first
#define sc second
#define pb push_back
#define mp make_pair
#define MASK(i) ((1 << (i)))
#define BIT(i, x) (((x) >> (i)) & 1)
#define BIT_ON(i, x) ((x) | (1 << (i)))
#define BIT_OFF(i, x) ((x) & ~(1 << (i)))
#define C_BIT(x) (__builtin_popcountll(x))
// ------------------------------------------------------------------------------ //

// -------------------------- LOOPS THINGS -------------------------------------- //
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, b, a) for (int i = b; i >= a; i--)
#define FORE(i, S) for (auto i : S)
// ------------------------------------------------------------------------------ //

// --------------------------- VECTOR THINGS ------------------------------------ //
#define getLOWERBOUND(x, S) (lower_bound(S.begin(), S.end(), x) - S.begin())
#define getUPPERBOUND(x, S) (upper_bound(S.begin(), S.end(), x) - S.begin())
#define UNIQUE(S) S.erase(unique(S.begin(), S.end()), S.end())
#define SORT_Vector(S) (sort(S.begin(), S.end()))
#define SORT_Array(S, N) (sort(S + 1, S + N + 1))
// ------------------------------------------------------------------------------ //

// --------------------------- FILES -------------------------------------------- //
#define task "bus"
// ------------------------------------------------------------------------------ //

// --------------------------- CONSTANTS ---------------------------------------- //
const int MAXN = 100005;
// const ll oo    = ((ll)1e18) + 7;
const int oo = 2e9 + 7;
// ------------------------------------------------------------------------------ //

// --------------------------- VARIABLES ---------------------------------------- //
int N, M, T, K, Q, S;
// ------------------------------------------------------------------------------ //

// --------------------------- SOLUTION ----------------------------------------- //

// ------------------------------------------------------------------------------ //

int pa[MAXN];
int d[MAXN];
int root(int u) { return (u == pa[u]) ? u : pa[u] = root(pa[u]); }
bool DSU(int u, int v)
{
    int X = root(u);
    int Y = root(v);
    if (X == Y)
        return false;
    if (d[X] > d[Y])
        swap(X, Y);
    pa[X] = Y;
    d[Y] += d[X];
    return true;
}

void Init()
{
    for (int i = 1; i <= N; i++)
    {
        pa[i] = i;
        d[i] = 1;
    }
}

struct Edge
{
    int id, u, v, w;
    bool operator<(const Edge &A) const
    {
        return w < A.w;
    }
} E[MAXN];

namespace SUBTASK_1
{
    void SOLVE()
    {
        sort(E + 1, E + M + 1);
        int l = 0;
        int r = M;
        int ans = oo;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            Init();
            for (int i = 1; i <= mid; i++)
                DSU(E[i].u, E[i].v);
            if (root(S) == root(T))
            {
                ans = E[mid].w;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        cout << ans << '\n';
    }
}

namespace SUBTASK_2
{ // n, m <= 5000
    void SOLVE()
    {
        vector<Edge> Ea;
        vector<Edge> Eb;
        for (int i = 1; i <= M; i++)
        {
            if (E[i].id == 1)
                Ea.pb(E[i]);
            if (E[i].id == 2)
                Eb.pb(E[i]);
        }
        // Ea.pb( {0, 0, 0, 0} );
        sort(Ea.begin(), Ea.end());
        sort(Eb.begin(), Eb.end());

        int ans = oo;
        int curA = 0;
        int curB = (int)Eb.size() - 1;
        while (curA <= Ea.size() && curB >= 0)
        {
            Init();
            for (int i = 0; i < curA; i++)
                DSU(Ea[i].u, Ea[i].v);
            for (int i = 0; i <= curB; i++)
                DSU(Eb[i].u, Eb[i].v);
            if (root(S) == root(T))
            {
                int tmp = 0;
                if (curA >= 1)
                    tmp = Ea[curA - 1].w;
                ans = min(ans, tmp + Eb[curB].w);
                curB--;
            }
            else
                curA++;
        }
        cout << ans << '\n';
    }
}

namespace SUBTASK_3
{
    int dS[MAXN];
    int dT[MAXN];
    vector<ii> G[MAXN];
    void dijkstra(int s, int *d)
    {
        for (int i = 1; i <= N; i++)
            d[i] = oo;
        d[s] = 0;
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        pq.push({0, s});
        while (pq.size())
        {
            ii top = pq.top();
            pq.pop();
            int u = top.sc;
            int du = top.fi;
            if (du != d[u])
                continue;
            for (ii p : G[u])
            {
                int v = p.sc;
                int uv = p.fi;
                if (d[v] > max(d[u], uv))
                {
                    d[v] = max(d[u], uv);
                    pq.push({d[v], v});
                }
            }
        }
    }

    int SOLVE()
    {
        for (int i = 1; i <= M; i++)
        {
            int u = E[i].u;
            int v = E[i].v;
            int w = E[i].w;
            if (E[i].id == 1)
                G[u].pb({w, v});
            if (E[i].id == 1)
                G[v].pb({w, u});
        }
        dijkstra(S, dS);
        dijkstra(T, dT);
        int ans = oo;
        for (int i = 1; i <= M; i++)
        {
            if (E[i].id == 1)
                continue;
            int u = E[i].u;
            int v = E[i].v;
            ans = min(ans, dS[u] + dT[v]);
            ans = min(ans, dT[u] + dS[v]);
        }
        return ans;
    }
}

namespace SUBTASKFULL
{

    void SOLVE()
    {
        vector<Edge> Ea;
        vector<Edge> Eb;
        for (int i = 1; i <= M; i++)
        {
            if (E[i].id == 1)
                Ea.pb(E[i]);
            if (E[i].id == 2)
                Eb.pb(E[i]);
        }
        sort(Ea.begin(), Ea.end());
        sort(Eb.begin(), Eb.end());
        int La = 0;
        int Ra = (int)Ea.size();

        int ansA = 0;
        int ansB = 0;
        int ans = oo;
        while (La <= Ra)
        {
            int Ma = (La + Ra) >> 1;
            ansA = Ea[Ma - 1].w;
            int Lb = 0;
            int Rb = (int)Eb.size();
            int tmp = oo;
            while (Lb <= Rb)
            {
                int Mb = (Lb + Rb) >> 1;
                ansB = Eb[Mb - 1].w;
                Init();
                for (int i = 0; i < Ma; i++)
                    DSU(Ea[i].u, Ea[i].v);
                for (int i = 0; i < Mb; i++)
                    DSU(Eb[i].u, Eb[i].v);
                if (root(S) == root(T))
                {
                    tmp = min(tmp, ansA + ansB);
                    Rb = Mb - 1;
                }
                else
                    Lb = Mb + 1;
            }
            if (ans > tmp)
            {
                ans = tmp;
                Ra = Ma - 1;
            }
            else
                La = Ma + 1;
        }
        cout << min(ans, SUBTASK_3 ::SOLVE()) << '\n';
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> N >> M >> S >> T;
    int cnt = 0;
    for (int i = 1; i <= M; i++)
    {
        int id, u, v, c;
        cin >> id >> u >> v >> c;
        E[i] = {id, u, v, c};
        cnt += (id == 2);
    }
    // cerr << oo - (int)2e9 << '\n';
    if (cnt == 0 || cnt == M)
    {
        SUBTASK_1 ::SOLVE();
        return 0;
    }
    if (N <= 5000)
    {
        SUBTASK_2 ::SOLVE();
        return 0;
    }
    SUBTASKFULL ::SOLVE();
}
