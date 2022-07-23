#include<bits/stdc++.h>
using namespace std;
int n,m,v[30],w[30],dp[30][30005];
int main(){
    cin>>n>>m;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<m;++i){
        cin>>v[i]>>w[i];
        w[i]*=v[i];
    }
    for(int i=m-1;i>=0;--i){
        for(int j=0;j<=n;++j){
            if(j<v[i])
                dp[i][j]=dp[i+1][j];
            else
                dp[i][j]=max(w[i]+dp[i+1][j-v[i]],dp[i+1][j]);
        }
    }
    cout<<dp[0][n];
    return 0;
}