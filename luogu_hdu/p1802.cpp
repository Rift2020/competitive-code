#include<bits/stdc++.h>
#define maxn 1005
#define ll long long
using namespace std;
int n,x,win[maxn],los[maxn],use[maxn];
ll dp[maxn][maxn];
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>x;
    for(int i=1;i<=n;++i){
        cin>>los[i]>>win[i]>>use[i];
    }
    //for(int i=1;i<=n;++i)dp[0][i]=dp[0][i-1]+los[i];
    //for(int i=1;i<=n;++i)cout<<dp[0][i]<<endl;
    //for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            for(int q=x;q>=0;--q){
                if(q-use[j]>=0){
                    //cout<<q<<" "<<j<<" "<<q-use[j]<<endl;
                    dp[q][j]=max(dp[q][j-1]+los[j],dp[q-use[j]][j-1]+win[j]);
                }
                else dp[q][j]=dp[q][j-1]+los[j];
            }
    cout<<dp[x][n]*5<<endl;
    return 0;
}