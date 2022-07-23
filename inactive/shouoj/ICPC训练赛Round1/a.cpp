#include<bits/stdc++.h>
#define maxn 600005
#define maxm 500005
using namespace std;
int n,m,s,a,b,f[maxn][30],d[maxn];
vector<int> v[maxn];
void ydfs(int x,int r){
    d[x]=d[r]+1;
    f[x][0]=r;
    for(int i=1;;++i){
        if(f[f[x][i-1]][i-1]==0)break;
        f[x][i]=f[f[x][i-1]][i-1];
    }
    for(int i:v[x]){
        if(i!=r)
            ydfs(i,x);
    }
}
int lca(int x,int y){

    if(d[x]>d[y])swap(x,y);
    while(d[x]<d[y]){
        int cd=d[y]-d[x];
        int gd=log(cd)/log(2);
        y=f[y][gd];
    }
    if(x==y)return x;
    for(int i=29;i>=0;--i){
        if(f[x][i]==0||f[x][i]==f[y][i])continue;
        x=f[x][i];
        y=f[y][i];
    }
    return f[x][0];
}
int main(){
    //freopen("1.in","r",stdin);
    cin>>n>>m>>s;
    memset(f,0,sizeof(f));
    for(int i=1;i<n;++i){
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    d[s]=1;
    ydfs(s,0);
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        printf("%d\n",d[a]+d[b]-2*d[lca(a,b)]);
    }
    return 0;
}