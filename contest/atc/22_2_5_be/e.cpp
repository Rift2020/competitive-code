#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 200005
using namespace std;
using ll = long long;
int n,q;
vector<int> g[maxn];
bool vis[maxn];
void dfs(int u){
    if(vis[u])return;
    vis[u]=true;
    if(u==n+1){
        cout<<"Yes"<<endl;
        exit(0);
    }
    for(int v:g[u]){
        dfs(v);
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int l,r;
    cin>>n>>q;
    rep(i,1,q){
        cin>>l>>r;
        g[l].push_back(r+1);
        g[r+1].push_back(l);
    }
    dfs(1);
    cout<<"No"<<endl;
    
    
    return 0;
}