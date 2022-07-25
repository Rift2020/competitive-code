#include<bits/stdc++.h>#define rep(i, a, b) for (int i = (a); i <= (b); ++i)	#define per(i, a, b) for (int i = (a); i >= (b); --i)		using namespace std;using ll = long long;int t,n,k;
typedef pair<int,int> pr;
vector<pr> v;signed main(){	ios::sync_with_stdio(false);
	cin.tie(nullptr);	cin>>t;
	while(t--){
		v.clear();
		cin>>n>>k;
		pr in;
		v.resize(n);
		rep(i,0,n-1){
			cin>>v[i].first;
		}
		rep(i,0,n-1){
			cin>>v[i].second;
		}
		sort(v.begin(),v.end());
		for(auto i:v){
			if(k>=i.first)k+=i.second;
			else break;
		}
		cout<<k<<endl;
	}				return 0;}