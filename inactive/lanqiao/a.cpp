#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;
int ans=0;
void dfs(int x,int s,int fa){
    if(x==10){
        if(s>fa)
            ++ans;
        return;
    }
    if(s<=fa)return;
    for(int i=fa+1;i<=s/(10-x+1);++i)
        dfs(x+1,s-i,i);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    dfs(1,2022,0);
    cout<<ans<<endl;
    
    
    return 0;
}