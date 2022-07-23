#include<bits/stdc++.h>
#define maxn 6005
using namespace std;
int r[maxn],n,root,mem[maxn][2];
vector<int> fa[maxn],son[maxn];
int sroot(int x){
    //cout<<x<<endl;
    if(fa[x].empty())return x;
    return sroot(fa[x][0]);
}
//这里dfs也可以不返回参数，上一级调用可以通过直接读取下一层数组
int dfs(int x,int is){
    if(mem[x][is]!=-1)return mem[x][is];//已经得到了就直接返回
    if(is==1){//x参加舞会
        int s=0;
        for(int i:son[x]){
            s+=dfs(i,0);//直接下属不参加
        }
        return mem[x][1]=r[x]+s;
    }
    else{//x不参加舞会
        int s=0;
        for(int i:son[x]){
            s+=max(dfs(i,1),dfs(i,0));//直接下属可参加可不参加
        }
        return mem[x][0]=s;
    }
}
int main(){
    memset(mem,-1,sizeof(mem));
    cin>>n;
    for(int i=1;i<=n;++i)scanf("%d",&r[i]);
    int x,y;
    for(int i=1;i<n;++i){
        scanf("%d%d",&x,&y);
        fa[x].push_back(y);
        son[y].push_back(x);
    }
    root=sroot(1);
    //cout<<root<<endl;
    cout<<max(dfs(root,1),dfs(root,0))<<endl;
    return 0;
}