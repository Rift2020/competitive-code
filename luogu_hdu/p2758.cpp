#include<bits/stdc++.h>
#define maxn 2005
using namespace std;
string a,b;
int dp[maxn][maxn];
int main(){
    ios::sync_with_stdio(false);
    cin>>a>>b;
    for(int j=0;j<=b.size();++j)dp[0][j]=j;
    for(int i=0;i<=a.size();++i)dp[i][0]=i;
    for(int i=0;i<a.size();++i){
        for(int j=0;j<b.size();++j){
            int di=i+1,dj=j+1;
            if(a[i]==b[j]){
                dp[di][dj]=dp[di-1][dj-1];
            }
            else {
                int ne=min(dp[di-1][dj]+1,dp[di][dj-1]+1);
                dp[di][dj]=min(ne,dp[di-1][dj-1]+1);
            }
        }
    }
    cout<<dp[a.size()][b.size()]<<endl;
    return 0;
}