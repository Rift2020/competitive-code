#include<bits/stdc++.h>
#define maxn 205
#define ll long long
using namespace std;
typedef struct{
    int to;
    int cap;
    int rev;
vector<edge> vec[maxn];
int n,m,s,t;
bool vis[maxn];
int dfs(int x,int f){
    if(x==t)return f;
    vis[x]=true;
    int s=0;
    for(auto &e:vec[x]){
        if(vis[e.to]==false&&e.cap>0){
            int mi=dfs(e.to,min(f,e.cap));
            if(mi>0){
                e.cap-=mi;
                vec[e.to][e.rev].cap+=mi;
                f-=mi;
                s+=mi;              
            }
            if(f<=0)break;
        }
    }
    if(s>0)
        return s;
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
    vec[u].push_back(edge{v,w,vec[v].size()});
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