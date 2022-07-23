#include<bits/stdc++.h>
using namespace std;
typedef struct {
    int x;
    int y;
} xy;
queue<xy>q;
int a[405][405];
int dx[8]={2,2,1,1,-1,-1,-2,-2};
int dy[8]={1,-1,2,-2,2,-2,1,-1};
int main(){
    memset(a,-1,sizeof(a));
    xy p,f;
    int n,m,x,y,nx,ny,s;
    cin>>n>>m>>x>>y;
    a[x][y]=0;
    p.x=x;
    p.y=y;
    q.push(p);
    while (!q.empty())
    {
        f=q.front();
        q.pop();
        x=f.x;
        y=f.y;
        s=a[x][y];
        for(int i=0;i<8;++i){
                nx=x+dx[i];
                ny=y+dy[i];
                if(nx>n||ny>m||nx<=0||ny<=0||a[nx][ny]!=-1)continue;
                a[nx][ny]=s+1;
                p.x=nx;
                p.y=ny;
                q.push(p);
            }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            printf("%-5d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}