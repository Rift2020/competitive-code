#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 105
using namespace std;
using ll = long long;
int t,n;
bool dp[maxn][10005];
int a[maxn];
int b[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>n;
        rep(i,1,n)cin>>a[i];
        rep(i,1,n)cin>>b[i];
        rep(i,1,n)memset(dp[i],false,sizeof(dp[i]));
        dp[0][0]=true;
        rep(i,1,n){
            int d=abs(a[i]-b[i]);
            rep(j,0,10000){
                if(dp[i-1][j]){
                    dp[i][abs(j-d)]=true;
                    dp[i][j+d]=true;
                }
            }
        }
        int minD;
        rep(i,0,10000){
            if(dp[n][i]){
                minD=i;
                break;
            }
        }
        int sum=0,ans=0;
        rep(i,1,n){
            sum+=a[i]+b[i];
            ans+=a[i]*a[i]+b[i]*b[i];
        }
        ans*=(n-2);
        int suma=(sum-minD)/2;
        int sumb=sum-suma;
        ans+=suma*suma+sumb*sumb;
        cout<<ans<<endl;
    }
    
    
    
    return 0;
}