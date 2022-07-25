#include<bits/stdc++.h>
#define maxn 55
using namespace std;
int g[maxn][maxn];//图
int mc[maxn];//mc[i]指代[i~n]的最大团点数量
vector<int> select;//当前的团中的点
int ans;//这轮dfs中的最大团点数量
void dfs(int x,int num){
	if(num+mc[x+1]<=ans)return;//剪枝
	for(int v=x+1;v<=n;++v){
		bool ok=true;//点v与select中的点是否构成团
		for(int u:select){
			if(g[u][v]==0){
				ok=false;
				break;
			}
		}
		if(ok){
			select.push_back(v);
			dfs(v,num+1);
			select.pop_back();
		}
	}
	ans=max(ans,num);
}
void solve(){
	per(i,n,1){
		select.clear();
		select.push_back(i);
		dfs(i,1);
		mc[i]=ans;
	}
}
		if(n==0)break;
		memset(mc,0,sizeof(mc));
		ans=0;
		select.clear();
		rep(i,1,n)
			rep(j,1,n)
				cin>>g[i][j];
		solve();
		
		cout<<mc[1]<<endl;
	}