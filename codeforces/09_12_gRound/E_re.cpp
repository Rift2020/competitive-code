#include<bits/stdc++.h>
#define maxn 200005
int t,n,ans;
int dfs(int x,int fa){
	int son=0;
	for(int i:g[x]){
		if(i==fa)continue;
		son+=dfs(i,x);
	}
	//cout<<':'<<x<<endl;
	if(son==0)return 1;
	else {
		ans+=son-1;
		return 0;
	}
}
	while(t--){
		rep(i,1,n)g[i].clear();
		ans=1;
		cin>>n;
		rep(i,1,n-1){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		//cout<<"ok"<<endl;
		dfs(1,0);
		cout<<ans<<endl;
	}