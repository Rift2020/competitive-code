#include<bits/stdc++.h>
		#define maxn 100005
typedef pair<int,int> nod;//dis,u
struct edge{
	int v,w;
};
vector<edge> g[maxn];
priority_queue<nod,vector<nod>,greater<nod> > pq;
int dis[maxn];
bool vis[maxn];
void dijkstr(){
	dis[s]=0;
	pq.push(nod{0,s});
	while (!pq.empty()) {
		int u=pq.top().second;
		pq.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(auto i:g[u]){
			int v=i.v,w=i.w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				pq.push(nod{dis[v],v});
			}
		}
	}
}
	rep(i,1,n)dis[i]=INT_MAX;
	rep(i,1,m){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back(edge{v,w});
	}
	rep(i,1,n)cout<<dis[i]<<" ";