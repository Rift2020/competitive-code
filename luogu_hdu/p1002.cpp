#include<bits/stdc++.h>
#define maxn 25
#define int long long
using namespace std;
int bx,by,mx,my;
int dp[maxn][maxn];
bool ma[maxn][maxn];
int dx[8]={-2,-2,-1,-1,1,1,2,2};
int dy[8]={1,-1,2,-2,2,-2,1,-1};
signed main(){
    ios::sync_with_stdio(false);
    cin>>bx>>by>>mx>>my;
    bx++,by++,mx++,my++;
    ma[mx][my]=true;
    for(int i=0;i<8;++i){
        int nx=mx+dx[i];
        int ny=my+dy[i];
        ma[nx][ny]=true;
    }
    if(ma[1][1]==false)
        dp[1][1]=1;
    for(int i=1;i<=bx;++i){
        for(int j=1;j<=by;++j){
            if(ma[i][j])continue;
            if(i==1&&j==1)continue;
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    cout<<dp[bx][by]<<endl;
    
    
    return 0;
}