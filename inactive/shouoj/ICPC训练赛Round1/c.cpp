#include<bits/stdc++.h>
#define maxn 55
using namespace std;
int f[maxn][maxn][maxn];
int n,m,k;
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            for(int l=0;l<=k;++l)
                f[i][j][l]=1e9;
    for(int i=1;i<=n;++i)
        for(int l=0;l<=k;++l)
            f[i][i][l]=0;
    for(int i=0;i<m;++i){
        int x,y,z;
        cin>>x>>y>>z;
        f[x][y][0]=f[y][x][0]=z;
        f[x][y][1]=f[y][x][1]=z/2;
        
    }
    for(int l=1;l<=n;++l){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                for(int m=0;m<=k;++m){
                    for(int n=0;n<=m;++n){
                        //cout<<i<<" "<<j<<" "<<n<<" "<<m<<endl;
                        f[i][j][m]=min(f[i][j][m],f[i][l][n]+f[l][j][m-n]);
                    }
                }
            }
        }
    }
    int ans=f[1][n][0];
    for(int i=0;i<=k;++i){
        ans=min(ans,f[1][n][i]);
    }
    cout<<ans<<endl;
    return 0;
}