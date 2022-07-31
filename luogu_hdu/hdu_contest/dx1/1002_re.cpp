/**
 *    author:  Rift
 *    created: 2022.07.21  09:41
**/
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxk 35
using namespace std;
using ll = long long;
int t,n,m,k;
int sx,sy,ex,ey;
typedef struct{
    int x,y,x2,y2;
}wall;
wall w[maxk];
bool sw[maxk];
bool blk[maxk][maxk];
bool vis[maxk][maxk];
bool fl;
int ans;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
void dfs(int x,int y){
    if(x==ex&&y==ey){
        fl=true;
        return;
    }
    if(vis[x][y])return;
    if(x<0||y<0||x>n||y>m)return;
    if(blk[x][y])return;
    vis[x][y]=true;
    rep(i,0,3){
        dfs(x+dx[i],y+dy[i]);
    }
}
void check(){
    memset(blk,0,sizeof(blk));
    int ds=k;
    rep(i,1,k){
        if(sw[i]){
            wall wa=w[i];
            if(wa.x==wa.x2){
                rep(j,wa.y,wa.y2)blk[wa.x][j]=true;
            }
            else{
                rep(j,wa.x,wa.x2)blk[j][wa.y]=true;
            }
            ds--;
        }
    }
    if(ds>=ans)return;
    fl=false;
    memset(vis,0,sizeof(vis));
    dfs(sx,sy);
    if(fl){
        ans=min(ans,ds);
    }
}
void force(int now){
    if(now==k+1){
        check();
        return;
    }
    sw[now]=true;
    force(now+1);
    sw[now]=false;
    force(now+1);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        n*=2;
        m*=2;
        cin>>sx>>sy>>ex>>ey;
        sx=sx*2+1,sy=sy*2+1,ex=ex*2+1,ey=ey*2+1;
        rep(i,1,k){
            cin>>w[i].x>>w[i].y>>w[i].x2>>w[i].y2;
            w[i].x*=2,w[i].y*=2,w[i].x2*=2,w[i].y2*=2;
        }
        ans=INT_MAX;
        force(1);
        cout<<ans<<endl;
    }


}
