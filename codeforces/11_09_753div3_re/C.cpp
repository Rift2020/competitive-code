#include<bits/stdc++.h>
#define int long long
priority_queue<int,vector<int>,greater<int> > pq,cl;
	while(t--){
		add=0;
		ans=-1e9;
		pq=cl;
		cin>>n;
		rep(i,1,n){
			int in;
			cin>>in;
			pq.push(in);
		}
		while(pq.size()){
			int now=pq.top();
			now+=add;
			ans=max(ans,now);
			add-=now;
			pq.pop();
		}
		cout<<ans<<endl;
	}