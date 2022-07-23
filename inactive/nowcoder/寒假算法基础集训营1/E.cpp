#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
int t,n,m;
signed main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n>>m;
        if(m==1){
            if(n==1)cout<<1<<endl;
            else cout<<-1<<endl;
            continue;
        }
        int ans=1;
        n-=m;
        ans+=n/(m-1)*2;
        if(n%(m-1)>0)ans+=2;
        cout<<ans<<endl;
    }
    
    
    
    return 0;
}