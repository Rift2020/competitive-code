#include<bits/stdc++.h>
	#define  endl '\n'
		#define maxn 5005
int dp[maxn][maxn];//s[l,r]有多少字串是回文串
string in;
int n,q;
	cin.tie(0);
	cout.tie(0);
	n=in.size();
	for(int i=0;i<n;++i){
		for(int l=i,r=i;l>=0&&r<n&&in[l]==in[r];--l,++r){
			f[l][r]=1;
		}
		for(int l=i,r=i+1;l>=0&&r<n&&in[l]==in[r];--l,++r){
			f[l][r]=1;
		}
	}
	for(int i=0;i<n;++i)dp[i][i]=1;
		for(int i=0,j=i+len-1;j<n;++i,++j){
			dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]+f[i][j];
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<dp[l-1][r-1]<<endl;
	}