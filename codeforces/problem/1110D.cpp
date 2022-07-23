#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 1000005
using namespace std;
using ll = long long;
int n,m,ans;
int a[maxn];
int dp[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    rep(i,1,n){
        int in;
        cin>>in;
        a[in]++;
    }
    rep(i,1,m){
        if(i>=3){
            int t=min({a[i-2],a[i-1],a[i],2});
            rep(j,1,t){
                dp[i]=max(dp[i-1],dp[i-3]+j-a[i-2]/3+(a[i-2]-j)/3-a[i-1]/3+(a[i-1]-j)/3);
            }
        }
        dp[i]=max({dp[i],dp[i-1]+a[i]/3});
    }
    cout<<dp[m]<<endl;
    
    return 0;
}