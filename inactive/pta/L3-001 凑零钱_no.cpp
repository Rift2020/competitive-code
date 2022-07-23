#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 10005
#define maxm 105
using namespace std;
using ll = long long;
int n,m;
typedef pair<int,int> pr;//last,value
bool dp[maxm];
pr path[maxm];
int co[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    rep(i,1,n)cin>>co[i];
    sort(co+1,co+n+1,greater<int>());
    dp[0]=true;
    rep(i,1,n){
        for(int j=m;j-co[i]>=0;--j){
            if(dp[j-co[i]]){
                path[j]={j-co[i],co[i]};
                dp[j]=true;
                //if(j==m)break;
            }
        }
        //if(dp[m])break;
    }
    if(dp[m]==false){
        cout<<"No Solution"<<endl;
    }
    else{
        vector<int> ans;
        for(int now=m;now!=0;now=path[now].first){
            ans.push_back(path[now].second);
        }
        for(int i=ans.size()-1;i>=0;--i){
            cout<<ans[i]<<" ";
        }
    }
    
    
    return 0;
}