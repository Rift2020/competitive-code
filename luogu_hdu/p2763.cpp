/**
 *    author:  Rift
 *    created: 2022.11.19  07:19
**/
#include<bits/stdc++.h>
#include <vector>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define x first
#define y second
#define maxn 2005
#define maxm 30010//maxm 必须设为两倍

using namespace std;
using ll = long long;
using pr = pair<int,int>;
int n,m,k;
vector<int> ans[25];
struct edge{
    int from,to,flow,cap;//from实际上用不到
};
struct dinic{
    int n,m,s,t;//n实际上用不到
    edge eg[maxm];//边，[0,n)索引存边
    vector<int> g[maxn];//g[u]存着点u为起点的边，值为eg的索引
    int dep[maxn];//残量网络中，点i的层数
    int cur[maxn];//用于当前弧优化(一次建层中，一条边增广过，那么就不可能被增广第二次)
    bool vis[maxn];

    queue<int> q,cl;

    void init(int n){
        for(int i=0;i<=n;++i)
            g[i].clear();
        m=0;
    }
    void add_edge(int u,int v,int cap){
        //cout<<u<<" "<<v<<" "<<cap<<endl;
        g[u].push_back(m);
        eg[m++]={u,v,0,cap};
        g[v].push_back(m);
        eg[m++]={v,u,0,0};

    }
    bool bfs(){//分层
        memset(vis,0,sizeof(vis));
        q=cl;
        q.push(s);
        dep[s]=0;
        vis[s]=1;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int i:g[u]){
                edge &e=eg[i];
                if(vis[e.to]||e.cap==e.flow)continue;
                vis[e.to]=1;
                dep[e.to]=dep[u]+1;
                q.push(e.to);
            }
        }
        return vis[t];
    }
    int dfs(int u,int left){//当前增广的节点，流到这个点的流量
        if(u==t||left==0)return left;
        int flow=0,f;
        for(int &i=cur[u];i<g[u].size();++i){//当前弧优化&多路增广
            edge &e=eg[g[u][i]];
            edge &fe=eg[g[u][i]^1];//反向边
            if(dep[u]+1!=dep[e.to])continue;
            f=dfs(e.to,min(left,e.cap-e.flow));
            if(f==0)continue;
            e.flow+=f;
            fe.flow-=f;
            flow+=f;
            left-=f;
            if(left==0)break;
        }
        return flow;
    }
    int MaxFlow(int s,int t){
        this->s=s;
        this->t=t;
        int flow=0;
        while(bfs()){
            memset(cur,0,sizeof(cur));
            flow+=dfs(s,INT_MAX);
        }
        return flow;
    }
};
dinic d1;
signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    cin>>k>>n;
    d1.init(n+k+2);
    int s=n+k+1,t=n+k+2;
    for(int i=n+1;i<=n+k;++i){
        int in;
        cin>>in;
        d1.add_edge(i,t,in);
        m+=in;
    }
    for(int i=1;i<=n;++i){
        d1.add_edge(s,i,1);
    }
    for(int i=1;i<=n;++i){
        int t;
        cin>>t;
        rep(j,1,t){
            int in;
            cin>>in;
            d1.add_edge(i,n+in,1);
        }
    }
    int f=d1.MaxFlow(s,t);
    if(f<m){
        cout<<"No Solution!"<<endl;
    }
    else{
        for(int i=1;i<=n;++i){
            for(int j:d1.g[i]){
                int v=d1.eg[j].to;
                int f=d1.eg[j].flow;
                int cap=d1.eg[j].cap;
                if(v!=s&&f>0){
                    //cout<<i<<" "<<v<<" "<<f<<" "<<cap<<endl;
                    //assert(v-n>0&&v-n<=k);
                    ans[v-n].push_back(i);
                }
            }
        }
        for(int i=1;i<=k;++i){
            cout<<i<<": ";
            for(int j:ans[i]){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}
