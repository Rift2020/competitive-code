#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 105using namespace std;using ll = long long;
vector<int> g[maxn];
vector<int> now;
vector<int> czd;
int mat[maxn][maxn];int t,n,m,s,ans;
bool check(){
	//cout<<':';
	//for(int i:czd)cout<<i<<" ";
	//cout<<endl;
	for(int i=0;i<czd.size();++i){
		for(int j=i+1;j<czd.size();++j){
			if(mat[czd[i]][czd[j]]==0)return false;
		}
	}
	return true;
}
void cz(int i,int n){
	int d=czd.size();
	if(i==n||d==s){
		if(check())
			++ans;
		return;
	}
	if(n-i+d==s){
		czd.push_back(now[i]);
		cz(i+1,n);
		czd.pop_back();
	}
	else{
		czd.push_back(now[i]);
		cz(i+1,n);
		czd.pop_back();
		cz(i+1,n);
	}
}
void solve(int x){
	//cout<<x<<':'<<endl;
	now=g[x];
	czd.clear();
	czd.push_back(x);
	cz(0,g[x].size());
}signed main(){	ios::sync_with_stdio(false);	cin>>t;
	while(t--){
		cin>>n>>m>>s;
		ans=0;
		memset(mat,0,sizeof(mat));
		rep(i,1,n)g[i].clear();
		rep(i,1,m){
			int a,b;
			cin>>a>>b;
			if(a>b)swap(a,b);
			g[a].push_back(b);
			mat[a][b]=mat[b][a]=1;
		}
		rep(i,1,n)sort(g[i].begin(),g[i].end());
		for(int i=1;i<=n;++i){
			if(g[i].size()>=s-1)
				solve(i);
		}
		cout<<ans<<endl;
	}				return 0;}