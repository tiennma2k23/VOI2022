#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=1e6+5,inf=1e18;
int p[maxn],le[maxn],ri[maxn];
int32_t main()
{
    int n,k,l;
    cin>>n>>k>>l;
    for (int i=1;i<=n;i++) cin>>p[i];
    int cnt=0;
    int tmp=0,pos=0;
    for (int i=1;i<=n;i++)
    {
        cnt++;
        if (cnt<=k) 
        {
            le[i]=tmp+p[i]-p[pos]+min(p[i],l-p[i]);
            if (cnt==k) tmp=le[i]+min(p[i],l-p[i]),pos=i;
        }
        else 
        {
            le[i]=tmp+p[i]-p[pos]+min(p[i],l-p[i]);
            cnt-=k;
            if (cnt==k) tmp=le[i]+min(p[i],l-p[i]),pos=i;
        }
    }
    
    for (int i=1;i<=n;i++) p[i]=l-p[i];
    cnt=0;
    tmp=0;
    pos=n+1;
    for (int i=n;i>=1;i--)
    {
        cnt++;
        if (cnt<=k) 
        {
            ri[i]=tmp+p[i]-p[pos]+min(p[i],l-p[i]);
            if (cnt==k) tmp=ri[i]+min(p[i],l-p[i]),pos=i;
        }
        else 
        {
            ri[i]=tmp+p[i]-p[pos]+min(p[i],l-p[i]);
            cnt-=k;
            if (cnt==k) tmp=ri[i]+min(p[i],l-p[i]),pos=i;
        }
    }
    int ans=inf;
    for (int i=0;i<=n;i++) 
    {
        ans=min(ans,le[i]+ri[i+1]);
    }
    cout<<ans<<endl;

}