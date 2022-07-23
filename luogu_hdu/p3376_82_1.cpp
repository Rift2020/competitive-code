#include<bits/stdc++.h>
#define maxn 205
#define ll long long
using namespace std;
typedef struct{
    int to;//边指向的下一个点
    int cap;//边能承载的最大流量
    int rev;//反向边邻接表的索引，vec[to][rev]即为反向边
}edge;
}edge;
vector<edge> vec[maxn];//邻接表
int n,m,s,t;
bool vis[maxn];//是否访问过
int dfs(int x,int f){
    if(x==t)return f;//到达终点
    if(f<=0)return f;
    vis[x]=true;
    for(auto &e:vec[x]){
        if(vis[e.to]==false&&e.cap>0){
            int mi=dfs(e.to,min(f,e.cap));//继续搜索并且传递过往边的流量最小值
            if(mi>0){
                e.cap-=mi;//经过边减少
                vec[e.to][e.rev].cap+=mi;//反向边增加
                return mi;
            }
        }
    }
    return 0;
}
ll inline max_flow(){
    ll re=0;
    while(true){
        memset(vis,0,sizeof(vis));
        int f=dfs(s,INT_MAX);
        if(f>0)
            re+=f;
        else
            break;
    }
    return re;
}
void inline add_edge(int u,int v,int w){
    vec[u].push_back(edge{v,w,vec[v].size()});//这里很巧妙，vec[v].size()就是下一个push的下标
    vec[v].push_back(edge{u,0,vec[u].size()-1});
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>s>>t;
    for(int i=0;i<m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        add_edge(u,v,w);
    }
    cout<<max_flow()<<endl;
    return 0;
}