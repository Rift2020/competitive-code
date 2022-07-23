#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 50
using namespace std;
using ll = long long;
int g[maxn][maxn];
bool blk[maxn][maxn];
int t,n,m,k;
int sx,sy,ex,ey;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
void dfs(int x,int y,int p){
    if(g[x][y]!=-1&&g[x][y]<=p)return;
    if(blk[x][y]==true)++p;
    g[x][y]=p;
    for(int i=0;i<4;++i)dfs(x+dx[i],y+dy[i],p);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>sx>>sy>>ex>>ey;
        sx=sx*2+1;
        sy=sy*2+1;
        ex=ex*2+1;
        ey=ey*2+1;
        n*=2;
        m*=2;
        int x,y,x2,y2;
        rep(i,1,2){
            cin>>x>>y>>x2>>y2;
            x*=2;
            y*=2;
            x2*=2;
            y2*=2;
            if(x==x2){
                rep(j,y,y2){
                    blk[x][j]=true;
                }
            }
            else{
                rep(j,x,x2){
                    blk[j][y]=true;
                }
            }
        }
        dfs(sx,sy,0);
        cout<<g[ex][ey]<<endl;
    }
    
    
    
    return 0;
}