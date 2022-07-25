#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 100005using namespace std;using ll = long long int;
typedef pair<int,int> pr;vector<pr> g[maxn];
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
}int main(){	ios::sync_with_stdio(false);	cin>>t;
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
	}				return 0;}