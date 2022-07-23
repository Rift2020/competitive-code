//bfs写成dfs了
#include<bits/stdc++.h>
using namespace std;
int a[400][400];
void bfs(int& n,int& m,int x,int y,int sp);
int main(){
    int n,m;
    cin>>n>>m;
    memset(a,-1,sizeof(a));
    int x,y;
    cin>>x>>y;
    --x;--y;
    bfs(n,m,x,y,0);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            printf("%-5d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
void bfs(int& n,int& m,int x,int y,int sp){
    if(x<0||x>=n||y<0||y>=m)return;
    if(*(*(a+x)+y)<=sp&&*(*(a+x)+y)!=-1)return;
    *(*(a+x)+y)=sp;
    ++sp;
    bfs(n,m,x+2,y+1,sp);
    bfs(n,m,x+2,y-1,sp);
    bfs(n,m,x-2,y+1,sp);
    bfs(n,m,x-2,y-1,sp);
    bfs(n,m,x+1,y+2,sp);
    bfs(n,m,x+1,y-2,sp);
    bfs(n,m,x-1,y+2,sp);
    bfs(n,m,x-1,y-2,sp);
}