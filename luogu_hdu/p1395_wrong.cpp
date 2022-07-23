#include<bits/stdc++.h>
#define maxn 50005
using namespace std;
int n;
bool vis[maxn];
vector<int> v[maxn];
int son[maxn],mson[maxn],zson[maxn],mp,mpv=INT_MAX;
void dfs(int x,int fa){
    vis[x]=true;
    son[x]=1;
    zson[x]=1;
    for(int i:v[x]){
        if(i==fa||vis[i])continue;
        dfs(i,x);
        son[x]=zson[i]+1;
        zson[x]+=son[i];
        mson[x]=max(mson[x],son[x]);
    }
}
int dfs2(int x){
    vis[x]=1;
    int s=1;
    zson[x]=1;
    for(int i:v[x]){
        if(vis[i])continue;
        s+=dfs2(i);
        if(x==mp)continue;
        zson[x]+=zson[i];
    }
    s+=zson[x]-1;
    //cout<<':'<<x<<" "<<s<<endl;
    //cout<<x<<" "<<s<<endl;
    return s;
}
int main(){
    memset(vis,0,sizeof(vis));
    memset(mson,0,sizeof(mson));
    memset(zson,0,sizeof(zson));
    cin>>n;
    int a,b;
    for(int i=0;i<n-1;++i){
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,-1);
    //for(int i=1;i<=n;++i)cout<<son[i]<<" ";
    //cout<<endl;
    for(int i=1;i<=n;++i){
        //cout<<mson[i]<<" "<<endl;
        if(max(mson[i]-1,n-mson[i])<mpv){
            mp=i;
            mpv=max(mson[i]-1,n-mson[i]);
            //cout<<mpv<<endl;
        }
    }

    memset(vis,0,sizeof(vis));
    //cout<<dfs2(mp)<<endl;
    cout<<mp<<" "<<dfs2(mp)-1<<endl;
    return 0;
}