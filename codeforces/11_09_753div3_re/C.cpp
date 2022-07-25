#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define int long longusing namespace std;int t,n,add,ans;
priority_queue<int,vector<int>,greater<int> > pq,cl;signed main(){	ios::sync_with_stdio(false);	cin>>t;
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
	}				return 0;}