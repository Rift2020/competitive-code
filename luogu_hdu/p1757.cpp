#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 1005
using namespace std;
using ll = long long;
typedef pair<int,int> pr;//weight,value
int n,m;
int dp[maxn];
vector<pr> v[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>m>>n;
    rep(i,1,n){
        pr th;
        int j;
        cin>>th.first>>th.second>>j;
        v[j].push_back(th);
    }
    int ans=0;
    for(int z=1;z<=n;++z){
        if(v[z].empty())break;
        for(int i=m;i>=0;--i){
            for(pr j:v[z]){
                if(i-j.first<0)continue;
                dp[i]=max(dp[i],dp[i-j.first]+j.second);
            }
        }
    }
    for(int i=0;i<=m;++i)ans=max(ans,dp[i]);
    cout<<ans<<endl;
    
    return 0;
}