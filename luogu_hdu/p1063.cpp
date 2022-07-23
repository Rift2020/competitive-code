#include<bits/stdc++.h>
#define ll long long
#define maxn 305
using namespace std;
typedef pair<int,int> pr;
pr a[maxn];
int n;
ll dp[maxn][maxn];
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i].first;
        a[i+n].first=a[i].first;
    }
    a[n].second=a[1].first;
    a[n+n].second=a[1+n].first;
    for(int i=n-1;i>=1;--i){
        a[i].second=a[i+1].first;
        a[i+n].second=a[i+1+n].first;
    }
    for(int len=2;len<=n;++len){
        for(int i=1;i<=n*2-1;++i){
            int j=i+len-1;
            for(int k=i;k<j;++k){
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+a[i].first*a[k].second*a[j].second);
            }
        }
    }
    ll ma=0;
    for(int i=1;i<=n;++i)ma=max(ma,dp[i][i+n-1]);
    cout<<ma<<endl;
    return 0;
}