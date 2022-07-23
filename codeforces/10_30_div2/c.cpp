#include<bits/stdc++.h>
#define rep(i, a, b) for (long long i = (a); i <= (b); ++i)
#define per(i, a, b) for (long long i = (a); i >= (b); --i)
#define int long long
#define maxn 100005
using namespace std;
int t,n,now;
int a[maxn];
bool fl;
signed main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        fl=true;
        now=1;
        rep(i,1,n)cin>>a[i];
        rep(i,1,n){
            int ind=i+1;
            now=ind*now/__gcd(ind,now);
            if(a[i]%now==0){
                fl=false;
                break;
            }
            if(now>1e9)break;
        }
        if(fl)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    
    
    return 0;
}