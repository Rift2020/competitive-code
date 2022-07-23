#include<bits/stdc++.h>
#define maxn 85
using namespace std;
int t,n,ans;
bool vis[maxn];//是否访问过
void dfs(int x,int i){//x当前位置，i当前步数
    if(vis[x]==true)return;//这步重复，走不了
    vis[x]=true;
    
    if(i==n){//走到了
        ++ans;
        vis[x]=false;
        return;
    }
    int l=x-i,r=x+i;
    if(l<1)l=n+l;
    if(r>n)r=r-n;
    dfs(l,i+1);
    dfs(r,i+1);
    vis[x]=false;//回溯
}
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        memset(vis,0,sizeof(vis));
        cin>>n;
        ans=0;
        dfs(1,1);
        cout<<ans<<endl;
    }
    
    
    return 0;
}