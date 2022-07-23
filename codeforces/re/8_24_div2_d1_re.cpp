#include <iostream>
#define maxn 4000005
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
		for(int l=2,r;l<=i;l=r+1){
            r=i/(i/l);
            dp[i]+=(r-l+1)*dp[i/l];
            dp[i]%=m;
        }
		ss[i]=ss[i-1]+dp[i];
		ss[i]%=m;
	}
	cout<<dp[n]<<endl;
	return 0;
}