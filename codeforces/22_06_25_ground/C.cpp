#include<bits/stdc++.h>
#define int ll
		using namespace std;
typedef pair<int,int> pr;//int,amount
vector<pr> v,v2;
int b[maxn];
pr ho(int x){
	int re=1;
	while(x>1){
		if(x%m!=0)break;
		x/=m;
		re=(re*m);
	}
	return pr{x,re};
}
	cin.tie(nullptr);
	while(t--){
		v.clear();
		v2.clear();
		cin>>n>>m;
		rep(i,1,n){
			int in;
			cin>>in;
			pr now=ho(in);
			if(v.empty()||v.back().first!=now.first){
				v.push_back(now);
			}
			else{
				v.back().second+=now.second;
			}
		}
		cin>>k;
		rep(i,1,k){
			int in;
			cin>>in;
			pr now=ho(in);
			if(v2.empty()||v2.back().first!=now.first){
				v2.push_back(now);
			}
			else{
				v2.back().second+=now.second;
			}
		}
		if(v==v2)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}