#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 105
#define maxm 55
#define mod 1000000007
#define int ll
using namespace std;
using ll = long long;
int dp[maxn][maxm];
int n,m,k;
int a[maxm];
bool check(int x){
    string s=to_string(x);
    for(char c:s)
        if(c=='9'||c=='7')return true;
    return false;
}
signed main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    rep(i,1,m)cin>>a[i];
    dp[0][0]=1;
    rep(r,1,n){
        rep(mo,0,k-1){
            rep(i,1,m){
                int nmo=(mo+a[i])%k;
                dp[r][nmo]=(dp[r][nmo]+dp[r-1][mo])%mod;
            }
        }
    }
    int ans=0;
    rep(i,0,k-1){
        if(check(i))
            ans=(ans+dp[n][i])%mod;
    }   
    cout<<ans<<endl;
    
    return 0;
}