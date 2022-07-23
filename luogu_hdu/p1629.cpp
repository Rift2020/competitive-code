#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 10005
using namespace std;
using ll = long long;
int n,m;
typedef pair<int,int> pr,edge;//dis,u;w,v;
priority_queue<pr,vector<pr>,greater<pr> > pq;
vector<edge> g[maxn],rg[maxn];
bool vis[maxn];
int dis[maxn];
void dijkstr(const vector<edge> ng[maxn]){
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    memset(vis,false,sizeof(vis));
    pq.push(pr{0,1});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(vis[u])continue;
        vis[u]=true;
        for(auto i:ng[u]){
            int v=i.second,w=i.first;
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                pq.push(edge{dis[v],v});
            }

        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    rep(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back(edge{w,v});
        rg[v].push_back(edge{w,u});
    }
    ll ans=0;
    dijkstr(g);
    rep(i,1,n)ans+=dis[i];
    dijkstr(rg);
    rep(i,1,n)ans+=dis[i];
    cout<<ans<<endl;
    return 0;
}