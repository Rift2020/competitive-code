#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 1005
using namespace std;
using ll = long long;
int n,m;
int c[maxn];
int dist[maxn];
int vis[maxn];
typedef pair<int,int> pr;//w,v
unordered_map<int,int> g[maxn];
void dij(){
    rep(i,1,n)dist[i]=1e8;
    dist[1]=0;
    priority_queue<pr,vector<pr>,greater<pr> >pq;
    pq.push({0,1});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(vis[u])continue;
        vis[u]=true;
        for(auto i:g[u]){
            int v=i.first;
            int w=i.second+c[v];
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                pq.push({w,v});
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    rep(i,1,n)cin>>c[i];
    rep(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        if(g[u].find(v)==g[u].end()){
            g[u][v]=w;
            g[v][u]=w;
        }
        else{
            g[u][v]=min(g[u][v],w);
            g[v][u]=min(g[v][u],w);
        }
    }
    dij();
    cout<<dist[n]-c[n]<<endl;
    
    return 0;
}