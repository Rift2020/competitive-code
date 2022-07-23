#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
int t,x,y,n,ans;
signed main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        rep(i,1,n){
            cin>>x>>y;
            ans+=x*y;
        }
        cout<<ans<<endl;
    }
    
    
    
    return 0;
}