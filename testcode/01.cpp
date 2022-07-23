//书上实现居然连滚动数组都没有吗。。这可是O(n^2)到O(n)的空间复杂度优化...
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
int dp[10];
int w[10]={3,2,1,4,5};
int v[10]={25,20,15,40,50};
int n=5;
int pk=6;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0;i<n;++i){
        for(int j=pk;j-w[i]>=0;--j){
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[pk]<<endl;
    
    
    return 0;
}