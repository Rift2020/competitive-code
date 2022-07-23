#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
int t,n,a,b;
int ans[100005];
signed main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n>>a>>b;
        int cnt=0,tp=n+1;
        if(a+b>n-2||abs(a-b)>1)
            cout<<-1<<endl;
        else{
           if(a>b){
               ans[1]=++cnt;
               ans[n]=++cnt;
           } else if(a<b){
             ans[n]=--tp;
             ans[1]=--tp;  
           }
           else{
               ans[1]=++cnt;
               ans[n]=--tp;
           }
           if(ans[1]==1){
               for(int i=3;b;i+=2,--b)ans[i]=++cnt;
               for(int i=2;a;i+=2,--a)ans[i]=++cnt;
                for(int i=n-1;cnt+1<=tp-1;i--)ans[i]=--tp;
           }
           else{
               for(int i=2;b;i+=2,--b)ans[i]=++cnt;
               for(int i=3;a;i+=2,--a)ans[i]=++cnt;
                for(int i=n-1;cnt+1<=tp-1;i--)ans[i]=--tp;
           }
           rep(i,1,n){
               cout<<ans[i]<<" ";
           }
           cout<<endl;
        }
    }
    
    
    
    return 0;
}