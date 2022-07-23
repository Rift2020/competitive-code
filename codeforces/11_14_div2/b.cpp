#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
int t;
int a,b;
signed main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>a>>b;
        int ans=a*b/3;
        if((a*b)%3!=0)++ans;
        cout<<ans<<endl;
    }
    
    
    
    return 0;
}