#include<bits/stdc++.h>
		#define maxn 200005
vector<int> v[maxn];
int dep[maxn];
int rd[maxn];
bool vis[maxn];
bool hl;
void dfs(int x,int d){
	//cout<<x<<" "<<d<<endl;
	dep[x]=max(dep[x],d);
	vis[x]=true;
	for(int i:v[x]){
		if(vis[i]){
			hl=true;
			return;
		}
		dfs(i,d+1);
	}
	vis[x]=false;
}
	while (t--) {
		cin>>n;
		rep(i,1,n){
			v[i].clear();
			dep[i]=0;
			vis[i]=false;
			hl=false;
		}
		rep(i,1,n){
			int k;
			cin>>k;
			rd[i]=k;
			rep(j,1,k){
				int in;
				cin>>in;
				v[in].push_back(i);
			}
		}
		/*
		rep(i,1,n){
			cout<<':'<<endl;
			for(int i:v[i])cout<<i<<" ";
			cout<<endl;
		}
		*/
		rep(i,1,n){
			if(rd[i]==0)dfs(i,1);
		}
		if(hl)cout<<-1<<endl;
		else{
			int ans=1;
			rep(i,1,n){
				ans=max(ans,dep[i]);
			}
			cout<<ans<<endl;
		}
	}