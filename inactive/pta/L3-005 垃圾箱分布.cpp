#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define maxn 1015
#define maxm 15
#define x first
#define y second
using namespace std;
using ll = long long;
int n,m,k,md;
int inline read(){
    string in;
    in.resize(20);
    scanf("%s",&in[0]);
    if(in[0]=='G'){
        return atoi(in.substr(1).c_str())+n;
    }
    return atoi(in.c_str());
}
typedef pair<int,int> pr;//w,ind //dis,nod
vector<pr> g[maxn];
bool vis[maxn];
int dis[maxm][maxn];
void dij(int x){
    priority_queue<pr,vector<pr>,greater<pr> > pq;
    pq.push({0,x});
    dis[x-n][x]=0;
    while(!pq.empty()){
        int now=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        if(vis[now])continue;
        vis[now]=true;
        for(pr nod:g[now]){
            int nd=nod.x;
            int v=nod.y;
            //if(v>n&&v!=x)continue;
            if(dis[x-n][now]+nd<dis[x-n][v]){
                dis[x-n][v]=dis[x-n][now]+nd;
                pq.push({dis[x-n][v],v});
            }
        }
    }
}
signed main(){
    //ios::sync_with_stdio(false);
   // cin.tie(nullptr);
    cin>>n>>m>>k>>md;
    rep(i,1,k){
        int u,v,w;
        u=read(),v=read(),w=read();
        g[u].push_back({w,v});
        g[v].push_back({w,u});
    }
    rep(i,1,m){
        rep(j,1,n+m){
            dis[i][j]=1e8;
        }
    }
    rep(i,1,m){
        memset(vis,0,sizeof(vis));
        dij(n+i);
    }
    int ans;
    double mi=-1,aav=1e9;
    rep(i,1,m){
        double avg=0;
        int mii=1e9;
        int ma=-1;
        rep(j,1,n){
            mii=min(mii,dis[i][j]);
            ma=max(ma,dis[i][j]);
            avg+=dis[i][j];
        }
        if(ma<=md&&mii>mi||(ma<=md&&mii==mi&&avg/n<aav)){
            ans=i;
            mi=mii;
            aav=avg/n;
        }
    }
    if(mi==-1){
        printf("No Solution\n");
    }
    else{
        printf("G%d\n",ans);
        printf("%.1f %.1f\n",mi,aav);
    }
    return 0;
}