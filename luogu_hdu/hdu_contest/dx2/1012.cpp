/**
 *    author:  Rift
 *    created: 2022.07.25  19:49
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define maxn 100005
#define int ll
using namespace std;
using ll = long long;
int dp[maxn];
int t,n;
int v[]={7,31,365};
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int &i:dp)i=LONG_LONG_MAX/2;
    dp[0]=0;
    for(int i=0;i<3;++i){
        for(int j=0;j<maxn-v[i]-1;++j){
            dp[j+v[i]]=min(dp[j+v[i]],dp[j]+1);
        }
    }
    cin>>t;
    while(t--){
        cin>>n;
        int k=n/365;
        k-=50;
        if(k<=0){
            if(dp[n]==LONG_LONG_MAX/2)
                cout<<-1<<endl;
            else
                cout<<dp[n]<<endl;
        }
            
        else{
            n-=k*365;
            if(dp[n]==LONG_LONG_MAX/2)
                cout<<-1<<endl;
            else
                cout<<dp[n]+k<<endl;
        }
    }
    
    return 0;
}