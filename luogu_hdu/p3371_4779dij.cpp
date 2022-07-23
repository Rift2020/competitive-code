#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
typedef pair<int,int> nod;//len,num
int n,m,s;
int dist[maxn];//s到该点的距离
bool visit[maxn];//标记该点是否已经relax过
unordered_map<int,int> um[maxn];
void relax(){
    //Dijkstra
    priority_queue<nod,vector<nod>,greater<nod> > pq;
    pq.push(nod{0,s});
    while(!pq.empty()){
        int k=pq.top().second;
        pq.pop();
        if(visit[k])continue;
        visit[k]=true;
        for(auto it:um[k]){
            int s=it.second,i=it.first;
            if(dist[i]>dist[k]+s){
                dist[i]=dist[k]+s;
                pq.push(nod{dist[i],i});
            }
        }
    }
}
int main(){
    cin>>n>>m>>s;
    for(int i=1;i<=n;++i)dist[i]=INT_MAX;
    memset(visit,0,sizeof(visit));
    dist[s]=0;
    int u,v,w;
    for(int i=0;i<m;++i){
        cin>>u>>v>>w;
        if(um[u].find(v)==um[u].end()||um[u][v]>w)//如果有重边，存较小的
            um[u][v]=w;
    }
    relax();
    for(int i=1;i<=n;++i)
        cout<<dist[i]<<" ";
    return 0;
}