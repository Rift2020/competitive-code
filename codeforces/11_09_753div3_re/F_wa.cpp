#include<bits/stdc++.h>
		#define maxn 2005
char c[maxn][maxn];
int mem[maxn][maxn];
int a,b,ans;
int dfs(int x,int y){
	if(mem[x][y]!=-1)return mem[x][y];
	int nx=x,ny=y;
	mem[x][y]=1;
	if(c[x][y]=='R')nx++;
	else if(c[x][y]=='L')nx--;
	else if(c[x][y]=='U')ny++;
	else if(c[x][y]=='D')ny--;
	if(nx>0||nx<=n||ny>0||ny<=m)
		mem[x][y]=dfs(nx,ny)+1;
	//else return mem[x][y]=1;
	return mem[x][y];
}
	while(t--){
		cin>>n>>m;
		ans=-1;
		rep(i,1,n){
			rep(j,1,m){
				mem[i][j]=-1;
				cin>>c[i][j];
			}
		}
		
		rep(i,1,n){
			rep(j,1,m){
				dfs(i,j);
				if(mem[i][j]>ans){
					a=i,b=j,ans=mem[i][j];
				}
			}
		}
		cout<<a<<" "<<b<<" "<<ans<<endl;
	}