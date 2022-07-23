#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define int ll
using namespace std;
using ll = long long;
int t,n;
int inline fpow(int x,int n){
    int re=1;
    while(n){
        if(n&1)
            re*=x;//re=(x*re)%mod
        x*=x;//x=(x*x)%mod
        n>>=1;
    }
    return re;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>n;
        if(n>=20)cout<<"NO"<<endl;
        else {
            cout<<"YES"<<endl;
            for(int i=0;i<n;++i){
                cout<<fpow(3,i)<<" ";
            }
            cout<<endl;
        }
    }   
    
    
    
    return 0;
}