#include<bits/stdc++.h>
	while(t--){
		cin>>n>>m;
		ll s=0;
		rep(i,1,n){
			s+=i*i;
		}
		s*=m;
		cout<<s<<endl;
	}