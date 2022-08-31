#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 365
using namespace std;
using ll = long long;
int n;
int a[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    int in;
    a[0]=0;
    for(int i=1;i<=n;++i){
        cin>>in;
        in+=a[i-1];
        in%=360;
        a[i]=in;
    }
    sort(a,a+n+1);
    int ans=0;
    for(int i=0;i<n;++i){
        ans=max(ans,a[i+1]-a[i]);
    }
    ans=max(ans,360-a[n]);
    cout<<ans<<endl;
    
    return 0;
}