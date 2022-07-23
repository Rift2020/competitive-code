#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
int t,n,x;
map<int,int> mp;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>n>>x;
        mp.clear();
        int in;
        rep(i,1,n){
            cin>>in;
            mp[in]++;
        }
        int ans=0;
        for(auto i:mp){
            int nd=i.first*x;
            if(mp[nd]>=mp[i.first]){
                mp[nd]-=mp[i.first];
                continue;
            }{
            
        }
            mp[i.first]-=mp[nd];
            mp[nd]=0;
            ans+=mp[i.first];
        }
        cout<<ans<<endl;
    }
    
    
    
    return 0;
}