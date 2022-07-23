#include<bits/stdc++.h>
#define maxn 20005
using namespace std;
vector<int> tu[maxn];
int n,m,res=0;
bool vis[maxn];
int dfn[maxn],low[maxn],inde=0;
bool fl[maxn];
void tarjan(int u,int fa){
    vis[u]=true;
    low[u]=dfn[u]= ++inde;
    int child=0;
    for(auto v:tu[u]){
        if(!vis[v]){
            ++child;
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(fa!=u&&low[v]>=dfn[u]&&fl[u]!=true){
                fl[u]=true;
                //cout<<"1:"<<u<<endl;
                ++res;
            } 
        }
        else if(v!=fa){
                low[u]=min(low[u],dfn[v]);
        }
    }
    if(fa==u&&child>=2&&fl[u]==false){
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
        if(vis[i]==false){
            inde=0;
            tarjan(i,i);
        }
    }
    cout<<res<<endl;
    for(int i=1;i<=n;++i){
        if(fl[i])cout<<i<<" ";
    }
    return 0;
}