#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 20005
using namespace std;
using ll = long long;
int n,m;
int d[maxn];
int fa[maxn];
int dep[maxn];
bool vis[maxn];
vector<int> v[maxn];
void dfs(int x,int now,int c,int f){
    if(vis[x])return;
    dep[x]=c;
    fa[x]=f;
    d[x]=now+v[x].size();
    vis[x]=true;
    for(int y:v[x])
        dfs(y,d[x],c+1,x);
}
int lca(int x,int y){
    int d1=dep[x],d2=dep[y];
    if(d1<d2){
        swap(d1,d2);
        swap(x,y);
    }
    while(d1>d2){
        x=fa[x];
        d1--;
    }
    while(x!=y){
        x=fa[x];
        y=fa[y];
    }
    return x;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    rep(i,1,n-1){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0,1,-1);
    while(m--){
        int x,y;
        cin>>x>>y;
        int l=lca(x,y);
        cout<<d[x]+d[y]-2*d[l]+v[l].size()<<endl;
    }
    
    return 0;
}
