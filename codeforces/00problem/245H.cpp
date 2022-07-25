#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)
	#define  endl '\n'
		#define maxn 5005		using namespace std;using ll = long long;int f[maxn][maxn];//s[l,r]是否是回文串
int dp[maxn][maxn];//s[l,r]有多少字串是回文串
string in;
int n,q;signed main(){	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);	cin>>in;
	n=in.size();
	for(int i=0;i<n;++i){
		for(int l=i,r=i;l>=0&&r<n&&in[l]==in[r];--l,++r){
			f[l][r]=1;
		}
		for(int l=i,r=i+1;l>=0&&r<n&&in[l]==in[r];--l,++r){
			f[l][r]=1;
		}
	}
	for(int i=0;i<n;++i)dp[i][i]=1;	for(int len=2;len<=n;++len){
		for(int i=0,j=i+len-1;j<n;++i,++j){
			dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]+f[i][j];
		}
	}	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<dp[l-1][r-1]<<endl;
	}	return 0;}