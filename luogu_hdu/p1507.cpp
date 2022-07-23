#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxw 405
#define maxn 55
using namespace std;
using ll = long long;
typedef struct{
    int vol,w,val;
} th;

int n,vol,w;
int dp[maxw][maxw];
th a[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>vol>>w>>n;
    rep(i,1,n){
        cin>>a[i].vol>>a[i].w>>a[i].val;
    }
    rep(i,1,n){
        per(j,vol,a[i].vol){
            per(k,w,a[i].w){
                dp[j][k]=max(dp[j][k],dp[j-a[i].vol][k-a[i].w]+a[i].val);
            }
        }
    }
    int ans=0;
    rep(i,0,vol){
        rep(j,0,w){
            ans=max(ans,dp[i][j]);
        }
    }
    cout<<ans<<endl;
    
    return 0;
}