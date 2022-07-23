#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 1005
using namespace std;
using ll = long long;
int fa[maxn*2];
int who(int x){
    if(fa[x]==x)return x;
    return fa[x]=who(fa[x]);
}
void merge(int x,int y){
    int nx=who(x);
    int ny=who(y);
    fa[nx]=ny;
}
int n;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    rep(i,1,maxn*2-1)fa[i]=i;
    cin>>n;
    rep(i,1,n){
        int m,in;
        char c;
        cin>>m>>c;
        rep(j,1,m){
            cin>>in;
            merge(i,n+in);
        }
    }
    map<int,int> mp;
    rep(i,1,n){
        mp[who(i)]++;
    }
    cout<<mp.size()<<endl;
    vector<int> ans;
    for(auto i:mp)ans.push_back(i.second);
    sort(ans.begin(),ans.end(),greater<int>());
    for(int i=0;i<ans.size();++i){
        if(i==0)cout<<ans[i];
        else cout<<" "<<ans[i];
    }
    cout<<endl;
    
    
    return 0;
}