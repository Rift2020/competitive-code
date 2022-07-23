#include<bits/stdc++.h>
#define maxn 20005
using namespace std;
int n,m;
vector<int> tu[maxn];
bool fl[maxn],vis[maxn];
int low[maxn],dfn[maxn],inde=0,res=0;
void tarjan(int u,int fa){
    vis[u]=true;
    low[u]=dfn[u]=++inde;
    int child=0;
    for(int v:tu[u]){
        if(!vis[v]){
            ++child;
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]&&fl[u]==false&&fa!=u){
                fl[u]=true;
                ++res;
            }
        }
        else if(v!=fa){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(u==fa&&child>=2&&fl[u]==false){
        fl[u]=true;
        ++res;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int x,y;
        cin>>x>>y;
        tu[x].push_back(y);
        tu[y].push_back(x);
    }
    for(int i=1;i<=n;++i){
        if(!vis[i])
            tarjan(i,i);
    }
    cout<<res<<endl;
    for(int i=1;i<=n;++i){
        if(fl[i])cout<<i<<" ";
    }
    return 0;
}