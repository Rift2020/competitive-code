#include<bits/stdc++.h>
#define maxn 100005
typedef pair<int,int> pr;
int a[maxn];
unordered_map<int,int> mem[maxn];
int t,n;
int dfs(int x,int fa){
	if(mem[x].find(fa)!=mem[x].end())return mem[x][fa];
	int re=0;
	for(auto p:g[x]){
		int v=p.first;
		int q=p.second;
		if(v==fa)continue;
		re=max(re,a[x]-q-a[v]+dfs(v,x));
	}
	return mem[x][fa]=re;
}
	while(t--){
		cin>>n;
		rep(i,1,n)cin>>a[i];
		rep(i,1,n)g[i].clear();
		rep(i,1,n)mem[i].clear();
		rep(i,1,n-1){
			int x,y,z;
			cin>>x>>y>>z;
			g[x].push_back({y,z});
			g[y].push_back({x,z});
		}
		int ans=0;
		rep(i,1,n){
			ans=max(ans,dfs(i,0));
		}
		cout<<ans<<endl;
	}