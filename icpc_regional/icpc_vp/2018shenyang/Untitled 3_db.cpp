#include<bits/stdc++.h>
int now[7];
int lengthOfLIS(int nums[],int n) {
	int dp[n];
	for(auto &i:dp)i=1;
	for(int i=1;i<n;++i){
		for(int j=0;j<i;++j){
			if(nums[j]<nums[i])//继承条件
			dp[i]=max(dp[i],dp[j]+1);
		}
	}
	int ans=0;
	for(auto i:dp)ans=max(ans,i);//找出dp数组的最大值
	return ans;
}
int ans[8];
	int n=7;
		rep(j,0,i-1)a[j]=j+1;
		rep(j,0,i)ans[j]=0;
		do{
			rep(j,1,i){
				rep(k,0,i-1){
					now[k]=a[k];
				}
				sort(now,now+j);
				if(lengthOfLIS(now,i)>=i-1)++ans[j];
			}
		}while(next_permutation(a,a+i));
		rep(j,1,i){
			cout<<i<<" "<<j<<" "<<ans[j]<<endl;
		}
	}