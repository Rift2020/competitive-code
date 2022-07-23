#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define int long long
using namespace std;
using ll = long long;
int t;
int l,r;
int sol(int i,int x){
    return i%(1LL<<x)+1;
}
signed main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>l>>r;
        int ans=1e9;
        int now;
        for(int i=0;(l>>(i+1))>0||(r>>(i+1))>0;++i){
            now=0;
            int mi=l|(1LL<<i);
            int ma;
            if((r|(1LL<<i))==r)ma=r;
            else ma=(r-(1LL<<(i+1)))|((1LL<<(i+1))-1);
            int le1=(mi>>(i+1)),le2=(ma>>(i+1));
            if(le2>le1){
                now=(1LL<<i)*(le2-le1-1);
                now+=(1LL<<(i))-sol(mi,i)+1+sol(ma,i);
            }
            else{
                now=sol(ma,i)-sol(mi,i)+1;
            }
            ans=min(ans,r-l+1-now);
        }
        cout<<ans<<endl;
    }
    
    
    
    return 0;
}