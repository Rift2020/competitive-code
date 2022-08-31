/**
 *    author:  Rift
 *    created: 2022.08.27  14:11
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define maxn 10005
using namespace std;
using ll = long long;
using pr = pair<int,int>;
int n,m;
int h[maxn][maxn];
int vis[maxn][maxn];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
typedef struct{
	int d,x,y;
}st;
queue<st> q;//dis,ind
int inline read(){
    int s=0,f=1;
    char c=getchar();
    while(!(c<='9'&&c>='0')){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c<='9'&&c>='0'){
        s=(s<<1)+(s<<3);
        s+=c-'0';
        //s%=mod;
        c=getchar();
    }
    return f*s;
}
signed main(){
	n=read(),m=read();
	rep(i,1,n){
		rep(j,1,m){
			h[i][j]=read();
			if(h[i][j]==0){
				q.push({1,i,j});
			}
		}
	}
	while(!q.empty()){
		st tp=q.front();
		q.pop();
		vis[tp.x][tp.y]=tp.d;
		for(int i=0;i<4;++i){
			int nx=tp.x+dx[i];
			int ny=tp.y+dy[i];
			if(h[nx][ny]>=h[tp.x][tp.y]&&nx>=1&&nx<=n&&ny>=1&&ny<=m&&(vis[nx][ny]==0||vis[nx][ny]>tp.d+1))
				q.push({tp.d+1,nx,ny});
		}
	}	
	rep(i,1,n){
		rep(j,1,m){
			printf("%d ",vis[i][j]-1);
		}
		printf("\n");
	}
	return 0;
}
