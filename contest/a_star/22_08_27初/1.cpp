/**
 *    author:  Rift
 *    created: 2022.08.27  14:03
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define maxn 105
using namespace std;
using ll = long long;
using pr = pair<int,int>;
int t,n;
int g[maxn][maxn];
int vis[maxn],se;
void dfs(int x){
	if(vis[x])return;
	vis[x]=se;
	rep(j,1,n){
		if(g[x][j])
			dfs(j);
	}
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>t;
	while(t--){
		cin>>n;
		memset(vis,0,sizeof(vis));
		rep(i,1,n){
			rep(j,1,n){
				cin>>g[i][j];
			}
		}
		for(se=1;se<=n;++se){
			dfs(se);
		}

	}
	
	
	return 0;
}
