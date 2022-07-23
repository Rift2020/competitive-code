#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
int n;
vector<int> v;
signed main(){
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,1,n){
        int in;
        cin>>in;
        v.push_back(in);
    }
    ll ans=0;
    for(int i=0;i<v.size();++i){
        for(int j=i;j<v.size();++j){
            ans+=abs(v[i]+v[j]-1000);
        }
    }
    cout<<ans<<endl;
    
    
    return 0;
}