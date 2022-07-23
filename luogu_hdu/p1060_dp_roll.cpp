#include<bits/stdc++.h>
using namespace std;
int n,m,v[30],w[30],dp[30005];
int main(){
    cin>>n>>m;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<m;++i){
        cin>>v[i]>>w[i];
        w[i]*=v[i];
    }
    for(int i=m-1;i>=0;--i){
        for(int j=n;j>=0;--j){
            if(j>=v[i])
                dp[j]=max(w[i]+dp[j-v[i]],dp[j]);
        }
    }
    cout<<dp[n];
    return 0;
}