#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 10005
using namespace std;
using ll = long long int;
struct edge{
    int v,w;
};
int n,m,s;
vector<edge> g[maxn];
int dis[maxn],cnt[maxn];
bool inq[maxn];
queue<int> q;
bool spfa(){
    dis[s]=0;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        inq[u]=false;
        for(auto i:g[u]){
            int v=i.v,w=i.w;
            if(dis[u]+w<dis[v]){
                cnt[v]=cnt[u]+1;
                dis[v]=dis[u]+w;
                if(cnt[v]>=n)return false;
                if(inq[v]==false){
                    q.push(v);
                    inq[v]=true;
                }
            }
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>s;
    rep(i,1,n)dis[i]=INT_MAX;
    rep(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back(edge{v,w});
    }
    spfa();
    rep(i,1,n){
        cout<<dis[i]<<" ";
    }
    
    
    return 0;
}