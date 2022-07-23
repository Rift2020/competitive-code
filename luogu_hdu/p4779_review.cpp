#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,m,s;
unordered_map<int,int> um[maxn];//num,len
int dist[maxn];
bool vis[maxn];
typedef pair<int,int> nod;//len,num
priority_queue<nod,vector<nod>,greater<nod> > pq;
void relax(){
    pq.push(nod(0,s));
    while(!pq.empty()){
        int now=pq.top().second;
        pq.pop();
        if(vis[now])continue;
        vis[now]=true;
        for(auto i:um[now]){
            int s=i.second,k=i.first;
            if(dist[k]>dist[now]+s){
                dist[k]=dist[now]+s;
                pq.push(nod(dist[k],k));
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    int u,v,w;
    cin>>n>>m>>s;
    for(int i=0;i<=n;++i)dist[i]=INT_MAX;
    dist[s]=0;
    for(int i=0;i<m;++i){
        cin>>u>>v>>w;
        if(um[u].find(v)==um[u].end()||w<um[u][v]){
            um[u][v]=w;
        }
    }
    relax();
    for(int i=1;i<=n;++i)cout<<dist[i]<<" ";
    
    return 0;
}