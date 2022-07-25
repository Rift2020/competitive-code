#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)
		#define maxn 5005		using namespace std;using ll = long long int;int n,m;
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
}int main(){	ios::sync_with_stdio(false);	cin>>n>>m;
	rep(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		g[x].push_back({z,y});
		g[y].push_back({z,x});
	}	int ans=prim();
	rep(i,1,n){
		if(has[i]==false){
			cout<<"orz"<<endl;
			return 0;
		}
	}	cout<<ans<<endl;		return 0;}