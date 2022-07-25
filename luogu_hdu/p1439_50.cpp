#include <iostream>
#define maxn 1005
using namespace std;
int a[maxn],b[maxn];
int dp[maxn][maxn];
int n;
int main() {
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)cin>>b[i];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(a[i]==b[j]){
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	cout<<dp[n][n]<<endl;
	return 0;
}