#include<bits/stdc++.h>
typedef pair<int,int> pr;
vector<pr> v;
	cin.tie(nullptr);
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
	}