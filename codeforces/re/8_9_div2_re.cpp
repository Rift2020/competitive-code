#include<bits/stdc++.h>
#define mod 1000000007
#define int long long
#define maxn 200005
using namespace std;
int t,n,k;
int inline fpow(int x,int n){
    int re=1;
    while(n){
        if(n&1)
            re=(x*re)%mod;
        x=(x*x)%mod;
        n>>=1;
    }
    return re;
}
signed main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n>>k;
        int t0=fpow(2,n-1);
        if(n%2==1){
            cout<<fpow(t0+1,k)<<endl;
        }
        else{
            long long ans=fpow(t0-1,k);
            for(int i=1;i<=k;++i){
                ans+=fpow(t0-1,i-1)*(fpow(2,n*(k-i)));
                ans%=mod;
            }
            cout<<ans<<endl;
        }
    }
    
    
    return 0;
}