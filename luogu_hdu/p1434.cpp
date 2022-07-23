#include<bits/stdc++.h>
#define maxn 105
using namespace std;
int r,c,a[maxn][maxn],mem[maxn][maxn],ans=0;
int mx[]={1,-1,0,0};
int my[]={0,0,1,-1};
int dfs(int x,int y){
    if(mem[x][y])return mem[x][y];
    mem[x][y]=1;
    int nx,ny;
    for(int i=0;i<4;++i){
        nx=x+mx[i],ny=y+my[i];
        if(nx>=1&&nx<=r&&ny>=1&&ny<=c&&a[nx][ny]<a[x][y]){
            mem[x][y]=max(mem[x][y],1+dfs(nx,ny));
        }
    }
    if(mem[x][y]>ans)ans=mem[x][y];
    return mem[x][y];
}
int main(){
    cin>>r>>c;
    for(int i=1;i<=r;++i)
        for(int j=1;j<=c;++j)scanf("%d",&a[i][j]);    
    for(int i=1;i<=r;++i)
        for(int j=1;j<=c;++j)
            dfs(i,j);
    cout<<ans<<endl;
    return 0;
}