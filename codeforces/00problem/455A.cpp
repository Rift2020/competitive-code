#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)
		#define maxm 100005		using namespace std;using ll = long long;
int c[maxm];
ll dp[maxm];
ll n,ans;signed main(){	ios::sync_with_stdio(false);	cin>>n;
	rep(i,1,n){
		int x;
		cin>>x;
		c[x]++;
	}
	rep(i,1,maxm-1){
		dp[i]=(ll)c[i]*i;
		if(i!=1){
			dp[i]+=dp[i-2];
		}
		dp[i]=max(dp[i],dp[i-1]);
		ans=max(ans,dp[i]);
	}
	cout<<dp[maxm-1]<<endl;				return 0;}