#include<bits/stdc++.h>
		#define maxn 1000005

int has[maxn];
int sum[maxn];
int n,m;
	rep(i,1,n){
		is[i].push_back(0);
		rep(j,1,m){
			char c;
			cin>>c;
			if(c=='.'){
				is[i].push_back(false);
			}
			else{
				is[i].push_back(true);
			} 
		}
	}
	rep(j,1,m-1){
		rep(i,2,n){
			if(is[i][j]&&is[i-1][j+1]){
				has[j+1]=1;
				break;
			}
		}
	}
	rep(j,1,m)
		sum[j]=sum[j-1]+has[j];
	int q;
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		if(sum[r]-sum[l]==0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}