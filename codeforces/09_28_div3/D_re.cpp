#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)		using namespace std;using ll = long long int;int t;
int k;
typedef pair<int,int> pr;
priority_queue<pr> pq,cl;
vector<pr> ans;int main(){	ios::sync_with_stdio(false);	cin>>t;
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
	}				return 0;}