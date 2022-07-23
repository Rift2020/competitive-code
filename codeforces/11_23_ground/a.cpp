#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
int t;
int n,m;
signed main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n>>m;
        if(n==1&&m==1)cout<<0<<endl;
        else if(min(n,m)==1)cout<<1<<endl;
        else cout<<2<<endl;
    }
    
    
    
    return 0;
}