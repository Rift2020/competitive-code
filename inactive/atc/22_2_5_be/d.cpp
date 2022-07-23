#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
int t;
ll a,s;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>a>>s;
        ll n=s-2*a;
        if(n>=0&&(n&a)==0)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    
    
    
    return 0;
}