#include<bits/stdc++.h>
#define maxn 105
using namespace std;
int n;
int a[maxn];
int dp[maxn],dp2[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
        dp[i]=dp2[i]=1;
    }
    for(int i=1;i<n;++i){
        for(int j=0;j<i;++j){
            if(a[j]<a[i])
                dp[i]=max(dp[i],dp[j]+1);
        }
    }
    for(int i=n-2;i>=0;--i){
        for(int j=n-1;j>i;--j){
            if(a[j]<a[i]){
                dp2[i]=max(dp2[i],dp2[j]+1);
            }
        }
    }
    int ans=dp[0]+dp2[0]-1;
    for(int i=0;i<n;++i){
        ans=max(ans,dp[i]+dp2[i]-1);
    }
    cout<<n-ans<<endl;
    return 0;
}