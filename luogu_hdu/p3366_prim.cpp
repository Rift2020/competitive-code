#include<bits/stdc++.h>
		#define maxn 5005
typedef pair<int,int> nod;
vector<nod> g[maxn];
bool has[maxn];
priority_queue<nod,vector<nod>,greater<nod> > pq;
int prim(){
	int re=0;
	pq.push({0,1});
	while(!pq.empty()){
		int now=pq.top().second;
		int fe=pq.top().first;
		pq.pop();
		//cout<<now<<" "<<fe<<endl;
		if(has[now])continue;
		
		has[now]=true;
		re+=fe;
		for(auto nex:g[now]){
			int v=nex.second;
			int dis=nex.first;
			if(has[v])continue;
			pq.push({dis,v});
		}
	}
	return re;
}
	rep(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		g[x].push_back({z,y});
		g[y].push_back({z,x});
	}
	rep(i,1,n){
		if(has[i]==false){
			cout<<"orz"<<endl;
			return 0;
		}
	}