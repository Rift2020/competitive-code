#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
int t,n;
string in;
int ans;
int bn(int l,int r){
    if(l>r)return 0;
    int re=0;
    rep(i,l,r)if(in[i]=='b')++re;
    return re;
}
int cn(int l,int r){
    if(l>r)return 0;
    int re=0;
    rep(i,l,r)if(in[i]=='c')++re;
    return re;
}
int an(int l,int r){
    if(l>r)return 0;
    int re=0;
    rep(i,l,r)if(in[i]=='a')++re;
    return re;
}
signed main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        cin>>in;
        ans=1e9;
        for(int i=0;i<n;++i){
            if(in[i]=='a'){
                for(int j=i+1;j<=i+6&&j<n;++j){
                    if(in[j]=='a'&&bn(i,j)<an(i,j)&&cn(i,j)<an(i,j))
                        ans=min(ans,j-i+1);
                }
            }
        }
        if(ans==1e9)
            cout<<-1<<endl;
        else 
            cout<<ans<<endl;
    }
    
    
    
    return 0;
}