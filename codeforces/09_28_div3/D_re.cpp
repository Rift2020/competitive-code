#include<bits/stdc++.h>
int k;
typedef pair<int,int> pr;
priority_queue<pr> pq,cl;
vector<pr> ans;
	while(t--){
		cin>>k;
		int in;
		pq=cl;
		rep(i,1,k){
			cin>>in;
			pq.push(pr{in,i});
		}
		ans.clear();
		while(pq.size()>1){
			int tp=pq.top().first;
			if(tp==0)break;
			int tnp=pq.top().second;
			pq.pop();
			int sp=pq.top().first;
			if(sp==0)break;
			int snp=pq.top().second;
			pq.pop();
			ans.push_back(pr{tnp,snp});
			--tp,--sp;
			pq.push(pr{tp,tnp});
			pq.push(pr{sp,snp});
		}
		cout<<ans.size()<<endl;
		for(auto i:ans){
			cout<<i.first<<" "<<i.second<<endl;
		}
	}