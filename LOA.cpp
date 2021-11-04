#include<bits/stdc++.h>
#define ld double
#define ldld pair<ld,ld>
#define fi first
#define se second
using namespace std;
const int maxn=1e4+1;
ldld a[maxn];
ld S(ldld A, ldld B, ldld C)
{
    return (abs((B.fi-A.fi)*(C.se-A.se)-(C.fi-A.fi)*(B.se-A.se)));
}

ld dist(ldld A, ldld B)
{
    return sqrt((A.fi-B.fi)*(A.fi-B.fi)+(A.se-B.se)*(A.se-B.se));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("LOA.inp","r",stdin);
    freopen("LOA.out","w",stdout);
    ld ans=0;
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i].fi>>a[i].se;
    for (int i=1;i<=n-2;i++)
        for (int j=i+1;j<n;j++)
            for (int z=j+1;z<=n;z++)
            {
                double s=S(a[i],a[j],a[z])*2;
                double R=(dist(a[i],a[j])*dist(a[j],a[z])*dist(a[z],a[i]))/s;
                ans=max(ans,R);
            }
    cout<<setprecision(3)<<fixed<<ans<<"\n";

}
// 3
// 0 0
// 0 1
// 1 1