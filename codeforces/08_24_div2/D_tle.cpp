#include <iostream>
#define maxn 200005
#define ll long long
using namespace std;
int n,m;
ll dp[maxn],ss[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin>>n>>m;
	dp[1]=1,ss[1]=1;
	for(int i=2;i<=n;++i){
		dp[i]=ss[i-1];
		for(int j=2;j<=i;++j){
			dp[i]+=dp[i/j];
			dp[i]%=m;
			if(i/j==1){
				dp[i]+=(i-j);
				dp[i]%=m;
				break;
			}
		}
		ss[i]=ss[i-1]+dp[i];
		ss[i]%=m;
	}
	cout<<dp[n]<<endl;
	return 0;
}