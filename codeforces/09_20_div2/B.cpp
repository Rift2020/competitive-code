#include<bits/stdc++.h>
	while(t--){
		cin>>a[0]>>a[1]>>a[2]>>m;
		sort(a,a+3,greater<int>());
		int l=max(0,a[0]-a[1]-a[2]-1);
		int r=max(0,a[0]-1)+max(0,a[1]-1)+max(0,a[2]-1);
		if(m>=l&&m<=r)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}