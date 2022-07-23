#include<bits/stdc++.h>
using namespace std;
#define maxn 35
int mp[maxn][maxn],n;
bool f[maxn][maxn];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
void fdfs(int x,int y){
    if(mp[x][y]==1||f[x][y]==true)return;
    f[x][y]=true;
    for(int i=0;i<4;++i){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>=1&&ny>=1&&nx<=n&&ny<=n){
            fdfs(nx,ny);
        }
    }
}
void pr(){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(mp[i][j]==1)cout<<1;
            else if(f[i][j]==false){
                cout<<2;
            }
            else cout<<0;
            cout<<" ";
        }
        cout<<endl;
    }
        
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cin>>mp[i][j];
    for(int j=1;j<=n;++j){
        fdfs(1,j);
        fdfs(n,j);
        fdfs(j,1);
        fdfs(j,n);
    }
    pr();
    
    
    return 0;
}