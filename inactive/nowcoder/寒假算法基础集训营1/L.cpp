#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
int t,n;

signed main(){
    ios::sync_with_stdio(false);cout<<setiosflags(ios::fixed);
    cin>>t;
    while(t--){
        cin>>n;
        double x=0,y=0,ans=0;
        rep(i,1,n){
            char c;
            cin>>c;
            if(c=='U')y+=1;
            else if(c=='D')y-=1;
            else if(c=='L')x-=1;
            else if(c=='R')x+=1;
            ans=max(ans,sqrt(x*x+y*y));
        }
        cout<<std::setprecision(7)<<ans<<endl;
    }
    
    
    
    return 0;
}