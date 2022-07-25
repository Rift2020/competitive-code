#include<bits/stdc++.h>
#define maxn 200005#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)		using namespace std;using ll = long long int;vector<int> g[maxn];
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
}int main(){	ios::sync_with_stdio(false);	cin>>t;
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
	}				return 0;}