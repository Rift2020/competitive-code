#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define dec(i,x,y) for(int i=x;i>=y;i--)
#define ll long long
#define INF 0x3f3f3f3f

char *p1,*p2,buf[100000];

const int maxn=105;
int n=4,p;
int a[maxn][maxn],b[maxn][maxn],been[maxn][maxn],now[maxn];
int dx[]={0,1,-1,0};
int dy[]={1,0,0,-1};
void dfs(int x,int y)
{
    if(x<1||y<1||x>4||y>4)return;
    if(b[x][y]==0||been[x][y])return ;
    been[x][y]=1;
    for(int i=0;i<4;i++)dfs(x+dx[i],y+dy[i]);
}
bool dfs2(int x,int y)
{
    if(x<1||y<1||x>4||y>4)return 1;
    if(b[x][y]==1)return 0;
    if(been[x][y])return 0;
    been[x][y]=1;
    bool ret=0;
    for(int i=0;i<4;i++)ret|=dfs2(x+dx[i],y+dy[i]);
    return ret;
}
bool vilIn(){
    rep(i,1,n)if(a[i]&&now[i]==false)return false;
    return true;
}
void dfs3(int i){
    if(vis[i]==true)return;
    vis[i]=true;
    int x=i/4+1;
	if(i%4==0)x--;
	int y=i-(x-1)*4;
    rep(j,1,4){
		int nx=x+dx[j];
		int ny=y+dy[j];
		//cout<<x<<" "<<y<<" "<<nx<<" "<<ny<<endl;
		if(nx<1||nx>4||ny<1||ny>4)continue;
		if(now[(nx-1)*4+ny])
			//cout<<nx<<" "<<ny<<" "<<(nx-1)*4+ny<<endl;
			dfs3((nx-1)*4+ny);
	}
}
int dfs4(int i){
    if(mem[i])return mem[i];
    int x=i/4+1;
	if(i%4==0)x--;
	int y=i-(x-1)*4;
    mem[i]=2;
    rep(j,1,4){
		int nx=x+dx[j];
		int ny=y+dy[j];
		//cout<<x<<" "<<y<<" "<<nx<<" "<<ny<<endl;
		if(nx<1||nx>4||ny<1||ny>4)return mem[i]=1;
		if(now[(nx-1)*4+ny]==false)
			if(dfs4((nx-1)*4+ny)==1)return mem[i]=1;
	}
    return mem[i]=2;
}
bool check(){
    if(vilIn()==false)return false;
    memset(vis,0,sizeof(vis));
    memset(mem,0,sizeof(mem));
    rep(i,1,n){
        if(now[i]){
            dfs3(i);
            break;
        }
    }
    rep(i,1,n){
        if(now[i]&&vis[i]==false)return false;
    }
    rep(i,1,n){
        if(now[i]==false&&dfs4(i)==2){
            return false;
        }
    }
    rep(i,1,4){
        rep(j,1,4){
            cout<<(now[(i-1)*4+j])<<" ";
        }
        cout<<endl;
    }
    return true;
}
int main()
{   
    n=4;
    rep(i,1,n)rep(j,1,n)cin>>a[i][j];
    int cnt=0;

    rep(val,1,(1<<16)-1)
    {
        int ok=1,color=0;
        rep(j,0,15)b[j/4+1][j%4+1]=min(1,((val)&(1<<j)));
        rep(i,1,4)rep(j,1,4)been[i][j]=0;
        rep(i,1,4)rep(j,1,4)if(ok)
        {
            if(b[i][j]==0&&!been[i][j])ok=dfs2(i,j);
            if(a[i][j]&&(b[i][j]==0))ok=0;
            if(b[i][j]==1)
            {
                if(color&&!been[i][j])ok=0;
                else if(!color&&!been[i][j])dfs(i,j),color=1;
            }
        }
        if(ok){
            rep(i,1,4){
                rep(j,1,4){
                    now[(i-1)*4+j]=b[i][j];
                }
            }
            if(check()==false){
            rep(i,1,4){
                rep(j,1,4){
                    cout<<b[i][j]<<" ";
                }
                cout<<endl;
            }
            }
            
        }
        cnt+=ok;
    }
    cout<<cnt<<endl;
    return 0;
}
