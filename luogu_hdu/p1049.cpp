#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define maxn 35
#define maxv 20005
using namespace std;
using ll = long long;
typedef pair<int,int> pr;//weight,value
int n,v;
pr th[maxn];
int dp[maxv];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>v>>n;
    rep(i,1,n){
        cin>>th[i].x;
        th[i].y=th[i].x;
    }
    rep(i,1,n){
        per(j,v,th[i].x){
            dp[j]=max(dp[j],dp[j-th[i].x]+th[i].y);
        }
    } 
    int ans=0;
    rep(i,0,v)ans=max(ans,dp[i]);
    cout<<v-ans<<endl;
    
    return 0;
}