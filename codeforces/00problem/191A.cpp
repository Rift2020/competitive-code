#include<bits/stdc++.h>
		#define maxn 500005
int n;
string in[maxn];
	rep(i,1,n)cin>>in[i];
		int f=in[i].front()-'a';
		int b=in[i].back()-'a';
		for(int j=0;j<26;++j){
			if(dp[j][f])
				dp[j][b]=max(dp[j][b],dp[j][f]+(int)in[i].length());
		}
		dp[f][b]=max(dp[f][b],(int)in[i].length());

	}
	int ans=0;
	cout<<ans<<endl;