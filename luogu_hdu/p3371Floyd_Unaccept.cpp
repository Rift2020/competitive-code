#include<bits/stdc++.h>
using namespace std;
int n,m,s;
int main(){
	cin>>n>>m>>s;
	int g[n+1][n+1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			if(i==j)g[i][j]=0;
			else g[i][j]=1000000;
		}
	for(int i=0;i<m;++i){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		if(w<g[u][v]){
			g[u][v]=w;
		}
	}
	int an[n+1][n+1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			an[i][j]=g[i][j];
		}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j){
				an[i][j]=min(an[i][j],an[i][k]+an[k][j]);
			}
	for(int i=1;i<=n;++i)
		printf("%d ",an[s][i]);
	return 0;
}