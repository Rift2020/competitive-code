#include<bits/stdc++.h>
		#define maxn 100005
int t;
int n;
int m;
	while(t--){
		cin>>n;
		memset(use,false,sizeof(use));
		int a,b,c;
		cin>>m;
		rep(o,1,m){
			cin>>a>>b>>c;
			use[b]=true;
		}
		int s;
		rep(i,1,n){
			if(use[i]==false){
				s=i;
			}
		}
		rep(i,1,n){
			if(i==s)continue;
			cout<<i<<" "<<s<<endl;
		}
	}