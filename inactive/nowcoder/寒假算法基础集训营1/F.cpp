#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 100005
using namespace std;
using ll = long long;
int n,m,t;
int a[maxn];
int s,ans;
signed main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n>>m;
        s=0,ans=0;
        rep(i,1,n){
            int in;
            cin>>in;
            if(in>=m)a[i]=1;
            else a[i]=-1;
            s+=a[i];
        }
        if(s<=0){
            cout<<-1<<endl;
            continue;
        }
        int now=0;
        for(int i=1;i<=n;++i){
            if(s==1){
                ans++;
                break;
            }
            now+=a[i];
            if(now==1){
                s-=1;
                ans+=1;
                now=0;
            }
        }
        cout<<ans<<endl;
    }
    
    
    
    return 0;
}