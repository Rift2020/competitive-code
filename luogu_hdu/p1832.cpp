#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 1005
using namespace std;
using ll = long long;
int n;
ll dp[maxn];
bool isPrime(int x){
    if(x==1)return false;
    for(int i=2;i*i<=x;++i){
        if(x%i==0)return false;
    }
    return true;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    dp[0]=1;
    rep(i,2,n){
        if(isPrime(i))
        for(int l=i;l<=n;++l){
            dp[l]+=dp[l-i];
        }
    }
    
    cout<<dp[n]<<endl;
    
    
    return 0;
}