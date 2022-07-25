#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)
		#define maxn 500005		using namespace std;using ll = long long;int dp[30][30];
int n;
string in[maxn];signed main(){	ios::sync_with_stdio(false);	cin>>n;
	rep(i,1,n)cin>>in[i];	rep(i,1,n){
		int f=in[i].front()-'a';
		int b=in[i].back()-'a';
		for(int j=0;j<26;++j){
			if(dp[j][f])
				dp[j][b]=max(dp[j][b],dp[j][f]+(int)in[i].length());
		}
		dp[f][b]=max(dp[f][b],(int)in[i].length());

	}
	int ans=0;	for(int i=0;i<26;++i)ans=max(ans,dp[i][i]);
	cout<<ans<<endl;		return 0;}