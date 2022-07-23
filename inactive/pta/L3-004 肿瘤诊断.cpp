#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxm 1290
#define maxn 134
#define maxl 65
using namespace std;
using ll = long long;
int m,n,l,t;
int a[maxm][maxn][maxl];
int vis[maxm][maxn][maxl];
int dx[]={1,-1,0,0,0,0};
int dy[]={0,0,-1,1,0,0};
int dz[]={0,0,0,0,1,-1};
unordered_map<int,int> mp;
typedef struct
{
    int x,y,z;
} st;
queue<st> q;
void bfs(int x,int y,int z,int n){
    q.push({x,y,z});
    while(!q.empty()){
        int x=q.front().x,y=q.front().y,z=q.front().z;
        q.pop();
        if(vis[x][y][z]||a[x][y][z]==0)continue;
        vis[x][y][z]=n;
        for(int i=0;i<6;++i){
            q.push({x+dx[i],y+dy[i],z+dz[i]});
        }
    }
    
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>m>>n>>l>>t;
    rep(k,1,l)
    rep(i,1,m){
        rep(j,1,n){
            {
                cin>>a[i][j][k];
            }
        }
    }
    int cnt=0;
    //cout<<endl;
    rep(k,1,l)
    rep(i,1,m){
        rep(j,1,n){
            {
                if(vis[i][j][k]==0&&a[i][j][k]){
                    bfs(i,j,k,++cnt);
                }
                //cout<<a[i][j][k]<<":"<<vis[i][j][k]<<" ";
            }
        }
        //cout<<endl;
    }
    rep(i,1,m){
        rep(j,1,n){
            rep(k,1,l){
                if(vis[i][j][k]){
                    mp[vis[i][j][k]]++;
                }
            }
        }
    }
    int ans=0;
    for(auto i:mp){
        if(i.second>=t)ans+=i.second;
    }
    cout<<ans<<endl;
    return 0;
}