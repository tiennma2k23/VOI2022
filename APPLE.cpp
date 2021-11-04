#include<bits/stdc++.h>
#define ld double
using namespace std;
#define ldld pair<ld,ld>
#define fi first
#define se second
ldld a[4];

ld S(ldld A, ldld B, ldld C)
{
    return (abs((B.fi-A.fi)*(C.se-A.se)-(C.fi-A.fi)*(B.se-A.se)))/2;
}

int main()
{
    freopen("APPLE.inp","r",stdin);
    freopen("APPLE.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i=1;i<=3;i++) cin>>a[i].fi>>a[i].se;
    ld s=S(a[1],a[2],a[3]);
    cout<<setprecision(1)<<fixed<<s<<"\n";
    int n;
    cin>>n;
    int ans=0;
    for (int i=1;i<=n;i++) 
    {
        ldld x;
        cin>>x.fi>>x.se;
        ld sum=0;
        for (int j=1;j<=3;j++) 
        {
            int pos1=j%3,pos2=(j+1)%3;
            if (pos1==0) pos1=3;
            if (pos2==0) pos2=3;
            sum+=S(a[pos1],a[pos2],x);
        }
        if (sum==s) ans++;
    }
    cout<<ans<<endl;
}
// 1 1
// 5 1
// 3 3
// 4
// 3 1
// 3 2
// 3 3
// 3 4