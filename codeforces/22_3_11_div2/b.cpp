#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 105
using namespace std;
using ll = long long;
int t,n,m;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int a[maxn][maxn];
bool vis[maxn][maxn];
int l,r,u,d,cnt;
void dfs(int x,int y){
    //cout<<":"<<x<<" "<<y<<endl;
    if(vis[x][y]||a[x][y]==0)return;
    if(x<1||x>n||y<1||y>m)return;
    ++cnt;
    vis[x][y]=true;
    u=min(u,x);
    d=max(d,x);
    l=min(l,y);
    r=max(r,y);
    for(int i=0;i<4;++i){
        int nx=x+dx[i];
        int ny=y+dy[i];
        dfs(nx,ny);
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>n>>m;
        rep(i,1,n){
            rep(j,1,m){
                char c;
                cin>>c;
                a[i][j]=c-'0';
                vis[i][j]=false;
            }
        }
        bool ok=true;
        rep(i,1,n){
            rep(j,1,m){
                
                if(a[i][j]&&!vis[i][j]){
                    r=0,l=105;
                    u=105,d=0,cnt=0;
                    dfs(i,j);
                    if((r-l+1)*(d-u+1)!=cnt){
                        ok=false;
                        break;
                    }
                }
            
            }
            if(!ok)break;
        }
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    
    
    return 0;
}