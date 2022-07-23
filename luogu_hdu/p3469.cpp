#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
vector<ll> v[maxn],cld[maxn];
int n,m;
bool vis[maxn],fl[maxn];
int dfn[maxn],low[maxn],cnt;
int acs[maxn];//all child size
void tarjan(int u,int fa){
    vis[u]=true;
    dfn[u]=low[u]=++cnt;
    acs[u]=1;
    for(auto i:v[u]){
        if(!vis[i]){
            tarjan(i,u);
            acs[u]+=acs[i];
            low[u]=min(low[u],low[i]);
            if(fa==u){
                cld[u].push_back(acs[i]);
            }
            if(fa!=u&&low[i]>=dfn[u]){
                fl[u]=true;
                cld[u].push_back(acs[i]);
            }
        }
        else if(i!=fa){
            low[u]=min(low[u],low[i]);
        }
    }
    if(fa==u&&cld[u].size()>=2){
        fl[u]=true;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    tarjan(1,1);
    for(int i=1;i<=n;++i){
        ll ans=2*(n-1);
        if(fl[i]){
            ll s=0;
            for(int j:cld[i]){
                s+=j;
            }
            if(n-s-1>0)
                cld[i].push_back(n-s-1);
            for(auto j=cld[i].begin();j!=cld[i].end();++j){
                for(auto k=j+1;k!=cld[i].end();++k)
                    ans+=(*j)*(*k)*2;
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}