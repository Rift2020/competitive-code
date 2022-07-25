#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 5005using namespace std;using ll = long long int;int t,n,cnt;
vector<int> g[maxn];
bool vis[maxn];
int dfs(int x,int fa){
	int fl=true;
	if(g[x].size()!=3)fl=false;
	int s=1;
	for(int v:g[x]){
		if(v==fa)continue;
		if(dfs(v,x)!=1)fl=false;
		s+=dfs(v,x);
	}
	if(fl)return 1;
	return s;
}
int main(){	ios::sync_with_stdio(false);	cin>>t;
	while(t--){
		cin>>n;
		cnt=0;
		rep(i,1,n)g[i].clear();
		memset(g,false,sizeof(g));
		int u,v;
		rep(i,1,n-1){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(dfs(1,0)%2==0){
			cout<<"Bob"<<endl;
		}
		else{
			cout<<"Alice"<<endl;
		}
		
	}				return 0;}